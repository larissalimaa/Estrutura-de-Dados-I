#include <iostream>
#include <cstdlib>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    inicio = fim = NULL;
}
FilaEncad::~FilaEncad()
{
    No *p = inicio;
    while(p != NULL)
    {
        No *t = p;
        p = p->getProx();
        delete t;
    }

}
int FilaEncad::getInicio()
{
    if(inicio != NULL)
        return inicio->getInfo();
    else
    {
        cout << "Fila vazia" << endl;
        exit(1);
    }

}
void FilaEncad::enfileira(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(fim != NULL) //inicio != NULL
        fim->setProx(p);
    else
        inicio = p;
    fim = p;
}
int FilaEncad::desenfileira()
{
    if(inicio != NULL)
    {
        No *p = inicio;
        inicio = p->getProx();
        if(inicio == NULL) fim = NULL;
        int val = p->getInfo();
        delete p;
        return val;
    }
    else
    {
        cout << "Fila vazia" << endl;
        exit(1);
    }

}
bool FilaEncad::vazia()
{
    return inicio == NULL;
}
void FilaEncad::imprime()
{
    cout << "Fila: ";
    for(No *p = inicio; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}
