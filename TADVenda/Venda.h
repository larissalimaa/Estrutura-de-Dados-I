#ifndef VENDA_H_INCLUDED
#define VENDA_H_INCLUDED

class Venda {
private:
    int n;
    float *vet;
public:
    Venda(int tam);
    ~Venda();
    float calculaTotal();
    float itemMaisCaro();
};

#endif // VENDA_H_INCLUDED
