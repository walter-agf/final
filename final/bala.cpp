#include "bala.h"

bala::bala(double posx, double posy, double radio)
{
    ini_x = posx;
    ini_y = posy;
    setPos(ini_x,ini_y);
    float velx,vely,e;
    velx = 0; //velocidad en x
    vely = 0; //velocidad en y
    e = 0.4; //coeficiente de restitucion
    tiempo_bala = 0;
    rango = 0;
    esf = new fisicas(posx,posy,velx,vely,radio,e);
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
    if (color == 1){
        painter->setBrush(Qt::transparent);
        QPen pain (Qt::blue);
        pain.setWidth(3);
        painter->setPen(pain);
        painter->drawEllipse(boundingRect());
    }
    else if (color == 2){
        painter->setBrush(Qt::transparent);
        QPen pain (Qt::green);
        pain.setWidth(3);
        painter->setPen(pain);
        painter->drawEllipse(boundingRect());
    }
    else if (color == 3){
        painter->setBrush(Qt::transparent);
        QPen pain (Qt::red);
        pain.setWidth(3);
        painter->setPen(pain);
        painter->drawEllipse(boundingRect());
    }
}

void bala::actualizar(float time, double vy)
{
    esf->actualizar(time,vy);
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
