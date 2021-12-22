#include <iostream>
#include "PilhaCont.h"
#include "FilaCont.h"

using namespace std;

bool ehPalindromo(int n, PilhaCont *p)
{
    PilhaCont aux(10);
    for(int i = 0; i < n/2; i++)
        aux.empilha(p->desempilha());
    if(n%2 == 1)
        p->desempilha(); //impar
    while(!p->vazia())
        if(p->desempilha() != aux.desempilha())
            return false;
    return true;
}

int main()
{
    PilhaCont p(10), p2(10);
    for(int i = 1; i <= 9; i++)
        p.empilha(i);
    p.imprime();

    p2.empilha(1);
    p2.empilha(3);
    p2.empilha(2);
    p2.empilha(3);
    p2.empilha(1);
    p2.imprime();

    cout << ehPalindromo(9, &p) << endl;
    cout << ehPalindromo(5, &p2) << endl;

    cout << endl << endl;

//    FilaCont f(10);
//    for(int i = 1; i <= 9; i++)
//        f.enfileira(i);
//    f.imprime();
//    cout << "Desenfileirou: " << f.desenfileira() << endl;
//    f.imprime();

    return 0;
}
