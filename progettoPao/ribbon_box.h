#ifndef RIBBON_BOX_H
#define RIBBON_BOX_H

#include "container.h"
#include <QGroupBox>
#include "showMenu_box.h"
#include "foodModification_box.h"

class Ribbon_box : public QGroupBox{
Q_OBJECT
private:
    Container* foodContainer;
    ShowMenu_Box* menuBox;
    FoodModification_box* modificationBox;
public:    
    Ribbon_box(Container* c, ShowMenu_Box* menub, FoodModification_box* mb,QGroupBox *parent = nullptr);
    ~Ribbon_box();
public slots:
    void load();
    void save();
    void searchMax() const;
};
#endif // RIBBON_BOX_H
