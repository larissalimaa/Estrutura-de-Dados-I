#include <iostream>
#include <cmath>
#include "Ponto.h"

using namespace std;

Ponto::Ponto()
{
    cout << "Digite X: ";
    cin >> x;
    cout << "Digite Y: ";
    cin >> y;
}
Ponto::Ponto(float a, float b)
{
    x = a;
    y = b;
}
Ponto::~Ponto()
{
    cout << "Destrutor" << endl;
}
float Ponto::getX()
{
    return x;
}
float Ponto::getY()
{
    return y;
}
void Ponto::setX(float xx)
{
    x = xx;
}
void Ponto::setY(float yy)
{
    y = yy;
}
float Ponto::distancia(Ponto *op)
{
    float dx = x - (*op).x;
    float dy = y - op->y;
    float d = sqrt(dx*dx + dy*dy);
    return d;
}
