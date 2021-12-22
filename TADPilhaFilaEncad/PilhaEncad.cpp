#include <iostream>
#include <cstdlib>
#include "PilhaEncad.h"

using namespace std;

PilhaEncad::PilhaEncad()
{
    topo = NULL;
}
PilhaEncad::~PilhaEncad()
{
    No *p = topo;
    while(p != NULL)
    {
        No *t = p;
        p = p->getProx();
        delete t;
    }
}
int PilhaEncad::getTopo()
{
    if(topo != NULL)
        return topo->getInfo();
    else
    {
        cout << "Pilha vazia" << endl;
        exit(1);
    }
}
void PilhaEncad::empilha(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(topo);
    topo = p;
}
int PilhaEncad::desempilha()
{
    if(topo != NULL)
    {
        No *p = topo;
        topo = p->getProx();
        int val = p->getInfo();
        delete p;
        return val;
    }
    else
    {
        cout << "Pilha vazia" << endl;
        exit(1);
    }
}
bool PilhaEncad::vazia()
{
    return topo == NULL;
}
void PilhaEncad::imprime()
{
    cout << "Pilha: " << endl;
    for(No *p = topo; p != NULL; p = p->getProx())
        cout << p->getInfo() << endl;
}
