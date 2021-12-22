#include <iostream>
#include "Relogio.h"

using namespace std;

int main()
{
    Relogio r(99,99,99);

    r.acertar(16,59,55);
    r.imprime();

    r.tique();
    r.imprime();

    r.tique();
    r.imprime();

    r.tique();
    r.imprime();

    r.tique();
    r.imprime();

    r.tique();
    r.imprime();

    return 0;
}
