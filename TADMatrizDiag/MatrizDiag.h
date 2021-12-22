#ifndef MATRIZDIAG_H_INCLUDED
#define MATRIZDIAG_H_INCLUDED

class MatrizDiag
{
public:
    MatrizDiag(int dim);
    ~MatrizDiag();
    float get(int i, int j);
    void set(int i, int j, float val);
private:
    int n;
    float *vet;
    int detInd(int i, int j);
};

#endif // MATRIZDIAG_H_INCLUDED
