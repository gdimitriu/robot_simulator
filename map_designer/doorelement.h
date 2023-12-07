#ifndef DOORELEMENT_H
#define DOORELEMENT_H

#include "wallelement.h"

class DoorElement : public WallElement
{
    Q_OBJECT
public:
    DoorElement(QObject *parent = nullptr);
protected:
    virtual Qt::PenStyle getPenStyle();
};

#endif // DOORELEMENT_H
