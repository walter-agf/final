#ifndef RAN_CANNON_H
#define RAN_CANNON_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPen>

class ran_cannon: public QGraphicsItem
{
public:
    double rad;
    ran_cannon(double radio);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void posicion (double x, double y);
};

#endif // RAN_CANNON_H
