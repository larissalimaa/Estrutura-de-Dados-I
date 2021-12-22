#ifndef LISTAORDCONT_H_INCLUDED
#define LISTAORDCONT_H_INCLUDED

class ListaOrdCont
{
public:
    ListaOrdCont(int tam);
    ~ListaOrdCont();
    int get(int k);
    void insere(int val); // insere na ordem
    void remove(int val); // remove no
    void imprime();
    bool busca(int val);
    ListaOrdCont* intercala(ListaOrdCont *l2);
private:
    int max; // capacidade maxima de
    int n; // quantidade de nos na
    int *vet; // vetor que armazena a
    int buscaBinaria(int val);
};

#endif // LISTAORDCONT_H_INCLUDED
