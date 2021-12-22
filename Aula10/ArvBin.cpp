#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Árvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

int ArvBin::auxNNos( NoArv *p ) {
    if (p == NULL) {
        return 0;
    } else {
        return 1 + auxNNos( p->getEsq() ) +
            auxNNos( p->getDir() );
    }
}

int ArvBin::nNos() {
    return auxNNos( raiz );
}

int ArvBin::auxSomaValores( NoArv *p ) {
    if (p == NULL) {
        return 0;
    } else {
        return p->getInfo() + auxSomaValores( p->getEsq() ) +
            auxSomaValores( p->getDir() );
    }
}

int ArvBin::somaValores() {
    return auxSomaValores( raiz );
}

//float ArvBin::mediaNos() {
//    int nNos = 0;
//    float somaNos = 0;
//    auxContaSomaNos(raiz, &somaNos, &nNos);
//    return somaNos/(float) nNos;
//
//}
//
//void ArvBin::auxContaSomaNos( NoArv *p, int *somaNos, int *nNos ) {
//    if (p!=NULL) {
//        *nNos = *nNos + 1;
//        *somaNos = *somaNos + p->getInfo();
//        auxContaSomaNos(p->getEsq(), somaNos, nNos);
//        auxContaSomaNos(p->getDir(), somaNos, nNos);
//    }
//}

int ArvBin::auxNFolhas( NoArv *p ) {
    if (p==NULL) {
        return 0;
    } else {
        if ( p->getEsq()==NULL && p->getDir() == NULL ) {
            return 1;
        } else {
            return auxNFolhas(p->getEsq()) +
                    auxNFolhas(p->getDir());
        }
    }
}

int ArvBin::nFolhas() {
    return auxNFolhas( raiz );
}

bool ArvBin::ehCheia() {
    int n = 0;
    int altura = auxAlturaContaNos(raiz, &n);
    return pow(2, altura+1)-1 == n;
}

int ArvBin::auxAlturaContaNos( NoArv *p, int *n ) {


    if (p!=NULL) {
        *n = *n + 1;
        int he = auxAlturaContaNos(p->getEsq(), n);
        int hd = auxAlturaContaNos(p->getDir(), n);
        if ( he > hd ) {
            return he + 1;
        } else {
            return hd + 1;
        }
    } else {
        return -1;
    }

}

void ArvBin::removeFolhas() {
    if ( !vazia() ) {
        if ( auxRemoveFolha(raiz) ) {
            delete raiz;
            raiz = NULL;
        }
    }
}

bool ArvBin::auxRemoveFolha( NoArv *p ) {
    if (p == NULL ) {
        return false;
    } else if ( p->getEsq() == NULL && p->getDir() == NULL ) {
        return true;
    } else {
        if ( auxRemoveFolha(p->getEsq()) ) {
            delete p->getEsq();
            p->setEsq(NULL);
        }

        if ( auxRemoveFolha(p->getDir()) ) {
            delete p->getDir();
            p->setDir(NULL);
        }
        return false;
    }
}

bool ArvBin::ehABB()
{
    return auxEhABB(raiz);
}

int ArvBin::minSubArvore(NoArv *p) // chamar pra subárvore não nula
{
    if(p->getEsq() == NULL && p->getDir() == NULL)
        return p->getInfo();
    int menorSub;
    if(p->getEsq() == NULL)
        menorSub = minSubArvore(p->getDir());
    else if(p->getDir() == NULL)
        menorSub = minSubArvore(p->getEsq());
    else // 2 filhos
    {
        int minE = minSubArvore(p->getEsq());
        int minD = minSubArvore(p->getDir());
        if(minE < minD)
            menorSub = minE;
        else
            menorSub = minD;
    }
    if(p->getInfo() < menorSub)
        return p->getInfo();
    else
        return menorSub;
}

int ArvBin::maxSubArvore(NoArv *p)
{
    if(p->getEsq() == NULL && p->getDir() == NULL)
        return p->getInfo();
    int maiorSub;
    if(p->getEsq() == NULL)
        maiorSub = maxSubArvore(p->getDir());
    else if(p->getDir() == NULL)
        maiorSub = maxSubArvore(p->getEsq());
    else // 2 filhos
    {
        int maxE = maxSubArvore(p->getEsq());
        int maxD = maxSubArvore(p->getDir());
        if(maxE > maxD)
            maiorSub = maxE;
        else
            maiorSub = maxD;
    }
    if(p->getInfo() > maiorSub)
        return p->getInfo();
    else
        return maiorSub;
}

bool ArvBin::auxEhABB(NoArv *p)
{
    if(p != NULL)
    {
        if(p->getEsq() != NULL && p->getInfo() < maxSubArvore(p->getEsq()))
            return false;
        if(p->getDir() != NULL && p->getInfo() > minSubArvore(p->getDir()))
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

int ArvBin::min()
{
    if(raiz == NULL)
    {
        cout << "Arvore vazia" << endl;
        exit(1);
    }
    int menor = raiz->getInfo();
    auxMin(raiz, &menor);
    return menor;
}

void ArvBin::auxMin(NoArv *p, int *menor)
{
    if(p != NULL)
    {
        if(p->getInfo() < *menor)
            *menor = p->getInfo();
        auxMin(p->getEsq(), menor);
        auxMin(p->getDir(), menor);
    }
}
