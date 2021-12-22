#include <iostream>
#include <cstdlib>
#include "VetorFlexivel.h"

using namespace std;

VetorFlexivel::VetorFlexivel(int a, int b)
{
    c = a;
    f = b;
    n = f - c + 1;
    if(n > 0)
        vet = new float[n];
    else
    {
        cout << "Valores invalidos" << endl;
        exit(1);
    }
}

VetorFlexivel::~VetorFlexivel()
{
    delete [] vet;
}

int VetorFlexivel::detInd(int indice)
{
    if(indice >= c && indice <= f)
        return indice - c;
    else
        return -1;
}

float VetorFlexivel::get(int indice)
{
    int k = detInd(indice);
    if(k == -1)
    {
        cout << "Indice invalido";
        exit(1);
    }
    else
        return vet[k];
}

void VetorFlexivel::set(int indice, float valor)
{
    int k = detInd(indice);
    if(k == -1)
        cout << "Indice invalido";
    else
        vet[k] = valor;
}
