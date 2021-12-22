#include <iostream>
#include "MatrizDiag.h"

using namespace std;

int main()
{
    MatrizDiag mat(5);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(i == j)
                mat.set(i, j, i*2+j+1);
            else
                mat.set(i, j, 0);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << mat.get(i,j) << " ";
        cout << endl;
    }

    return 0;
}
