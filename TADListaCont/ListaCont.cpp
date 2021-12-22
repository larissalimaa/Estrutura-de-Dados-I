#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont()
{
    delete [] vet;
}

void ListaCont::imprime()
{
    cout << "Lista: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";
    cout << endl;
}

int ListaCont::get(int k)
{
    if(k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "Indice invalido" << endl;
        exit(1);
    }
}

void ListaCont::set(int k, int val)
{
    if(k >= 0 && k < n)
        vet[k] = val;
    else
        cout << "Indice invalido" << endl;
}

void ListaCont::insereFinal(int val)
{
    if(n < max)
        vet[n++] = val;
    else
    {
        cout << "Lista cheia" << endl;

        //Solução para vetor cheio
        cout << "Alocando um novo vetor" << endl;
        int *temp = new int[max*2];
        for(int i = 0; i < n; i++)
            temp[i] = vet[i];
        temp[n++] = val;
        delete [] vet;
        vet = temp;
        max = max*2;
    }
}

void ListaCont::removeFinal()
{
    if(n > 0)
        n--;
    else
        cout << "Lista vazia" << endl;
}

void ListaCont::insereK(int k, int val)
{
    if(k >= 0 && k < n)
    {
        if(n < max)
        {
            for(int i = n; i > k; i--)
                vet[i] = vet[i-1];
            vet[k] = val;
            n++;
        }
        else
            cout << "Lista cheia" << endl;
    }
    else
        cout << "Indice invalido" << endl;
}

void ListaCont::removeK(int k)
{
    if(k >= 0 && k < n)
    {
        for(int i = k; i < n-1; i++)
            vet[i] = vet[i+1];
        n--;
    }
    else
        cout << "Indice invalido" << endl;
}

void ListaCont::insereInicio(int val)
{
    if(n < max)
    {
        for(int i = n; i > 0; i--)
            vet[i] = vet[i-1];
        vet[0] = val;
        n++;
    }
    else
        cout << "Lista cheia" << endl;
}
void ListaCont::insereInicio2(int val)
{
    if(n == 0)
    {
        vet[0] = val;
        n++;
    }
    else
        insereK(0, val);
}

void ListaCont::removeInicio()
{
    if(n > 0)
    {
        for(int i = 0; i < n-1; i++)
            vet[i] = vet[i+1];
        n--;
    }
    else
        cout << "Lista vazia" << endl;
}
void ListaCont::removeInicio2()
{
    if(n > 0)
        removeK(0);
    else
        cout << "Lista vazia" << endl;
}
