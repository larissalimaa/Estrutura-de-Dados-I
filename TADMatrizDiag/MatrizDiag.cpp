#include <iostream>
#include <cstdlib>
#include "MatrizDiag.h"

using namespace std;

MatrizDiag::MatrizDiag(int dim)
{
    n = dim;
    vet = new float[n];
}

MatrizDiag::~MatrizDiag()
{
    delete [] vet;
}

int MatrizDiag::detInd(int i, int j)
{
    if(i >= 0 && i < n && j >= 0 && j < n)
    {
        if(i == j)
            return i;
        else
            return -2;
    }
    else
        return -1;
}

float MatrizDiag::get(int i, int j)
{
    int k = detInd(i,j);
    if(k == -1)
    {
        cout << "Indices invalidos" << endl;
        exit(1);
    }
    else if(k == -2)
        return 0.0;
    else
        return vet[k];
}

void MatrizDiag::set(int i, int j, float val)
{
    int k = detInd(i,j);
    if(k == -1)
        cout << "Indices invalidos" << endl;
    else if(k == -2)
    {    if(val != 0.0)
            cout << "Nao eh possivel valor diferente de zero" << endl;
    }
    else
        vet[k] = val;
}
