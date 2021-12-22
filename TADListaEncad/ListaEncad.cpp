#include <iostream>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
    primeiro = NULL;
}

ListaEncad::~ListaEncad()
{
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p;
        p = p->getProx();
        delete t;
    }
}

void ListaEncad::insereInicio(int val)
{
    No *p = new No(); //No *p = new No(val, primeiro);
    p->setInfo(val);
    p->setProx(primeiro);
    primeiro = p;
}

void ListaEncad::insereFinal(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(primeiro != NULL)
    {
        No *ult = primeiro;
        while(ult->getProx() != NULL)
            ult = ult->getProx();
        ult->setProx(p);
    }
    else
        primeiro = p;
}

void ListaEncad::insereK(int k, int val)
{
    if(k == 0)
    {
        if(primeiro == NULL)
            cout << "Indice invalido - lista vazia" << endl;
        else
            insereInicio(val);
    }
    else
    {
        No *p = primeiro, *ant = NULL;
        int cont = 0;
        while(p != NULL)
        {
            ant = p;
            p = p->getProx();
            cont++;
            if(cont == k)
                break;
        }
        if(p == NULL)
        {
            if(cont == k) // alternativa
                insereFinal(val);
            else
                cout << "Indice invalido" << endl;
        }
        else
        {
            No *novo = new No();
            novo->setInfo(val);
            novo->setProx(p);
            ant->setProx(novo);
        }
    }
}


void ListaEncad::removeInicio()
{
    if(primeiro != NULL)
    {
        No *p = primeiro;
        primeiro = p->getProx();
        delete p;
    }
    else
        cout << "Lista vazia" << endl;
}

void ListaEncad::removeFinal()
{
    if(primeiro != NULL)
    {
        No *ant = NULL, *ult = primeiro;
        while(ult->getProx() != NULL)
        {
            ant = ult;
            ult = ult->getProx();
        }
        if(ant == NULL) // só tem um nó
            primeiro = NULL;
        else
            ant->setProx(NULL);
        delete ult;
    }
    else
        cout << "Lista vazia" << endl;
}

bool ListaEncad::busca(int val)
{
    No *p = primeiro;
    while(p != NULL)
    {
        if(p->getInfo() == val)
            return true;
        p = p->getProx();
    }
    return false;
}

void ListaEncad::imprime()
{
    cout << "Lista: ";
    for(No *p = primeiro; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}

int ListaEncad::contaNos()
{
    int cont = 0;
    for(No *p = primeiro; p != NULL; p = p->getProx())
        cont++;
    return cont;
}
