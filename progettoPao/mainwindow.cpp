#include "mainwindow.h"
#include "ribbon_box.h"
#include "foodModification_box.h"
#include "showMenu_box.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent){
    foodContainer = new Container();

    ShowMenu_Box* bottomBox = new ShowMenu_Box(foodContainer);
    FoodModification_box* middleBox = new FoodModification_box(foodContainer,bottomBox);
    Ribbon_box* headerBox = new Ribbon_box(foodContainer,bottomBox,middleBox);
    layout = new QGridLayout;
    layout->addWidget(headerBox,0,0);
    layout->addWidget(middleBox,1,0);
    layout->addWidget(bottomBox,1,1);

    setLayout(layout);
}

MainWindow::~MainWindow(){
    delete foodContainer;
    delete layout;
}
