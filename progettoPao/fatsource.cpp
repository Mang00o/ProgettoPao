#include "fatsource.h"
#include <QTableWidget>

FatSource::FatSource(QString n, unsigned int c, unsigned int p, unsigned int f, unsigned int sF)
    : Food(n,c,p,f), saturatedFat(sF){}

FatSource::~FatSource(){};

TableModel* FatSource::createTableModel() const{
    QStringList fatHorHeader = { "Carboidrati(gr)", "Proteine(gr)", "Grassi(gr)", "GrassiSaturi(gr)"};
    QStringList fatVerHeader = { "Avocado", "Noci", "Olio di olive", "Burro di arachidi", "Mandorle", "Semi di lino"};
    QList<QList<QString>> fatValues = {
        { "2", "5", "23", "1"},
        { "14", "11", "58", "2"},
        { "0", "0", "100", "0"},
        { "23", "23", "45", "4"},
        { "22", "12", "49", "1"},
        { "29", "18", "42", "1"}
    };

    TableModel* fatTableModel = new TableModel(fatValues, fatHorHeader, fatVerHeader);
    return fatTableModel;
}

ListModel* FatSource::createListModel() const{
    QStringList fatInfo;
    fatInfo.append("- Informazioni su Grassi");
    fatInfo.append("I grassi, noti anche come lipidi, sono una delle tre principali classi di nutrienti, insieme alle proteine ​​e ai carboidrati.");
    fatInfo.append("I grassi si trovano in una varietà di alimenti, tra cui: Carne, Pesce, Latticini, Oli vegetali, Frutta secca");
    fatInfo.append("La quantità di grassi raccomandata varia in base all'età, al sesso, all'attività fisica e ad altri fattori individuali.");
    fatInfo.append("Le linee guida suggeriscono che circa il 20-35% delle calorie totali dovrebbe provenire dai grassi.");
    fatInfo.append("È importante distinguere tra grassi saturi, insaturi e trans. I grassi insaturi, come quelli presenti negli oli vegetali e nelle noci,\n \
                    sono generalmente considerati più salutari e dovrebbero costituire una parte significativa dell'apporto di grassi");
    fatInfo.append("La scelta di fonti sane di grassi e il controllo dell'apporto totale di grassi nella dieta sono importanti per una dieta equilibrata.");

    ListModel *fatListModel = new ListModel(fatInfo);
    return fatListModel;
}

QString FatSource::getAttributeLabel() const{
    return QString("Quantitativo\nGrassi saturi(gr)");
}

int FatSource::getSatFatValue() const{
    return saturatedFat;
}

void FatSource::setSatFatValue(unsigned int value){
    saturatedFat = value;
}
