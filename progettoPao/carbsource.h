#ifndef CARBSOURCE_H
#define CARBSOURCE_H

#include "food.h"


class CarbSource : public Food{
private:
    bool isGlutenFree;
public:
    CarbSource(QString n="carb", unsigned int c=0, unsigned int p=0, unsigned int f=0, bool gF = false);
    ~CarbSource();
    TableModel* createTableModel() const;
    ListModel* createListModel() const;
    QString getAttributeLabel() const;
    bool getGlutenFreeValue() const;
    void setGlutenFreeValue(bool value);
};

#endif // CARBSOURCE_H
