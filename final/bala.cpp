#include "bala.h"

bala::bala(double posx, double posy, double radio)
{
    ini_x = posx;
    ini_y = posy;
    float velx,vely,mass,K,e;
    mass = 12; //Masa
    velx = 0; //velocidad en x
    vely = 0; //velocidad en y
    K = 0.08; //resitencia en del aire
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

    painter->setBrush(Qt::transparent);
    QPen pain (Qt::blue);
    pain.setWidth(3);
    painter->setPen(pain);
    painter->drawEllipse(boundingRect());
}

void bala::actualizar(float time, double x, double y, double vy)
{
    esf->actualizar(time, x, y,vy);
    setPos(esf->getPX(),720-esf->getPY());
}

void bala::ingreso(double vx, double vy)
{
    vel_y = vy;
    esf->set_vel(vx,vy,ini_x,ini_y);
}

fisicas *bala::getEsf()
{
    return esf;
}
