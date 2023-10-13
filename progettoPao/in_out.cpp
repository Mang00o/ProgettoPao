#include "in_out.h"
#include "carbsource.h"
#include "fatsource.h"
#include "proteinsource.h"
#include <QErrorMessage>
#include <QtXml>
#include <QInputDialog>
#include <QFileDialog>

QString In_Out::getType(Food* f){
    QString type = "food";
    if(dynamic_cast<CarbSource*>(f))
        type = "carb";
    else if(dynamic_cast<ProteinSource*>(f))
        type = "protein";
    else if(dynamic_cast<FatSource*>(f))
        type = "fat";
    return type;
}

void In_Out::write(Container* foodContainer){
    QString nomeFile = QInputDialog::getText(NULL, "Salvataggio File","Inserire nome file salvataggio:", QLineEdit::Normal,"myFile");

    QFile file("../esempi/"+nomeFile+".xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QErrorMessage *error = new QErrorMessage;
        error->showMessage("Fallito ad aprire file di scritture");
    }

    QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);

        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("menu");

        for (Container::Iterator i = foodContainer->begin(); i!=foodContainer->end(); ++i){
            xmlWriter.writeStartElement("food");
            xmlWriter.writeTextElement("type", getType(i.getFood()));
            xmlWriter.writeTextElement("name", i.getName());
            xmlWriter.writeTextElement("carb", QString::number(i.getCarb()));
            xmlWriter.writeTextElement("protein", QString::number(i.getProtein()));
            xmlWriter.writeTextElement("fat", QString::number(i.getFat()));
            if(dynamic_cast<CarbSource*>(i.getFood())){
                if(dynamic_cast<CarbSource*>(i.getFood())->getGlutenFreeValue())
                    xmlWriter.writeTextElement("glutenFree", "true");
                else
                    xmlWriter.writeTextElement("glutenFree", "false");
            }
            else if(dynamic_cast<ProteinSource*>(i.getFood())){
                if(dynamic_cast<ProteinSource*>(i.getFood())->getVegetarianValue())
                    xmlWriter.writeTextElement("vegetarian", "true");
                else
                    xmlWriter.writeTextElement("vegetarian", "false");
                if(dynamic_cast<ProteinSource*>(i.getFood())->getVeganValue())
                    xmlWriter.writeTextElement("vegan", "true");
                else
                    xmlWriter.writeTextElement("vegan", "false");
            }
            else if(dynamic_cast<FatSource*>(i.getFood())){
                xmlWriter.writeTextElement("grassi_saturi",
                QString::number(dynamic_cast<FatSource*>(i.getFood())->getSatFatValue()));
            }
            xmlWriter.writeEndElement();
        }
        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();

        file.close();
}

void In_Out::read(Container *foodContainer){
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Seleziona un file", "../esempi", "XML files (*.xml)");

    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QErrorMessage *error = new QErrorMessage;
        error->showMessage("Fallito ad aprire file di lettura,\n "
                               "File non esistente");
    }

    QXmlStreamReader xml(&file);
        if(!xml.atEnd() && !xml.hasError()){
            bool error = false;
            xml.readNext();
            if (xml.tokenType() == QXmlStreamReader::StartDocument && !error) {
                xml.readNext();
                if (xml.name().toString() == "menu"){
                    xml.readNext(); xml.readNext();
                    while(xml.tokenType() == QXmlStreamReader::StartElement && !error){
                        if (xml.name().toString() == "food"){
                            Food* f;
                            xml.readNext(); xml.readNext(); xml.readNext();
                            if(xml.text().toString() == "carb"){
                                f = new CarbSource();
                            }else if(xml.text().toString() == "protein"){
                                f = new ProteinSource();
                            }else if(xml.text().toString() == "fat"){
                                f = new FatSource();
                            }else{
                                QErrorMessage *err = new QErrorMessage;
                                err->showMessage("ERRORE NOMINAZIONE tipo");
                                error = true;
                                xml.hasError();
                            }
                            if(!error){
                                xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext();
                                f->setName(xml.text().toString());
                                xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext();
                                f->setCarb(xml.text().toInt());
                                xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext();
                                f->setProtein(xml.text().toInt());
                                xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext();
                                f->setFat(xml.text().toInt());
                                if(dynamic_cast<CarbSource*>(f)){
                                    xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext();
                                    if(xml.text().toString()=="true")
                                        dynamic_cast<CarbSource*>(f)->setGlutenFreeValue(true);
                                    else
                                        dynamic_cast<CarbSource*>(f)->setGlutenFreeValue(false);
                                }
                                else if(dynamic_cast<ProteinSource*>(f)){
                                    xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext();
                                    if(xml.text().toString()=="true")
                                        dynamic_cast<ProteinSource*>(f)->setVegetarianValue(true);
                                    else
                                        dynamic_cast<ProteinSource*>(f)->setVegetarianValue(false);
                                    xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext();
                                    if(xml.text().toString()=="true")
                                        dynamic_cast<ProteinSource*>(f)->setVeganValue(true);
                                    else
                                        dynamic_cast<ProteinSource*>(f)->setVeganValue(false);
                                }
                                else if(dynamic_cast<FatSource*>(f)){
                                    xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext();
                                    dynamic_cast<FatSource*>(f)->setSatFatValue(xml.text().toInt());
                                }
                                foodContainer->insert(f);
                            }
                        }
                        xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext(); xml.readNext();
                    }
                }else{
                    QErrorMessage *err = new QErrorMessage;
                    err->showMessage("ERRORE NOMINAZIONE primo tag");
                }
            }
        }else if (xml.hasError()) {
            QErrorMessage *err = new QErrorMessage;
            err->showMessage("ERRORE durante la LETTURA del file XML: " + xml.errorString());
        }
    file.close();
}


