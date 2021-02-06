#include "cannon.h"

cannon::cannon(QObject *parent) : QObject(parent)
{
    pixmap = new QPixmap(":/pictures/canon_64.png");
}

QRectF cannon::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,0,0,ancho,alto);
}

void cannon::actualizar(double posx, double posy)
{
    setPos(posx,posy);
}
