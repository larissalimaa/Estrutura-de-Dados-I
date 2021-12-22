#include <iostream>
#include <cstdlib>
#include "Matriz2D.h"

using namespace std;

Matriz2D::Matriz2D(int nnl, int nnc)
{
    nl = nnl;
    nc = nnc;
    mat = new float*[nl];
    for(int i = 0; i < nl; i++)
        mat[i] = new float[nc];
}
Matriz2D::~Matriz2D()
{
    for(int i = 0; i < nl; i++)
        delete mat[i];
    delete [] mat;
}
bool Matriz2D::verifica(int i, int j)
{
    if(i >= 0 && i < nl && j >= 0 && j < nc)
        return true;
    else
        return false;
}
float Matriz2D::get(int i, int j)
{
    if(verifica(i,j))
        return mat[i][j];
    else
    {
        cout << "Indices invalidos" << endl;
        exit(1);
    }
}
void Matriz2D::set(int i, int j, float valor)
{
    if(verifica(i,j))
        mat[i][j] = valor;
    else
        cout << "Indices invalidos" << endl;
}
