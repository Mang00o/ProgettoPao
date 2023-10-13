#include "mybutton.h"

MyButton::MyButton(QString text, int i, QPushButton *parent) :
    QPushButton(parent), index(i){
    setText(text);
    connect(this, &QPushButton::clicked, this, &MyButton::handleClick);
}

MyButton::MyButton(QPixmap icon, int i, QPushButton *parent) :
    QPushButton(parent), index(i){
    setIcon(icon);
    connect(this, &QPushButton::clicked, this, &MyButton::handleClick);
}

void MyButton::handleClick(){
    emit myClick(index);
}

void MyButton::decreasePosition(){
    index--;
}

