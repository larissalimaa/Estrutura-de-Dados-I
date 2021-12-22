#ifndef LISTAORDENCAD_H_INCLUDED
#define LISTAORDENCAD_H_INCLUDED
#include "No.h"

class ListaOrdEncad
{
public:
    ListaOrdEncad();
    ~ListaOrdEncad();
    void insere(int val);
    void remove(int val);
    bool busca(int val);
    void imprime();
private:
    No *primeiro; // ponteiro para o primeiro
};

#endif // LISTAORDENCAD_H_INCLUDED
