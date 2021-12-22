#include <iostream>
#include <cstdlib>
#include "Vetor.h"

using namespace std;

Vetor::Vetor(int tam)
{
    if(tam > 0)
    {
        n = tam;
        vet = new float[tam];
    }
    else
    {
        cout << "Tamanho invalido" << endl;
        exit(1);
    }
}

Vetor::~Vetor()
{
    delete [] vet;
}

float Vetor::get(int indice)
{
    if(verifica(indice))
        return vet[indice];
    cout << "Indice invalido" << endl;
    exit(1);
}

void Vetor::set(int indice, float valor)
{
    if(verifica(indice))
        vet[indice] = valor;
    else
        cout << "Indice invalido" << endl;
}

bool Vetor::verifica(int indice)
{
    return (indice >= 0 && indice < n);
}

void Vetor::leitura()
{
    cout << "Leitura: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Valor " << i+1 << ": ";
        cin >> vet[i];
    }
}

void Vetor::imprime()
{
    cout << "Vetor: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";
    cout << endl;
}
