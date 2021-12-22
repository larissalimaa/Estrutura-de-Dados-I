#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

class Ponto
{
public:
    Ponto();
    Ponto(float a, float b);
    ~Ponto();
    float getX();
    float getY();
    void setX(float xx);
    void setY(float yy);
    float distancia(Ponto *op);
private:
    float x, y;
};

#endif // PONTO_H_INCLUDED
