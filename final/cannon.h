#ifndef CANNON_H
#define CANNON_H

#include <QObject>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <stdlib.h>

class cannon: public QObject, public QGraphicsItem
{
public:
    explicit cannon(QObject *parent = nullptr);

    QPixmap *pixmap;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    void actualizar(double posx, double posy);

    float ancho = 64; //Ancho de la figura
    float alto = 64; // Alto de la figura
};

#endif // CANNON_H
