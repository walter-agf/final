#include "fisicas.h"

fisicas::fisicas(float posX_, float posY_, float velX_, float velY_, float radio_, float e_)
{
    PX = posX_; //pos en x
    PY = posY_; //pos en y
    pos_inicial_x = posX_;
    pos_inicial_y = posY_;
    R = radio_; //radio del cuerpo
    VX = velX_; //vel en x
    VY = velY_; //vel en y
    G = 9.81; //gravedad
    e = e_; //Coeficiente de restitucion
}

void fisicas::actualizar(float time, double vy)
{
    PX = pos_inicial_x + (VX * time);
    PY = pos_inicial_y + (vy*time)-((G*pow(time,2))/2);
    VY = vy - (G*time);
}


float fisicas::getPY() const
{
    return PY;
}

float fisicas::getR() const
{
    return R;
}

float fisicas::getVX() const
{
    return VX;
}

float fisicas::getVY() const
{
    return VY;
}

float fisicas::getE() const
{
    return e;
}

float fisicas::getPX() const
{
    return PX;
}

void fisicas::set_vel(float vx, float vy, float px, float py)
{
    VX = vx;
    VY = vy;
    PX = px;
    PY = py;
}
