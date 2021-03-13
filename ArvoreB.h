#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#include <iostream>
#include "NoB.h"

using namespace std;

class ArvoreB
{
private:
    NoB *raiz; //ponteiro pra raiz
    int t;     // grau minimo

    void imprimirAux(NoB* p,int nivel);
public:
    ArvoreB(int _t);

    void percorre();

    NoB *procura(int k);

    void insert(int k);
    void remove(int k);
    void imprimir();
    void imprimirArquivo();
};

#endif // ARVOREB_H_INCLUDED