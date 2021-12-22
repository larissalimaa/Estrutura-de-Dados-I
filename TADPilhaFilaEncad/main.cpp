#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

using namespace std;

void inverteFila(FilaEncad *f)
{
    PilhaEncad p;
    while(!f->vazia())
        p.empilha(f->desenfileira());
    while(!p.vazia())
        f->enfileira(p.desempilha());
}

int main()
{
//    PilhaEncad p;
//    for(int i = 1; i <= 9; i++)
//        p.empilha(i);
//    p.imprime();
//    cout << "Desempilhou: " << p.desempilha() << endl;
//    p.empilha(18);
//    p.imprime();

    FilaEncad f;
    for(int i = 1; i <= 9; i++)
        f.enfileira(i);
    f.imprime();
    inverteFila(&f);
    f.imprime();

    return 0;
}
