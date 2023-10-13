#include "showMenu_box.h"
#include <QHBoxLayout>

ShowMenu_Box::ShowMenu_Box(Container *c, QGroupBox *parent) : QGroupBox(parent), foodContainer(c){
    labelMenu = new QLabel("Aggiungi Cibo");

    QHBoxLayout* middle_layout = new QHBoxLayout();
    middle_layout->addWidget(labelMenu);

    setTitle("Sezione Menu");
    setLayout(middle_layout);
}

ShowMenu_Box::~ShowMenu_Box(){
    delete labelMenu;
    delete foodContainer;
}

void ShowMenu_Box::updateMenu(){
    QString* menuText = foodContainer->read();
    labelMenu->clear();
    labelMenu->setText(*menuText);
}
