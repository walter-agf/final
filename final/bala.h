#ifndef BALA_H
#define BALA_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QLabel>

#include "fisicas.h"

class bala: public QGraphicsItem
{
public:
    bala(double posx, double posy, double radio);
    ~bala();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void actualizar();
    fisicas *getEsf();
    fisicas *esf;
    QLabel *tiempo_bala;
};

#endif // BALA_H
