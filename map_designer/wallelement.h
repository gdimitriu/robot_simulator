#ifndef WALLELEMENT_H
#define WALLELEMENT_H

#include "mapelement.h"
#include <QtCore>

class WallElement : public MapElement
{
   Q_OBJECT
public:
    WallElement(QObject *parent = nullptr);
    void draw(QPainter * painter);
    bool isInside(QPoint point);
    void addStartPoint(QPoint point);
    void addEndPoint(QPoint point);
protected:
    virtual Qt::PenStyle getPenStyle();
private:
    QLine element;
    QLine vectorDim;
};

#endif // WALLELEMENT_H
