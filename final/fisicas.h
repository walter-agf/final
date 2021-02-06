#ifndef FISICAS_H
#define FISICAS_H

#include <math.h>
#include <cmath>

class fisicas
{
public:
    fisicas(float posX_,float posY_,float velX_,float velY_,float radio_,float e_);
    void actualizar(float time, double vy);
    // Metodos
    float getPX() const;
    float getPY() const;
    float getMass() const;
    float getR() const;
    float getVX() const;
    float getVY() const;
    float getE() const;
    void set_vel(float vx, float vy, float px, float py);
    //Variables
    float PX; //pos en x
    float PY; //pos en y
    float R; //radio del cuerpo
    float VX; //vel en x
    float VY; //vel en y
    float G; //gravedad
    float e; //Coeficiente de restitucion
};

#endif // FISICAS_H
