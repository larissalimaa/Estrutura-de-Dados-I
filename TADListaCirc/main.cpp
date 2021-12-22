#include <iostream>
#include "ListaCirc.h"

using namespace std;

int main()
{
    ListaCirc l;
    l.insereInicio(1);
    l.insereInicio(2);
    l.insereInicio(3);
    l.imprime();
    l.removeInicio();
    l.imprime();
    l.removeInicio();
    l.imprime();
    l.removeInicio();
    l.imprime();
    l.removeInicio();
    l.imprime();
    return 0;
}
