#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <stdlib.h>

class bullet: public QObject, public QGraphicsItem
{
public:
    explicit bullet(QObject *parent = nullptr);

    QPixmap *pixmap;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    void actualizar(double posx, double posy);

    float ancho = 24; //Ancho de la figura
    float alto = 24; // Alto de la figura
};

#endif // BULLET_H
