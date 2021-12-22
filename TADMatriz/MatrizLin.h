#ifndef MATRIZLIN_H_INCLUDED
#define MATRIZLIN_H_INCLUDED

class MatrizLin
{
public:
    MatrizLin(int m, int n);
    ~MatrizLin();
    float get(int i, int j);
    void set(int i, int j, float val);
private:
    int nl, nc;
    float *vet;
    int detInd(int i, int j);
};

#endif // MATRIZLIN_H_INCLUDED
