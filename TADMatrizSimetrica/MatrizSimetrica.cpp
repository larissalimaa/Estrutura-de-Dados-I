#include <iostream>
#include <cstdlib>
#include "MatrizSimetrica.h"

using namespace std;

MatrizSimetrica::MatrizSimetrica(int ordem)
{
    n = ordem;
    int tam = n*(n + 1)/2;
    vet = new float[tam];
}

MatrizSimetrica::~MatrizSimetrica()
{
    delete [] vet;
}

bool MatrizSimetrica::verifica(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < n)
        return true;
    else
        return false;
}

float MatrizSimetrica::get(int i, int j)
{
    if(verifica(i, j))
    {
        if(i >= j)
        {
            int k = i*(i + 1)/2 + j;
            return vet[k];
        }
        else
        {
            int k = j*(j + 1)/2 + i;
            return vet[k];
        }
    }
    else
    {
        cout << "Erro: indice invalido\n";
        exit(1);
    }
}

void MatrizSimetrica::set(int i, int j, float val)
{
    if(verifica(i, j))
    {
        if(i >= j)
        {
            int k = i*(i + 1)/2 + j;
            vet[k] = val;
        }
        else
        {
            int k = j*(j + 1)/2 + i;
            vet[k] = val;
            //if(val != vet[k])
            //    cout << "Valor diferente do elemento correspondente\n";
        }
    }
    else
        cout << "Erro: indices invalidos\n";
}
