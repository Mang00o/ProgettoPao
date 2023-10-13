#ifndef FOOD_H
#define FOOD_H

#include <QString>
#include <QLineEdit>
#include <QSpinBox>
#include "tablemodel.h"
#include "listmodel.h"

class Food{
    private:
        QString name;
        unsigned int carb, protein, fat;
        unsigned int kcal;
        void updateKcal();
    public:
        Food(QString n="food", unsigned int c=0, unsigned int p=0, unsigned int f=0);
        Food(const Food& f);
        virtual ~Food();
        virtual TableModel* createTableModel() const = 0;
        virtual ListModel* createListModel() const = 0;
        virtual QString getAttributeLabel() const = 0;
        QString getName() const;
        unsigned int getCarb() const;
        unsigned int getProtein() const;
        unsigned int getFat() const;
        unsigned int getKcal() const;       
        void setName(QString n);
        void setCarb(unsigned int c);
        void setProtein(unsigned int p);
        void setFat(unsigned int f);
};

#endif // FOOD_H
