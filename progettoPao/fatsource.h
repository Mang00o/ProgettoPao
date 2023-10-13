#ifndef FATSOURCE_H
#define FATSOURCE_H

#include "food.h"

class FatSource : public Food{
private:
    unsigned int saturatedFat;
public:
    FatSource(QString n="fat", unsigned int c=0, unsigned int p=0, unsigned int f=0, unsigned int sF = 0);
    ~FatSource();
    TableModel* createTableModel() const;
    ListModel* createListModel() const;
    QString getAttributeLabel() const;
    int getSatFatValue() const;
    void setSatFatValue(unsigned int value);
};


#endif // FATSOURCE_H
