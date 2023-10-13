#ifndef SHOWMENU_BOX_H
#define SHOWMENU_BOX_H

#include <QGroupBox>
#include <QLabel>
#include "container.h"

class ShowMenu_Box : public QGroupBox{
private:
    QLabel* labelMenu;
    Container* foodContainer;
public:
    ShowMenu_Box(Container* c, QGroupBox *parent = nullptr);
    ~ShowMenu_Box();
public slots:
    void updateMenu();
};

#endif // SHOWMENU_BOX_H
