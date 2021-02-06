#ifndef CANNON_D_H
#define CANNON_D_H

#include <QObject>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <stdlib.h>

class cannon_d: public QObject, public QGraphicsItem
{
public:
    explicit cannon_d(QObject *parent = nullptr);

    QPixmap *pixmap;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    void actualizar(double posx, double posy);

    float ancho = 64; //Ancho de la figura
    float alto = 64; // Alto de la figura
};

#endif // CANNON_D_H
