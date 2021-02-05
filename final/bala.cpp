#include "bala.h"

bala::bala(double posx, double posy, double radio)
{
    float velx,vely,mass,K,e;
    mass = 12; //Masa
    velx = 0; //velocidad en x
    vely = 0; //velocidad en y
    K = 0; //resitencia en del aire
    e = 0.4; //coeficiente de restitucion
    esf = new fisicas(posx,posy,velx,vely,mass,radio,K,e);
}

bala::~bala()
{
    delete esf;
}

QRectF bala::boundingRect() const
{
    return QRectF(-1*esf->getR(),-1*esf->getR(),2*esf->getR(),2*esf->getR());
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());
}

void bala::actualizar()
{
    esf->actualizar();
    setPos(esf->getPX(),720-esf->getPY());
}

fisicas *bala::getEsf()
{
    return esf;
}
