#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin arv;
    arv.montaArvore();
//    arv.insere(15);
//    arv.insere(25);
//    arv.insere(10);
    arv.preOrdem();
    cout << endl;

    cout << "Eh ABB: " << arv.ehABB() << endl;

    cout << "Menor: " << arv.min() << endl;

    return 0;
}
