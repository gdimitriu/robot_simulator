#include "doorelement.h"

DoorElement::DoorElement(QObject *parent) : WallElement(parent)
{

}

Qt::PenStyle DoorElement::getPenStyle()
{
    return Qt::DotLine;
}
