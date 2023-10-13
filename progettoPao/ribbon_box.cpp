#include "ribbon_box.h"
#include <QPushButton>
#include <QHBoxLayout>
#include "container.h"
#include "in_out.h"
#include <QPixmap>
#include "littlewindow.h"
#include <QErrorMessage>

Ribbon_box::Ribbon_box(Container* c, ShowMenu_Box *menub, FoodModification_box* mb, QGroupBox *parent):
    QGroupBox(parent), foodContainer(c), menuBox(menub), modificationBox(mb){

    QPixmap carica("../icone/carica1.png");
    QPushButton* load = new QPushButton();
        load->setIcon(carica);
        connect(load, SIGNAL(clicked()), this, SLOT(load()));
    QPushButton* save = new QPushButton();
        QPixmap scarica("../icone/scarica1.png");
        save->setIcon(scarica);
        connect(save, SIGNAL(clicked()), this, SLOT(save()));

    QPushButton* maxButton = new QPushButton("Ricerca valore massimo");
        connect(maxButton, SIGNAL(clicked()), this, SLOT(searchMax()));


    QHBoxLayout* header_layout = new QHBoxLayout();
    header_layout->addWidget(load);
    header_layout->addWidget(save);
    header_layout->addWidget(maxButton);

    setTitle("Home");
    setLayout(header_layout);
}

Ribbon_box::~Ribbon_box(){
    delete foodContainer;
    delete menuBox;
    delete modificationBox;
}

void Ribbon_box::load(){
    In_Out::read(foodContainer);
    menuBox->updateMenu();
    modificationBox->updateBox();
}

void Ribbon_box::save(){
    In_Out::write(foodContainer);
}

void Ribbon_box::searchMax() const{
    if(foodContainer->isEmpty()){
        QErrorMessage *err = new QErrorMessage;
        err->showMessage("Contenitore Vuoto");
    }else{
        LittleWindow* lw = new LittleWindow(foodContainer);
        lw->show();
    }
}
