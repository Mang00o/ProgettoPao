#include "littlewindow.h"
#include <QGroupBox>
#include <QLabel>

LittleWindow::LittleWindow(Container *c, QWidget *parent):
QWidget(parent), foodContainer(c){
    layout = new QVBoxLayout();
        maxValueBox = new QComboBox();
            maxValueBox->addItem("Ricerca valore massimo di:");
            maxValueBox->addItem("Kcal");
            maxValueBox->addItem("Carboidrati");
            maxValueBox->addItem("Proteine");
            maxValueBox->addItem("Grassi");
            connect(maxValueBox, SIGNAL(activated(int)), this, SLOT(showMax(int)));
        layout->addWidget(maxValueBox);
    setLayout(layout);
}

LittleWindow::~LittleWindow(){
    delete foodContainer;
    delete layout;
    delete maxValueBox;
}

void LittleWindow::showMax(int value) const{
    QString name = foodContainer->searchMax(value);
    QString text;
    if(name == ""){
        text.append("Nessun Massimo");
    }else{
        switch(value){
            case 1:
                text.append("Alimento con piu' Kcal: " + name);
                break;
            case 2:
                text.append("Alimento con piu' Carboidrati: " + name);
                break;
            case 3:
                text.append("Alimento con piu' Proteine: " + name);
                break;
            case 4:
                text.append("Alimento con piu' Grassi: " + name);
                break;
            default:
                break;
        }
    }
    QLabel* label = new QLabel(text);
    layout->addWidget(label);

    layout->removeWidget(maxValueBox);
    delete maxValueBox;
}
