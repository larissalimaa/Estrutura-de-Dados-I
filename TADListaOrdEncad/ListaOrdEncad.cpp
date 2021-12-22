#include <iostream>
#include "ListaOrdEncad.h"

using namespace std;

ListaOrdEncad::ListaOrdEncad()
{
    primeiro = NULL;
}
ListaOrdEncad::~ListaOrdEncad()
{
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}
void ListaOrdEncad::insere(int val)
{
    No *p = new No();
    No *ant = NULL, *atual;
    p->setInfo(val);
    for(atual = primeiro; atual != NULL; atual = atual->getProx())
    {
        if(atual->getInfo() > val)
            break;
        ant = atual;
    }
    if(ant == NULL) // atual == primeiro
        primeiro = p;
    else
        ant->setProx(p);
    p->setProx(atual);
}
void ListaOrdEncad::remove(int val)
{
    if(primeiro != NULL)
    {
        No *ant = NULL, *p;
        for(p = primeiro; p != NULL; p = p->getProx())
        {
            if(p->getInfo() == val)
                break;
            ant = p;
        }
        if(p == NULL)
            cout << "Valor " << val << " nao existe na lista" << endl;
        else
        {
            if(ant == NULL) // p == primeiro
                primeiro = p->getProx();
            else
                ant->setProx(p->getProx());
            delete p;
        }
    }
    else
        cout << "Lista vazia" << endl;
}
bool ListaOrdEncad::busca(int val)
{
    for(No *p = primeiro; p != NULL; p = p->getProx())
    {
        if(p->getInfo() == val)
            return true;
        else if(p->getInfo() > val)
            return false;
    }
    return false;
}
void ListaOrdEncad::imprime()
{
    cout << "Lista: ";
    for(No *p = primeiro; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}
