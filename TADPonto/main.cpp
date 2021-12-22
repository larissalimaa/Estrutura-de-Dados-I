#include <iostream>
#include "Ponto.h"

using namespace std;

int main()
{
    Ponto p1(1,4), p2(7,5);

    cout << p1.distancia(&p2) << endl;

    return 0;
}
