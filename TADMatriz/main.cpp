#include <iostream>
#include "Matriz2D.h"
#include "MatrizLin.h"

using namespace std;

int main()
{
    //Matriz2D mat(5,5);
    MatrizLin mat(5,5);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            mat.set(i,j, i+j+1);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << mat.get(i,j) << " ";
        cout << endl;
    }

    return 0;
}
