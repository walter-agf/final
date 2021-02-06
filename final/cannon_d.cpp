#include "cannon_d.h"

cannon_d::cannon_d(QObject *parent) : QObject(parent)
{
    pixmap = new QPixmap(":/pictures/canon_64_2.png");
}

QRectF cannon_d::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void cannon_d::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,0,0,ancho,alto);
}

void cannon_d::actualizar(double posx, double posy)
{
    setPos(posx,posy);
}
