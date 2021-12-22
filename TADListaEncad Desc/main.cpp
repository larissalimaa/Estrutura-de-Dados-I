#include <iostream>
#include "ListaEncad.h"

using namespace std;

int main()
{
    ListaEncad l;
    l.insereFinal(0);
    l.insereInicio(1);
    l.insereInicio(2);
    l.insereInicio(3);
    l.insereFinal(4);
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    l.removeInicio();
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    l.removeFinal();
    l.insereInicio(3);
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    l.insereK(2, 10);
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    l.insereK(5, 10);
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    l.insereK(0, 10);
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    l.insereDepoisX(1, 20);
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    l.insereFinal(30);
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    l.insereDepoisX(30, 100);
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    l.removeFinal();
    l.imprime();
    cout << "Nos: " << l.contaNos() << endl;
    cout << "Maior: " << l.maiorNo() << endl;
    return 0;
}
