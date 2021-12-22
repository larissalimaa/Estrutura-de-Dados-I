#ifndef VETORFLEXIVEL_H_INCLUDED
#define VETORFLEXIVEL_H_INCLUDED

class VetorFlexivel
{
private:
    int n;
    float *vet;
    int c, f;
    int detInd(int indice);
public:
    VetorFlexivel(int a, int b);
    ~VetorFlexivel();
    float get(int indice);
    void set(int indice, float valor);
};

#endif // VETORFLEXIVEL_H_INCLUDED
