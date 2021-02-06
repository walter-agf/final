#include "ran_cannon.h"

ran_cannon::ran_cannon(double radio)
{
    rad = radio;
}

QRectF ran_cannon::boundingRect() const
{
    return QRectF(-1*rad,-1*rad,2*rad,2*rad);
}

void ran_cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::transparent);
    QPen pain (Qt::darkYellow);
    pain.setWidth(5);
    painter->setPen(pain);
    painter->drawEllipse(boundingRect());
}

void ran_cannon::posicion(double x, double y)
{
    setPos(x, 720 - y);
}
