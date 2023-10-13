#ifndef IN_OUT_H
#define IN_OUT_H

#include "container.h"

class In_Out{
private:
    static QString getType(Food* f);
public slots:
    static void write(Container *foodContainer);
    static void read(Container *foodContainer);
};

#endif // IN_OUT_H
