#ifndef MATRIZSIMETRICA_H_INCLUDED
#define MATRIZSIMETRICA_H_INCLUDED

class MatrizSimetrica
{
public:
    MatrizSimetrica(int ordem);
    ~MatrizSimetrica();
    float get(int i, int j);
    void set(int i, int j, float val);
private:
    int n;
    float *vet;
    bool verifica(int i, int j);
};

#endif // MATRIZSIMETRICA_H_INCLUDED
