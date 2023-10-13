#ifndef FOODEXTRAWIDGET_H
#define FOODEXTRAWIDGET_H

#include <QWidget>
#include "food.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>


class FoodExtraWidget : public QWidget{
    Q_OBJECT
    private:
    Food* food;
    QPushButton* exampleButton;
    QPushButton* infoButton;
    QVBoxLayout* verticalLayout;
    QGroupBox* extraButtonBox;
public:
    FoodExtraWidget(Food* f, QWidget *parent = nullptr);
    ~FoodExtraWidget();
    QGroupBox* getGroupBox() const;
public slots:
    void displayExample() const;
    void displayInfo() const;
};

#endif // FOODEXTRAWIDGET_H
