#include "foodextrawidget.h"
#include <QTableView>
#include <QListView>
#include "carbsource.h"
#include "fatsource.h"
#include "proteinsource.h"

FoodExtraWidget::FoodExtraWidget(Food *f, QWidget *parent) : QWidget(parent), food(f){
    exampleButton = new QPushButton();
        connect(exampleButton, SIGNAL(clicked()), this, SLOT(displayExample()));
    infoButton = new QPushButton();
        connect(infoButton, SIGNAL(clicked()), this, SLOT(displayInfo()));

    if(dynamic_cast<CarbSource*>(f)){
        exampleButton->setText("Esempi\nfonti carboidrati");
        infoButton->setText("Info su\nfonti carboidrati");
    }
    else if(dynamic_cast<ProteinSource*>(f)){
        exampleButton->setText("Esempi\nfonti proteine");
        infoButton->setText("Info su\nfonti proteine");
    }
    else if(dynamic_cast<FatSource*>(f)){
        exampleButton->setText("Esempi\nfonti grassi");
        infoButton->setText("Info su\nfonti grassi");
    }

    verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(exampleButton);
    verticalLayout->addWidget(infoButton);
    extraButtonBox = new QGroupBox;
    extraButtonBox->setLayout(verticalLayout);
}

FoodExtraWidget::~FoodExtraWidget(){
    delete food;
    delete exampleButton;
    delete infoButton;
    delete verticalLayout;
    delete extraButtonBox;
}

void FoodExtraWidget::displayExample() const{
    QTableView* tableview = new QTableView();;
    tableview->setModel(food->createTableModel());
    tableview->show();
}

void FoodExtraWidget::displayInfo() const{
    QListView* listView = new QListView;
    listView->setModel(food->createListModel());
    listView->show();
}

QGroupBox* FoodExtraWidget::getGroupBox() const{
    return extraButtonBox;
}
