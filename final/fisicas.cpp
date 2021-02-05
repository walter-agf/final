#include "fisicas.h"

fisicas::fisicas(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)
{
    PX = posX_; //pos en x
    PY = posY_; //pos en y
    mass = masa_; // masa del cuerpo
    R = radio_; //radio del cuerpo
    VX = velX_; //vel en x
    VY = velY_; //vel en y
    AX = 0; //acel en x
    AY = 0; //acel en y
    G = 9.81; //gravedad
    K = K_; //Resistencia del aire
    e = e_; //Coeficiente de restitucion
    V = 0; //vector de velocidad
    dt = 0.1; //delta tiempo
}

void fisicas::actualizar()
{
    V = sqrt(pow(VX,2)+pow(VY,2));
    angulo = atan(VY/VX);
    AX = -((K*(V*V)*(R*R))/mass)*cos(angulo);
    AY = (-((K*(V*V)*(R*R))/mass)*sin(angulo))-G;
    PX = PX + ((VX*(dt)))+(((AX*(dt*dt)))/2);
    PY = PY + ((VY*(dt)))+(((AY*(dt*dt)))/2);
    VX = VX + AX*dt;
    VY = VY + AY*dt;
}


float fisicas::getPY() const
{
    return PY;
}

float fisicas::getMass() const
{
    return mass;
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
