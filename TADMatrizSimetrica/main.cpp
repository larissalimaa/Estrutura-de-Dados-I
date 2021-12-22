#include <iostream>
#include "MatrizSimetrica.h"

using namespace std;

int main()
{
    MatrizSimetrica mat(5);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
           // if(i >= j)
                mat.set(j,i, i+j);
           // else
             //mat.set(i,j, 0);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << mat.get(i,j) << " ";
        cout << endl;
    }

    return 0;
}
