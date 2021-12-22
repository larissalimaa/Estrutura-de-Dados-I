#ifndef LISTACIRC_H_INCLUDED
#define LISTACIRC_H_INCLUDED
#include "NoDuplo.h"

class ListaCirc
{
public:
    ListaCirc();
    ~ListaCirc();
    bool busca(int val);
    void insereInicio(int val);
    void removeInicio();
    void imprime();
private:
    NoDuplo *primeiro;
    int n;
    NoDuplo *ultimo;
};

#endif // LISTACIRC_H_INCLUDED
