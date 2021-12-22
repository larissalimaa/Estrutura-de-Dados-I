#include <iostream>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = ultimo = NULL;
    n = 0;
}
ListaDupla::~ListaDupla()
{
    NoDuplo *p = primeiro; // p = ultimo;
    while(p != NULL)
    {
        NoDuplo *t = p;
        p = p->getProx(); //p = p->getAnt();
        delete t;
    }
}
bool ListaDupla::busca(int val)
{
    for(NoDuplo *p = primeiro; p != NULL; p = p->getProx())
    //for(NoDuplo *p = ultimo; p != NULL; p = p->getAnt())
        if(p->getInfo() == val)
            return true;
    return false;
}
void ListaDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(primeiro);
    p->setAnt(NULL);
    if(ultimo == NULL) //primeiro == NULL
        ultimo = p;
    else
        primeiro->setAnt(p);
    primeiro = p;
    n++;
}
void ListaDupla::removeInicio()
{
    if(primeiro != NULL)
    {
        NoDuplo *p = primeiro;
        primeiro = p->getProx();
        delete p;
        if(primeiro == NULL)
            ultimo = NULL; //lista vazia
        else
            primeiro->setAnt(NULL);
        n--;
    }
    else
        cout << "Lista vazia" << endl;
}
void ListaDupla::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);
    if(primeiro == NULL)
        primeiro = p;
    else
        ultimo->setProx(p);
    ultimo = p;
    n++;

}
void ListaDupla::removeFinal()
{
    if(primeiro != NULL)
    {
        NoDuplo *p = ultimo;
        ultimo = p->getAnt();
        delete p;
        if(ultimo == NULL)
            primeiro = NULL; //lista vazia
        else
            ultimo->setProx(NULL);
        n--;
    }
    else
        cout << "Lista vazia" << endl;
}

void ListaDupla::imprime()
{
    cout << "Lista: ";
    for(NoDuplo *p = primeiro; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout  << endl;
}

void ListaDupla::imprimeReverso()
{
    cout << "Lista Reversa: ";
    for(NoDuplo *p = ultimo; p != NULL; p = p->getAnt())
        cout << p->getInfo() << " ";
    cout  << endl;
}
