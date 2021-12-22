#include <iostream>
#include "ListaCirc.h"

using namespace std;

ListaCirc::ListaCirc()
{
    primeiro = ultimo = NULL;
    n = 0;
}

ListaCirc::~ListaCirc()
{
    NoDuplo *p = primeiro;
    while(p != ultimo)
    {
        NoDuplo *t = p;
        p = p->getProx();
        delete t;
    }
    delete ultimo;
}

void ListaCirc::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    if(n == 0)
    {
        p->setProx(p);
        p->setAnt(p);
        ultimo = p;
    }
    else
    {
        p->setProx(primeiro);
        p->setAnt(ultimo);
        primeiro->setAnt(p);
        ultimo->setProx(p);
    }
    primeiro = p;
    n++;
}

void ListaCirc::removeInicio()
{
    if(primeiro != NULL)
    {
        NoDuplo *p = primeiro;
        primeiro = p->getProx();
        delete p;
        if(n == 1) // lista vai ficar vazia
            primeiro = ultimo = NULL;
        else
        {
            primeiro->setAnt(ultimo);
            ultimo->setProx(primeiro);
        }
        n--;
    }
    else
        cout << "Lista vazia" << endl;
}

void ListaCirc::imprime()
{
    cout << "Lista: ";
//    for(NoDuplo *p = primeiro; p != ultimo; p = p->getProx())
    NoDuplo *p = primeiro;
    for(int i = 0; i < n; i++, p = p->getProx())
        cout << p->getInfo() << " ";
//    if(ultimo != NULL)
//        cout << ultimo->getInfo();
    cout << endl;
}
