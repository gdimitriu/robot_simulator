#include "wallelement.h"

WallElement::WallElement(QObject *parent) : MapElement(parent)
{

}

void WallElement::draw(QPainter * painter)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::black, 15, Qt::SolidLine, Qt::FlatCap));
    painter->drawLine(wall);

    painter->setPen(QPen(Qt::black, 2, Qt::DashLine, Qt::RoundCap));
    painter->drawLine(vectorDim);

    if ( abs(wall.dx()) < 10 && abs(wall.dy()) > 10 )
    {
        painter->save();
        painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
        QPoint center = vectorDim.center();
        painter->translate(center);
        painter->rotate(-90);
        painter->drawText(0,0, QString::number(length));
        auto x = center.x();
        center.setX(-center.y());
        center.setY(-x);
        painter->translate(center);
        painter->restore();
    } else if ( abs(wall.dx()) > 10 )
    {
        painter->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
        painter->drawText(vectorDim.center(),QString::number(length));
    }
}

bool WallElement::isInside(QPoint point)
{
    //horizontal wall
    if ( wall.y1() == wall.y2() && wall.x1() != wall.x2() )
    {
        if ( wall.x1() < wall.x2() )
        {
            //from left to right
            if ( wall.x1() > point.x() || wall.x2() < point.x() )
                return false;
            else if ( (wall.y1() + 7) < point.y() || (wall.y1() - 7) > point.y() )
                return false;
            else if ( (wall.y2() + 7) < point.y() || (wall.y2() - 7) > point.y() )
               return false;
        } else
        {
            //from right to left
            if ( wall.x1() < point.x() || wall.x2() > point.x() )
                return false;
            else if ( (wall.y1() + 7) < point.y() || (wall.y1() - 7) > point.y() )
                return false;
            else if ( (wall.y2() + 7) < point.y() || (wall.y2() - 7) > point.y() )
               return false;
        }
    } else
    {
        //vertical wall
        if ( wall.x1() == wall.x2() && wall.y1() != wall.y2() )
        {
            if ( wall.y1() < wall.y2() )
            {
                //from upper to bottom
                if ( wall.y1() > point.y() || wall.y2() < point.y() )
                    return false;
                else if ( (wall.x1() + 7) < point.x() || (wall.x1() - 7) > point.x() )
                    return false;
                else if ( (wall.x2() + 7) < point.x() || (wall.x2() - 7) > point.x() )
                   return false;
            } else
            {
                //from bottom to upper
                if ( wall.y1() < point.y() || wall.y2() > point.y() )
                    return false;
                else if ( (wall.x1() + 7) < point.x() || (wall.x1() - 7) > point.x() )
                    return false;
                else if ( (wall.x2() + 7) < point.x() || (wall.x2() - 7) > point.x() )
                   return false;
            }
        }
    }
    return true;
}

void WallElement::addStartPoint(QPoint point)
{
    wall.setP1(point);
    wall.setP2(point);
    vectorDim.setP1(point + QPoint(0,30));
    vectorDim.setP2(point + QPoint(0,30));
}

void WallElement::addEndPoint(QPoint point)
{
    wall.setP2(point);
    if ( abs(wall.dx()) > 10 )
    {
        vectorDim.setP1(wall.p1() + QPoint(0,30));
        vectorDim.setP2(point + QPoint(0,30));
    } else
    {
        vectorDim.setP1(wall.p1() + QPoint(30,0));
        vectorDim.setP2(point + QPoint(30,0));
    }
}
