#ifndef BALA_H
#define BALA_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>
#include <QLabel>
#include <QPen>
#include "fisicas.h"

class bala: public QGraphicsItem
{
public:
    bala(double posx, double posy, double radio);
    ~bala();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
    void actualizar(float time, double x, double y, double vy);
    void ingreso(double vx, double vy);
    double ini_x;//posicion en x inicial
    double ini_y;//posicion en y inicial
    double vel_y;//velocidad inicial en y
    fisicas *getEsf();
    fisicas *esf;
    QLabel *tiempo_bala;
};

#endif // BALA_H
