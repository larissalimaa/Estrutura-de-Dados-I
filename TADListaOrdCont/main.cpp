#include <iostream>
#include "ListaOrdCont.h"

using namespace std;

int main()
{
    ListaOrdCont l(10), l2(10), *l3;
    l.insere(5);
    l.insere(7);
    l.insere(1);
    l.insere(9);
    l.insere(3);
    l.insere(13);
    l.insere(11);
    l.insere(15);
    l.imprime();

    l2.insere(4);
    l2.insere(2);
    l2.insere(8);
    l2.insere(6);
    l2.imprime();

    l3 = l.intercala(&l2);
    l3->imprime();
    delete l3;

    return 0;
}
