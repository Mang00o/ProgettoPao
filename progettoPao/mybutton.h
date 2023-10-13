#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QPixmap>

class MyButton : public QPushButton{
Q_OBJECT
private:
    int index;
public:
    MyButton(QString text, int i, QPushButton* parent = nullptr);
    MyButton(QPixmap icon, int i, QPushButton* parent = nullptr);
    void decreasePosition();
signals:
    void myClick(int index);
private slots:
    void handleClick();
};

#endif // MYBUTTON_H
