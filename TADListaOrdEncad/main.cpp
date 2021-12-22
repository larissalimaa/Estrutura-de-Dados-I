#include <iostream>
#include "ListaOrdEncad.h"

using namespace std;

int main()
{
    ListaOrdEncad l;
    l.insere(4);
    l.imprime();
    l.insere(1);
    l.imprime();
    l.insere(2);
    l.imprime();
    l.insere(3);
    l.imprime();
    l.insere(5);
    l.imprime();
    l.insere(0);
    l.imprime();
    l.remove(1);
    l.imprime();
    l.remove(1);
    l.imprime();
    l.remove(2);
    l.imprime();
    l.remove(3);
    l.imprime();
    l.remove(0);
    l.imprime();
    l.remove(5);
    l.imprime();
    l.remove(4);
    l.imprime();
    l.remove(0);
    l.imprime();
    return 0;
}
