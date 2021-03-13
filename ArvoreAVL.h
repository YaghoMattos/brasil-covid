#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

#include <iostream>

#include "NoAVL.h"
#include "CitiesCovid.h"
#include "Log.h"

using namespace std;

class ArvoreAVL{
    private:
        NoAVL* raiz;

        void rotacaoDupla(NoAVL* p, int dir);
        void rotacaoSimples(NoAVL* p, int dir);

        void aumentaBalanceamento(NoAVL* p, int dir);
        void rebalanceamentoInserir(NoAVL* p, int dir, bool hAlterada);

        void inserirAux(NoAVL * p,int valor,bool hAlterada);

        int oposto(int dir);
        void imprimirAux(NoAVL * p,int nivel);
    public:
        ArvoreAVL();
        ~ArvoreAVL();

        void inserir(int valor);
        bool search(int valor);

        void clear();
        void imprimir();
};

#endif // ARVOREAVL_H_INCLUDED