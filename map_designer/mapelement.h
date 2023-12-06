#ifndef MAPELEMENT_H
#define MAPELEMENT_H

#include <Qt>
#include <QObject>
#include <QPainter>
#include <QPoint>

class MapElement : public QObject
{
    Q_OBJECT
public:
    MapElement(QObject *parent = nullptr);
    virtual ~MapElement();
    virtual void draw(QPainter * painter) = 0;
    virtual bool isInside(QPoint point) = 0;
    virtual void setLength(double value);
    virtual double getLength();
signals:
protected:
    double length;

};

#endif // MAPELEMENT_H
