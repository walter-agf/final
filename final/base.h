#ifndef BASE_H
#define BASE_H

#include <QGraphicsItem>
#include <QPainter>

class base: public QGraphicsItem
{
public:
    double w,h;
    double x,y;
    base(double x_, double y_, double w_, double h_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BASE_H
