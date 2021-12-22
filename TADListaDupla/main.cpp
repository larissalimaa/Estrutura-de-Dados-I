#include <iostream>
#include "ListaDupla.h"

using namespace std;

int main()
{
    ListaDupla l;
    for(int i = 1; i <= 10; i++)
        l.insereInicio(i);
    l.imprime();
    l.imprimeReverso();
    return 0;
}
