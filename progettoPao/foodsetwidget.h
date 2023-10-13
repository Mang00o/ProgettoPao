#ifndef FOODSETWIDGET_H
#define FOODSETWIDGET_H

#include "food.h"
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include "showMenu_box.h"
#include <QGridLayout>
#include <QCheckBox>

class FoodSetWidget : public QWidget{
Q_OBJECT
private:
    Food* food;
    QGroupBox *foodModifierBox;
    QGridLayout* editLayout;
    ShowMenu_Box* menuBox;
public:
    explicit FoodSetWidget(Food* f, ShowMenu_Box* bb, QWidget *parent = nullptr);
    ~FoodSetWidget();
    QGroupBox* getGroupBox() const;
public slots:
    void changeN(QString name);
    void changeC(int value);
    void changeP(int value);
    void changeF(int value);
    void changeCarbAttribute(int value);
    void changeProtAttribute1(int value);
    void changeProtAttribute2(int value);
    void changeFatAttribute(int value);
};
#endif // FOODSETWIDGET_H
