#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

#include <iostream>

#include "NoAVL.h"
#include "BaseArvores.h"
#include "CitiesCovid.h"
#include "Log.h"

using namespace std;

class ArvoreAVL : public BaseArvores
{
private:
    NoAVL *raiz;


    NoAVL* insertAux(NoAVL* p, int valor);
    void imprimeAux(NoAVL* p,int nivel);
public:
    ArvoreAVL();
    ~ArvoreAVL();

    bool busca(int val);
    int getAltura(NoAVL* p);
    int getBalanceamento(NoAVL* p);
    void insert(int val);
    void imprimir();

    NoAVL *rotSimplesEsq(NoAVL *p); 
    NoAVL *rotSimplesDir(NoAVL *p);
    NoAVL *rotDuplaEsq(NoAVL *p); 
    NoAVL *rotDuplaDir(NoAVL *p); 
    int getComparacoes();
};

#endif // ARVOREAVL_H_INCLUDED