#include <iostream>
#include <cstdlib>
#include <cmath>
#include "ArvBinBusca.h"
using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}
ArvBinBusca::~ArvBinBusca()
{
    raiz = libera(raiz);
}
NoArv* ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}
int ArvBinBusca::getRaiz()
{
    if(raiz != NULL) //ou if(!vazia())
        return raiz->getInfo();
    else
    {
        cout << "Árvora vazia!" << endl;
        exit(1);
    }
}
bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}
bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}
bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false; //árvore vazia
    else if(p->getInfo() == val)
        return true; //chave encontrada
    else if(val < p->getInfo())//chave pertence SAE de p
        return auxBusca(p->getEsq(), val);
    else // val > p->getInfo(), chave pertence SAD de p
        return auxBusca(p->getDir(), val);
}
bool ArvBinBusca::buscaIt(int val)
{
    NoArv *p = raiz;
    while(p != NULL)
    {
        if(p->getInfo() == val)
            return true;
        else if(val < p->getInfo())
            p = p->getEsq();
        else
            p = p->getDir();
    }
    return false;
}
void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}
NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else
        p->setDir(auxInsere(p->getDir(), val));
    return p;
}
void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}
NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p != NULL)
    {
        if(val < p->getInfo())
            p->setEsq(auxRemove(p->getEsq(), val));
        else if(val > p->getInfo())
            p->setDir(auxRemove(p->getDir(), val));
        else // val == p->getInfo()
        {
            if(p->getEsq() == NULL && p->getDir() == NULL)
                p = removeFolha(p);
            else if(p->getEsq() == NULL || p->getDir() == NULL)
                p = removeNo1Filho(p);
            else // 2 filhos
            {
                int he = auxAltura(p->getEsq());
                int hd = auxAltura(p->getDir());
                if(he >= hd)
                {
                    NoArv *aux = maiorSubArvEsquerda(p);
                    p->setInfo(aux->getInfo());
                    aux->setInfo(val);
                    p->setEsq(auxRemove(p->getEsq(), val));
                }
                else
                {
                    NoArv *aux = menorSubArvDireita(p);
                    p->setInfo(aux->getInfo());
                    aux->setInfo(val);
                    p->setDir(auxRemove(p->getDir(), val));
                }
            }
        }
    }
    return p;
}
NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}
NoArv* ArvBinBusca::removeNo1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir(); //filho único é da direita
    else
        aux = p->getEsq(); //filho único é da esquerda
    delete p;
    return aux;
}
NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir(); //nó à direita de p
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}
NoArv* ArvBinBusca::maiorSubArvEsquerda(NoArv *p)
{
    NoArv *aux = p->getEsq(); //nó à esquerda de p
    while(aux->getDir() != NULL)
        aux = aux->getDir();
    return aux;
}
void ArvBinBusca::imprime()
{
    cout << "Arvore em pre-ordem: " << endl;
    auxImprime(raiz, 0);
    cout << endl;
}
void ArvBinBusca::auxImprime(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ") ";
        for(int i = 0; i < nivel; i++)
            cout << "--";
        cout << " " << p->getInfo() << endl;
        auxImprime(p->getEsq(), nivel+1);
        auxImprime(p->getDir(), nivel+1);
    }
}
int ArvBinBusca::minimo()
{
    if(raiz == NULL)
    {
        cout << "Árvora vazia!" << endl;
        exit(1);
    }
    return auxMin(raiz);
}
int ArvBinBusca::auxMin(NoArv *p)
{
    if(p != NULL)
    {
        if(p->getEsq() == NULL)
            return p->getInfo();
        return auxMin(p->getEsq());
    }
}
int ArvBinBusca::minimoIt()
{
    if(raiz == NULL)
    {
        cout << "Árvora vazia!" << endl;
        exit(1);
    }
    NoArv *p = raiz;
    while(p->getEsq() != NULL)
        p = p->getEsq();
    return p->getInfo();
}
void ArvBinBusca::removeMin()
{
    raiz = auxRemoveMin(raiz);
}
NoArv* ArvBinBusca::auxRemoveMin(NoArv *p)
{
    if(p != NULL)
    {
        if (p->getEsq() == NULL)
        {
            NoArv *r = p->getDir();
            delete p;
            return r;
        }
        p->setEsq(auxRemoveMin(p->getEsq()));
        return p;
    }
}

bool ArvBinBusca::balanceada()
{
    return altura() < log2(contaNos()) + 1;
}

bool ArvBinBusca::balanceada2()
{
    int cont = 0;
    int h = -1;
    auxBalanceada2(raiz, &cont, &h, 0);
    return h < log2(cont) + 1;
}
void ArvBinBusca::auxBalanceada2(NoArv *p, int *cont, int *h, int nivel)
{
    if(p != NULL)
    {
        *cont = *cont + 1;
        if(nivel > *h)
            *h = nivel;
        auxBalanceada2(p->getEsq(), cont, h, nivel+1);
        auxBalanceada2(p->getDir(), cont, h, nivel+1);
    }
}

int ArvBinBusca::contaNos()
{
    return auxContaNos(raiz);
}
int ArvBinBusca::auxContaNos(NoArv *p)
{
    if(p != NULL)
        return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
    return 0;
}

int ArvBinBusca::altura()
{
    return auxAltura(raiz);
}
int ArvBinBusca::auxAltura(NoArv *p)
{
    if(p != NULL)
    {
        int he = auxAltura(p->getEsq());
        int hd = auxAltura(p->getDir());
        if(he > hd)
            return 1 + he;
        else
            return 1 + hd;
    }
    return -1;
}

bool ArvBinBusca::ehABB()
{
    return auxEhABB(raiz);
}
bool ArvBinBusca::auxEhABB(NoArv *p) // ERRADO!
{
    if(p != NULL)
    {
        if(p->getEsq() != NULL && p->getInfo() < p->getEsq()->getInfo())
            return false;
        if(p->getDir() != NULL && p->getInfo() > p->getDir()->getInfo())
            return false;
        if(p->getEsq() == NULL && p->getDir() == NULL)
            return true;
        if(auxEhABB(p->getEsq()))
            return auxEhABB(p->getDir());
        else
            return false;
    }
    return true;
}
