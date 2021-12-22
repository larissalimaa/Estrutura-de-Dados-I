#include <iostream>
#include <cstdlib>
#include "MatrizAntiSimetrica.h"

using namespace std;

MatrizAntiSimetrica::MatrizAntiSimetrica(int ordem)
{
    n = ordem;
    int tam = n*(n - 1)/2;
    vet = new float[tam];
}

MatrizAntiSimetrica::~MatrizAntiSimetrica()
{
    delete [] vet;
}

bool MatrizAntiSimetrica::verifica(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < n)
        return true;
    else
        return false;
}

float MatrizAntiSimetrica::get(int i, int j)
{
    if(verifica(i, j))
    {
        if(i == j)
            return 0.0;
        if(i >= j)
        {
            int k = i*(i - 1)/2 + j;
            return vet[k];
        }
        else
        {
            int k = j*(j - 1)/2 + i;
            return -vet[k];
        }
    }
    else
    {
        cout << "Erro: indice invalido\n";
        exit(1);
    }
}

void MatrizAntiSimetrica::set(int i, int j, float val)
{
    if(verifica(i, j))
    {
        if(i == j)
        {
            if(val != 0)
                cout << "Valor diferente de zero" << endl;
        }
        if(i >= j)
        {
            int k = i*(i - 1)/2 + j;
            vet[k] = val;
        }
        else
        {
            int k = j*(j - 1)/2 + i;
            vet[k] = -val;
        }
    }
    else
        cout << "Erro: indices invalidos\n";
}
