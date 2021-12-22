#include "Venda.h"

Venda::Venda(int tam)
{
    n = tam;
    vet = new float[tam];
    for(int i = 0; i < n; i++)
        vet[i] = i+1;
}
Venda::~Venda()
{
    delete [] vet;
}
float Venda::calculaTotal()
{
    float total = 0;
    for(int i = 0; i < n; i++)
        total += vet[i];
    return total;
}
float Venda::itemMaisCaro()
{
    float maisCaro = vet[0];
    for(int i = 0; i < n; i++)
        if(vet[i] > maisCaro)
            maisCaro = vet[i];
    return maisCaro;
}
