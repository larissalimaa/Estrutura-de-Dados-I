#include <iostream>
#include "ListaCont.h"

using namespace std;

int main()
{
    ListaCont l(10);

    l.removeInicio();

    l.insereInicio(10);

    for(int i = 1; i <= 7; i++)
        l.insereFinal(i);
    l.imprime();

    l.insereInicio2(10);
    l.imprime();
    l.insereInicio(10);
    l.imprime();
    l.insereFinal(7);
    l.imprime();
    l.removeInicio();
    l.imprime();
    l.removeK(0);
    l.imprime();

    return 0;
}
