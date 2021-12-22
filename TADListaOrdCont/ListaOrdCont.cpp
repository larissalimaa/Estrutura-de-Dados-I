#include <iostream>
#include <cstdlib>
#include "ListaOrdCont.h"

using namespace std;

ListaOrdCont::ListaOrdCont(int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}
ListaOrdCont::~ListaOrdCont()
{
    delete [] vet;
}
int ListaOrdCont::get(int k)
{
    if(k >= 0 && k < n)
        return vet[k];
    else
    {
        cout << "Indice invalido" << endl;
        exit(1);
    }
}
void ListaOrdCont::insere(int val)
{
    int i;
    if(n == max)
        cout << "Vetor Cheio!" << endl;
    for(i = n-1; i >= 0 && vet[i] >= val; i--)
        vet[i+1] = vet[i];
    vet[i+1] = val;
    n++;
}
void ListaOrdCont::remove(int val)
{
    int k = buscaBinaria(val); // busca indice
    if (k >= 0 && k < n)
    {
        for(int i = k; i < n-1; i++) // copia da dir. para esq.
            vet[i] = vet[i+1];
        n--;
    }
    else
        cout << "Valor " << val << " nao existe na lista" << endl;
}
void ListaOrdCont::imprime()
{
    cout << "Lista: ";
    for(int i = 0; i < n; i++)
        cout << vet[i] << " ";
    cout << endl;
}
bool ListaOrdCont::busca(int val)
{
    int k = buscaBinaria(val);
    // retorna true, se k eh um indice valido
    // returna false, caso contrario
    return k >= 0 && k < n;
}
int ListaOrdCont::buscaBinaria(int val)
{
    int esq = 0;
    int dir = n-1;
    while(esq <= dir)
    {
        int meio = (esq + dir) / 2;
        if(val > vet[meio]) // se existir, val esta na segunda metade
            esq = meio + 1;
        else if (val < vet[meio]) // se existir, val esta na primeira metade
            dir = meio - 1;
        else
            return meio; // val na posicao meio
    }
    return -1; // val nao encontrado
}

ListaOrdCont* ListaOrdCont::intercala(ListaOrdCont *l2)
{
    ListaOrdCont *nova = new ListaOrdCont(max+l2->max);
    int i = 0, j = 0, k = 0;
    while(i < n && j < l2->n)
    {
        if(vet[i] < l2->vet[j])
            nova->vet[k++] = vet[i++];
        else
            nova->vet[k++] = l2->vet[j++];
    }
    while(i < n)
        nova->vet[k++] = vet[i++];
    while(j < l2->n)
        nova->vet[k++] = l2->vet[j++];
    nova->n = n + l2->n;
    return nova;
}
