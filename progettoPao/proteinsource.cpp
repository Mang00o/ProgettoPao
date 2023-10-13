#include "proteinsource.h"
#include <QTableWidget>

ProteinSource::ProteinSource(QString n, unsigned int c, unsigned int p, unsigned int f, bool veg, bool vegan)
    : Food(n,c,p,f), isVegetarian(veg), isVegan(vegan){}

ProteinSource::~ProteinSource(){}

TableModel* ProteinSource::createTableModel() const{
    QStringList proteinHorHeader = {"Carboidrati(gr)", "Proteine(gr)", "Grassi(gr)", "Vegetariano", "Vegano"};
    QStringList proteinVerHeader = {"Pollo", "Manzo", "Tacchino", "Merluzzo", "Salmone", "Tonno", "Uova", "Tofu", "Lenticchie"};
    QList<QList<QString>> proteinValues = {
        { "0", "25", "14", "NO", "NO"},
        { "0", "26", "17", "NO", "NO"},
        { "0", "29", "7", "NO", "NO"},
        { "0", "18", "1", "NO", "NO"},
        { "0", "21", "15", "NO", "NO"},
        { "0", "22", "8", "NO", "NO"},
        { "3", "13", "9", "NO", "NO"},
        { "1", "16", "9", "SI", "SI"},
        { "20", "9", "1", "SI", "SI"}
    };

    TableModel* proteinTableModel = new TableModel(proteinValues, proteinHorHeader, proteinVerHeader);
    return proteinTableModel;
}

ListModel* ProteinSource::createListModel() const{
    QStringList proteinInfo;
    proteinInfo.append("- Informazioni su Proteine");
    proteinInfo.append("Le proteine ​​sono macromolecole biologiche essenziali per la vita.");
    proteinInfo.append("Le proteine ​​si trovano in una varietà di alimenti, tra cui carne, pesce, uova, latticini, legumi, noci, semi e cereali integrali.");
    proteinInfo.append("L'apporto proteico raccomandato varia da persona a persona in base all'età, al sesso, all'attività fisica e ad altre variabili.");
    proteinInfo.append("In generale, le linee guida dietetiche suggeriscono di ottenere circa il 10-35% delle calorie giornaliere da fonti proteiche.");

    ListModel *proteinListModel = new ListModel(proteinInfo);
    return proteinListModel;
}

QString ProteinSource::getAttributeLabel() const{
    return QString("Vegetariano");
}

bool ProteinSource::getVegetarianValue() const{
    return isVegetarian;
}

bool ProteinSource::getVeganValue() const{
    return isVegan;
}

void ProteinSource::setVegetarianValue(bool value){
    isVegetarian = value;
}

void ProteinSource::setVeganValue(bool value){
    isVegan = value;
}
