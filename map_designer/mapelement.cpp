#include "mapelement.h"

MapElement::MapElement(QObject *parent) : QObject(parent), length(0.0)
{

}

MapElement::~MapElement()
{

}

void MapElement::setLength(double value)
{
    length = value;
}

double MapElement::getLength()
{
    return length;
}
