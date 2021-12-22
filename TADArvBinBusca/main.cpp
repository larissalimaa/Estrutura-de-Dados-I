#include <iostream>
#include "ArvBinBusca.h"
using namespace std;

int main()
{
    ArvBinBusca a;

    a.insere(15);
    a.insere(12);
    a.insere(10);
    a.insere(13);
    a.insere(5);
    a.insere(20);
    a.insere(18);
    a.insere(30);
    a.insere(25);
    a.insere(22);
    a.insere(21);
    a.insere(28);
    a.insere(40);
    a.imprime();
    a.insere(14);
    a.imprime();
    cout << "Menor: " << a.minimo() << endl;
    cout << "Menor It: " << a.minimoIt() << endl;
    a.removeMin();
    a.imprime();
    a.remove(10);
    a.imprime();
    a.remove(13);
    a.imprime();
    a.remove(20);
    a.imprime();
    a.remove(15);
    a.imprime();
    a.remove(25);
    a.imprime();
    cout << "Nos: " << a.contaNos() << endl;
    cout << "Altura: " << a.altura() << endl;
    cout << "Balanceada: " << a.balanceada() << endl;
    cout << "Balanceada2: " << a.balanceada2() << endl;
    cout << "EhABB: " << a.ehABB() << endl;

    ArvBinBusca a2;
    a2.insere(15);
    a2.insere(10);
    a2.insere(30);
    a2.imprime();
    cout << "Nos: " << a2.contaNos() << endl;
    cout << "Altura: " << a2.altura() << endl;
    cout << "Balanceada: " << a2.balanceada() << endl;
    cout << "Balanceada2: " << a2.balanceada2() << endl;
    cout << "EhABB: " << a2.ehABB() << endl;
    return 0;
}
