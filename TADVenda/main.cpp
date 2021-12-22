#include <iostream>
#include "Venda.h"

using namespace std;

int main()
{
    Venda v(5);
    cout << v.calculaTotal() << endl;
    cout << v.itemMaisCaro() << endl;

    return 0;
}
