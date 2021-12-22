#include <iostream>
#include "VetorFlexivel.h"

using namespace std;

int main()
{
    VetorFlexivel v(-5,6);
    for(int i = -5; i <= 6; i++)
        v.set(i, i);
    for(int i = -5; i <= 6; i++)
        cout << v.get(i) << " ";
    cout << endl;

    return 0;
}
