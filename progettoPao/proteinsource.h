#ifndef PROTEINSOURCE_H
#define PROTEINSOURCE_H

#include "food.h"

class ProteinSource : public Food{
private:
    bool isVegetarian;
    bool isVegan;
public:
    ProteinSource(QString n="protein", unsigned int c=0, unsigned int p=0, unsigned int f=0, bool veg = false, bool vegan = false);
    ~ProteinSource();
    TableModel* createTableModel() const;
    ListModel* createListModel() const;
    QString getAttributeLabel() const;
    bool getVegetarianValue() const;
    bool getVeganValue() const;
    void setVegetarianValue(bool value);
    void setVeganValue(bool value);
};

#endif // PROTEINSOURCE_H
