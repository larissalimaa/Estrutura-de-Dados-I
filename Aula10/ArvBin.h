#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    int nNos();
    int somaValores();
    float mediaNos();
    int nFolhas();
    bool ehCheia();
    void removeFolhas();
    bool ehABB();
    int min();

  private:
    NoArv *raiz; // ponteiro para o No raiz da árvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    NoArv* auxInsere(NoArv *p, int x);
    int auxNNos( NoArv *p );
    int auxSomaValores( NoArv *p );
    //void auxContaSomaNos( NoArv *p, int *somaNos, int *nNos );
    int auxNFolhas( NoArv *p );
    int auxAlturaContaNos( NoArv *p, int *nNos );
    bool auxRemoveFolha( NoArv *p );
    bool auxEhABB(NoArv *p);
    int minSubArvore(NoArv *p);
    int maxSubArvore(NoArv *p);
    void auxMin(NoArv *p, int *menor);
};

#endif // ARVBIN_H_INCLUDED
