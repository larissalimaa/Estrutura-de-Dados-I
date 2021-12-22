#ifndef LISTACONT_H_INCLUDED
#define LISTACONT_H_INCLUDED

class ListaCont
{
public:
    ListaCont(int tam);
    ~ListaCont();
    int get(int k);
    void set(int k, int val);
    void insereFinal(int val);
    void removeFinal();
    void insereK(int k, int val);
    void removeK(int k);
    void insereInicio(int val);
    void insereInicio2(int val);
    void removeInicio();
    void removeInicio2();
    void imprime();
private:
    int max;
    int n;
    int *vet;
};

#endif // LISTACONT_H_INCLUDED
