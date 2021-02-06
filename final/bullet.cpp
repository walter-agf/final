#include "bullet.h"

bullet::bullet(QObject *parent) : QObject(parent)
{
    pixmap = new QPixmap(":/pictures/bola-negra_24.png");
}
QRectF bullet::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,0,0,ancho,alto);
}

void bullet::actualizar(double posx, double posy)
{
    setPos(posx,720 - posy);
}
