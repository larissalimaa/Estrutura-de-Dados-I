#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"

class ListaEncad
{
public:
    ListaEncad();
    ~ListaEncad();
    void insereInicio(int val);
    void insereFinal(int val);
    void insereK(int k, int val);
    void insereDepoisX(int x, int val);
    void removeInicio();
    void removeFinal();
    bool busca(int val);
    void imprime();
    int contaNos();
    int maiorNo();
private:
    No* primeiro; // ponteiro para o primeiro
    No* ultimo;   // ponteiro para o ultimo
    int n;        // total de nos
    int maior;    // maior no da lista
};

#endif // LISTAENCAD_H_INCLUDED
