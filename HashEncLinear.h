#ifndef HASHENCLINEAR_H_INCLUDED
#define HASHENCLINEAR_H_INCLUDED

#include <iostream>
#include <string>
#include "Log.h"
#include "HashItem.h"
#include "CitiesCovid.h"

using namespace std;

class HashEncLinear{
    public:
        HashEncLinear(int tam);
        ~HashEncLinear();

        void inserir(CitiesCovid* item);
        bool buscar(CitiesCovid* item);

        int getNumColisoes();
        int getTamanho();
        void imprime();
        void imprimeArquivo();
        HashItem getHashMap(int pos);
    private:
        int tamanho;
        int primo;
        HashItem* HashMap;
        int num_colisoes;

        HashItem criaItem(CitiesCovid* item);
        HashItem criaItemVazio();
        bool isPosicaoVazia(int pos);

        /*Funções auxiliares*/
        int encontraPrimo(int tam);
        int divisao(int id,string data);
        int geraNumero(int id,string data);
};

#endif // HASHENCLINEAR_H_INCLUDED