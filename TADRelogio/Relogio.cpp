#include <iostream>
#include "Relogio.h"

using namespace std;

Relogio::Relogio(int h, int m, int s)
{
    acertar(h, m, s);
}

void Relogio::acertar(int h, int m, int s)
{
    horas = 0;
    if (h > 0 && h <= 23)
        horas = h;
    minutos = 0;
    if (m > 0 && m <= 59)
        minutos = m;
    segundos = 0;
    if (s > 0 && s <= 59)
        segundos = s;
}
int Relogio::getHora()
{
    return horas;
}
int Relogio::getMinuto()
{
    return minutos;
}
int Relogio::getSegundo()
{
    return segundos;
}
void Relogio::tique()
{
    segundos++;
    if(segundos >= 60)
    {
        minutos++;
        segundos = 0;
    }
    if(minutos >= 60)
    {
        horas++;
        minutos = 0;
    }
    if(horas > 23)
    {
        horas = 0;
    }
}

void Relogio::imprime()
{
    cout << "Hora: " << horas << ":" << minutos << ":" << segundos << endl;
}
