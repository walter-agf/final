#include "base.h"

base::base(double x_, double y_, double w_, double h_)
{
    x = x_;
    y = y_;
    w = w_;
    h = h_;
}
QRectF base::boundingRect() const
{
    return QRectF(x,y,w,h);
}

void base::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawRect(boundingRect());
}
