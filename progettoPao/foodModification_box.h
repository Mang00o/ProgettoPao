#ifndef FOODMODIFICATION_BOX_H
#define FOODMODIFICATION_BOX_H

#include <QGroupBox>
#include "container.h"
#include <QGridLayout>
#include "foodextrawidget.h"
#include "showMenu_box.h"
#include "foodsetwidget.h"
#include <QPushButton>
#include "mybutton.h"
#include <QComboBox>

class FoodModification_box : public QGroupBox{
Q_OBJECT
private:
    Container* foodContainer;
    QGridLayout* layout;   
    ShowMenu_Box* menuBox;
    QComboBox* chooseFoodType;
    QPushButton* addButton;
    QList<MyButton*>* deleteButtonList;
    QList<FoodSetWidget*>* foodSetWidgetList;
    QList<FoodExtraWidget*>* foodExtraWidgetList;
public:
    FoodModification_box(Container* c, ShowMenu_Box* mb, QGroupBox *parent = nullptr);
    ~FoodModification_box();
public slots:
    void addFood();
    void deleteFood(int index);
    void updateBox();
    void createFood(QString selectedItemText);
};

#endif // FOODMODIFICATION_BOX_H
