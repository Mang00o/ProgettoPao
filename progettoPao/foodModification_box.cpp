#include "foodModification_box.h"
#include "carbsource.h"
#include "fatsource.h"
#include "foodsetwidget.h"
#include "proteinsource.h"
#include <QLabel>
#include <QPixmap>
#include <QRadioButton>
#include <QButtonGroup>
#include <QTableView>
#include <QListView>

FoodModification_box::FoodModification_box(Container *c, ShowMenu_Box *mb, QGroupBox *parent):
QGroupBox(parent), foodContainer(c), menuBox(mb){
    foodSetWidgetList = new QList<FoodSetWidget*>();
    deleteButtonList = new QList<MyButton*>;
    foodExtraWidgetList = new QList<FoodExtraWidget*>();

    addButton = new QPushButton();
        QPixmap aggiungi("../icone/aggiungi.png");
        addButton->setIcon(aggiungi);
        connect(addButton, SIGNAL(clicked()), this, SLOT(addFood()));

    layout = new QGridLayout();
    layout->addWidget(addButton,0,0);

    setTitle("Sezione Cibo");
    setLayout(layout);
}

FoodModification_box::~FoodModification_box(){
    delete foodContainer;
    delete layout;
    delete menuBox;
    delete chooseFoodType;
    delete addButton;
    delete deleteButtonList;
    delete foodSetWidgetList;
    delete foodExtraWidgetList;
}

void FoodModification_box::addFood(){
    QPixmap elimina("../icone/elimina.png");
    MyButton* deleteButton = new MyButton(elimina,foodContainer->countElements());
    deleteButtonList->append(deleteButton);
    connect(deleteButton, SIGNAL(myClick(int)), this, SLOT(deleteFood(int)));
    layout->addWidget(deleteButton,foodContainer->countElements()+1,0);

    chooseFoodType = new QComboBox();
        chooseFoodType->addItem("Selezionare fonte di:");
        chooseFoodType->addItem("carboidrato");
        chooseFoodType->addItem("proteina");
        chooseFoodType->addItem("grasso");
        connect(chooseFoodType, SIGNAL(textActivated(QString)), this, SLOT(createFood(QString)));
    layout->addWidget(chooseFoodType,foodContainer->countElements()+1,1);
}

void FoodModification_box::createFood(QString selectedItemText){
    Food* f;
    if(selectedItemText=="carboidrato")
        f = new CarbSource();
    else if(selectedItemText=="proteina")
        f = new ProteinSource();
    else
        f = new FatSource();
    foodContainer->insert(f);

    FoodSetWidget* fsw = new FoodSetWidget(f,menuBox);
    foodSetWidgetList->append(fsw);    

    FoodExtraWidget* few = new FoodExtraWidget(f);
    foodExtraWidgetList->append(few);

    layout->replaceWidget(chooseFoodType,fsw->getGroupBox());
    delete chooseFoodType;
    layout->addWidget(few->getGroupBox(),foodContainer->countElements(),2);

    menuBox->updateMenu();
}

void FoodModification_box::deleteFood(int index){
    layout->removeWidget(deleteButtonList->at(index));
    delete deleteButtonList->at(index);
    deleteButtonList->removeAt(index);

    if(index==foodContainer->countElements()){
        layout->removeWidget(chooseFoodType);

        delete chooseFoodType;
    }else{
        foodContainer->removeAtIndex(index);

        layout->removeWidget(foodSetWidgetList->at(index)->getGroupBox());
        layout->removeWidget(foodExtraWidgetList->at(index)->getGroupBox());

        delete foodSetWidgetList->at(index)->getGroupBox();
        delete foodExtraWidgetList->at(index)->getGroupBox();

        foodSetWidgetList->removeAt(index);
        foodExtraWidgetList->removeAt(index);
    }

    for(int i = index; i<foodSetWidgetList->count(); i++){
        deleteButtonList->at(i)->decreasePosition();
    }

    menuBox->updateMenu();
}

void FoodModification_box::updateBox(){
    for(Container::Iterator i = foodContainer->middle(foodSetWidgetList->count()); i!=foodContainer->end(); ++i){
        QPixmap elimina("../icone/elimina.png");
        MyButton* deleteButton = new MyButton(elimina,foodContainer->countElements());
            deleteButtonList->append(deleteButton);
            connect(deleteButton, SIGNAL(myClick(int)), this, SLOT(deleteFood(int)));

        FoodSetWidget* fsw = new FoodSetWidget(i.getFood(),menuBox);
        foodSetWidgetList->append(fsw);

        FoodExtraWidget* few = new FoodExtraWidget(i.getFood());
        foodExtraWidgetList->append(few);

        layout->addWidget(deleteButton,foodSetWidgetList->count(),0);
        layout->addWidget(fsw->getGroupBox(),foodSetWidgetList->count(),1);
        layout->addWidget(few->getGroupBox(),foodSetWidgetList->count(),2);
    }
}
