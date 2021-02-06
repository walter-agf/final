#include "rastro.h"

rastro::rastro(){}
QRectF rastro::boundingRect() const
{
    return QRectF(-1*rad,-1*rad,2*rad,2*rad);
}

void rastro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
}

void rastro::posicion(double x, double y)
{
    setPos(x, 720 - y);
}
