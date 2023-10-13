#ifndef LITTLEWINDOW_H
#define LITTLEWINDOW_H

#include <QWidget>
#include "container.h"
#include <QVBoxLayout>
#include <QComboBox>

class LittleWindow : public QWidget{
Q_OBJECT
private:
    Container* foodContainer;
    QVBoxLayout* layout;
    QComboBox* maxValueBox;
public:
    LittleWindow(Container* c, QWidget *parent = nullptr);
    ~LittleWindow();
public slots:
    void showMax(int value) const;
};

#endif // LITTLEWINDOW_H
