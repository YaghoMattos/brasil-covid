#ifndef NOAVL_H_INCLUDED
#define NOAVL_H_INCLUDED

#include <iostream>

using namespace std;

class NoAVL
{
public:
    NoAVL(int valor);
    ~NoAVL();

    void setSubArvores(int n, NoAVL *p);
    void setBalanceamento(int n);
    int getBalanceamento();
    int getAltura();
    void atualizaAltura(int k);
    int getValor();
    NoAVL *getSubArvores(int n); // 0  - ESQ
                                 // 1  - DIR
                                 // 2 - Igual
private:
    int balanceamento;
    int altura;
    int valor;

    NoAVL *subArvoreEsquerda;
    NoAVL *subArvoreDireita;
};

#endif // NOAVL_H_INCLUDED