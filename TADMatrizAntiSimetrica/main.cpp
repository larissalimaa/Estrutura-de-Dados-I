#include <iostream>
#include "MatrizAntiSimetrica.h"

using namespace std;

int main()
{
    MatrizAntiSimetrica mat(5);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
                mat.set(i, j, i+j);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << mat.get(i,j) << " ";
        cout << endl;
    }

    return 0;
}
