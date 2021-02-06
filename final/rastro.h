#ifndef RASTRO_H
#define RASTRO_H

#include <QGraphicsItem>
#include <QPainter>

class rastro: public QGraphicsItem
{
public:
    double rad = 4;
    rastro();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void posicion (double x, double y);
};

#endif // RASTRO_H
