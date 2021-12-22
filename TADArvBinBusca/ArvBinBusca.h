#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
private:
    NoArv *raiz; // ponteiro para o nó raiz da árvore
    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int ch);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* removeFolha(NoArv *p);
    NoArv* removeNo1Filho(NoArv *p);
    NoArv* menorSubArvDireita(NoArv *p);
    NoArv* maiorSubArvEsquerda(NoArv *p);
    void auxImprime(NoArv *p, int nivel);
    int auxMin(NoArv *p);
    NoArv* auxRemoveMin(NoArv *p);
    int auxContaNos(NoArv *p);
    int auxAltura(NoArv *p);
    void auxBalanceada2(NoArv *p, int *cont, int *h, int nivel);
    bool auxEhABB(NoArv *p);

public:
    ArvBinBusca();
    ~ArvBinBusca();
    int getRaiz();
    bool vazia();
    bool busca(int val);
    bool buscaIt(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    int minimo();
    int minimoIt();
    void removeMin();
    bool balanceada();
    bool balanceada2();
    int contaNos();
    int altura();
    bool ehABB();
};

#endif // ARVBINBUSCA_H_INCLUDED
