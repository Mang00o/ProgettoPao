#include "carbsource.h"
#include <QTableWidget>

CarbSource::CarbSource(QString n, unsigned int c, unsigned int p, unsigned int f, bool gF) :
    Food(n,c,p,f), isGlutenFree(gF){}

CarbSource::~CarbSource(){}

TableModel* CarbSource::createTableModel() const{
    QStringList carbHorHeader = { "Carboidrati(gr)", "Proteine(gr)", "Grassi(gr)", "GlutenFree"};
    QStringList carbVerHeader = { "Riso", "Pasta", "Pane", "Patate", "Mais", "Quinoa", "Avena", "Farro"};
    QList<QList<QString>> carbValues = {
        {"80", "6", "1", "NO"},
        {"25", "4", "1", "NO"},
        {"49", "9", "3", "NO"},
        {"17", "2", "0", "SI"},
        {"75", "9", "4", "SI"},
        {"64", "14", "6", "SI"},
        {"72", "8", "8", "SI"},
        {"68", "15", "3", "NO"}
    };

    TableModel* carbTableModel = new TableModel(carbValues, carbHorHeader, carbVerHeader);
    return carbTableModel;
}

ListModel* CarbSource::createListModel() const{
    QStringList carbInfo;
    carbInfo.append("- Informazioni su Carboidrati");
    carbInfo.append("I carboidrati sono una delle tre principali classi di nutrienti, insieme alle proteine ​​e ai grassi.");
    carbInfo.append("I carboidrati si trovano in una varietà di alimenti, tra cui: Cereali, Frutta, Verdure.");
    carbInfo.append("La quantità di carboidrati raccomandata varia in base all'età, al sesso, all'attività fisica e ad altri fattori individuali.");
    carbInfo.append("Le linee guida suggeriscono che circa il 45-65% delle calorie totali dovrebbe provenire dai carboidrati.");
    carbInfo.append("È importante scegliere fonti di carboidrati che siano nutrienti e includere una varietà di carboidrati nella dieta\n per ottenere una gamma completa di nutrienti.");

    ListModel *carbListModel = new ListModel(carbInfo);
    return carbListModel;
}

QString CarbSource::getAttributeLabel() const{
    return QString("senza glutine");
}

bool CarbSource::getGlutenFreeValue() const{
    return isGlutenFree;
}

void CarbSource::setGlutenFreeValue(bool value){
    isGlutenFree = value;
}
