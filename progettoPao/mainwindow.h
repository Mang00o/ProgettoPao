#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QWidget>
#include "container.h"

class MainWindow : public QWidget{
Q_OBJECT
private:
    Container* foodContainer;
    QGridLayout* layout;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
