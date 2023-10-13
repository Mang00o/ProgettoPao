#include "foodsetwidget.h"
#include <QVBoxLayout>
#include "carbsource.h"
#include "fatsource.h"
#include "proteinsource.h"

FoodSetWidget::FoodSetWidget(Food* f, ShowMenu_Box *bb, QWidget *parent) :
QWidget(parent), food(f), menuBox(bb){
    editLayout = new QGridLayout();

    QLabel* foodName = new QLabel("Nome\nalimento");
        foodName->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
        editLayout->addWidget(foodName,0,0);
    QLineEdit* nameEdit = new QLineEdit();
        nameEdit->insert(food->getName());
        connect(nameEdit, SIGNAL(textChanged(QString)), this, SLOT(changeN(QString)));
        editLayout->addWidget(nameEdit,1,0);

    QLabel* foodCarbValue = new QLabel("Quantitativo\nCarboidrati(gr)");
        foodCarbValue->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
        editLayout->addWidget(foodCarbValue,0,1);
    QSpinBox* carbEdit = new QSpinBox();
        carbEdit->setValue(food->getCarb());
        connect(carbEdit, SIGNAL(valueChanged(int)), this, SLOT(changeC(int)));
        editLayout->addWidget(carbEdit,1,1);

    QLabel* foodProteinValue = new QLabel("Quantitativo\nProteine(gr)");
        foodProteinValue->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
        editLayout->addWidget(foodProteinValue,0,2);
    QSpinBox* proteinEdit = new QSpinBox();
        proteinEdit->setValue(food->getProtein());
        connect(proteinEdit, SIGNAL(valueChanged(int)), this, SLOT(changeP(int)));
        editLayout->addWidget(proteinEdit,1,2);

    QLabel* foodFatValue = new QLabel("Quantitativo\nGrassi(gr)");
        foodFatValue->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
        editLayout->addWidget(foodFatValue,0,3);
    QSpinBox* fatEdit = new QSpinBox();
        fatEdit->setValue(food->getFat());
        connect(fatEdit, SIGNAL(valueChanged(int)), this, SLOT(changeF(int)));
        editLayout->addWidget(fatEdit,1,3);

    if(dynamic_cast<CarbSource*>(food)){
        QLabel* glutenFreeValue = new QLabel();
            glutenFreeValue->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
            glutenFreeValue->setText("e' "+food->getAttributeLabel()+"?");
            editLayout->addWidget(glutenFreeValue,0,4);
        QCheckBox* checkButton = new QCheckBox();
            checkButton->setText(food->getAttributeLabel());
            checkButton->setChecked(dynamic_cast<CarbSource*>(food)->getGlutenFreeValue());
            connect(checkButton,SIGNAL(stateChanged(int)),this,SLOT(changeCarbAttribute(int)));
            editLayout->addWidget(checkButton,1,4);
    }else if(dynamic_cast<ProteinSource*>(food)){
        QLabel* vegetarianValue = new QLabel();
            vegetarianValue->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
            vegetarianValue->setText("e' "+food->getAttributeLabel()+"?");
            editLayout->addWidget(vegetarianValue,0,4);
        QCheckBox* checkButton = new QCheckBox();
            checkButton->setText(food->getAttributeLabel());
            checkButton->setChecked(dynamic_cast<ProteinSource*>(food)->getVegetarianValue());
            connect(checkButton,SIGNAL(stateChanged(int)),this,SLOT(changeProtAttribute1(int)));
            editLayout->addWidget(checkButton,1,4);
        QLabel* veganValue = new QLabel("e' Vegan?");
            veganValue->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
            editLayout->addWidget(veganValue,0,5);
        QCheckBox* proteinCheckButton = new QCheckBox();
            proteinCheckButton->setText("Vegano");
            proteinCheckButton->setChecked(dynamic_cast<ProteinSource*>(food)->getVeganValue());
            connect(proteinCheckButton,SIGNAL(stateChanged(int)),this,SLOT(changeProtAttribute2(int)));
            editLayout->addWidget(proteinCheckButton,1,5);
    }else if(dynamic_cast<FatSource*>(food)){
        QLabel* saturedFatValue = new QLabel();
            saturedFatValue->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
            saturedFatValue->setText(food->getAttributeLabel());
            editLayout->addWidget(saturedFatValue,0,4);
        QSpinBox* fatPercEdit = new QSpinBox();
            fatPercEdit->setRange(0, 100);
            fatPercEdit->setValue(dynamic_cast<FatSource*>(food)->getSatFatValue());
            connect(fatPercEdit, SIGNAL(valueChanged(int)), this, SLOT(changeFatAttribute(int)));
            editLayout->addWidget(fatPercEdit,1,4);
    }

    foodModifierBox = new QGroupBox;
        foodModifierBox->setLayout(editLayout);
}

FoodSetWidget::~FoodSetWidget(){
    delete food;
    delete menuBox;
    delete editLayout;
    delete menuBox;
}

void FoodSetWidget::changeN(QString name){
    food->setName(name);
    menuBox->updateMenu();
}
void FoodSetWidget::changeC(int value){
    food->setCarb(value);
    menuBox->updateMenu();
}
void FoodSetWidget::changeP(int value){
    food->setProtein(value);
    menuBox->updateMenu();
}
void FoodSetWidget::changeF(int value){
    food->setFat(value);
    menuBox->updateMenu();
}

void FoodSetWidget::changeCarbAttribute(int value){
    if(value==Qt::Checked)
        dynamic_cast<CarbSource*>(food)->setGlutenFreeValue(true);
    else if(value==Qt::Unchecked)
        dynamic_cast<CarbSource*>(food)->setGlutenFreeValue(false);
}

void FoodSetWidget::changeProtAttribute1(int value){
    if(value==Qt::Checked)
        dynamic_cast<ProteinSource*>(food)->setVegetarianValue(true);
    else if(value==Qt::Unchecked)
        dynamic_cast<ProteinSource*>(food)->setVegetarianValue(false);

}

void FoodSetWidget::changeProtAttribute2(int value){
    if(value==Qt::Checked)
        dynamic_cast<ProteinSource*>(food)->setVeganValue(true);
    else if(value==Qt::Unchecked)
        dynamic_cast<ProteinSource*>(food)->setVeganValue(false);
}

void FoodSetWidget::changeFatAttribute(int value){
    dynamic_cast<FatSource*>(food)->setSatFatValue(value);
}

QGroupBox* FoodSetWidget::getGroupBox() const{
    return foodModifierBox;
}
