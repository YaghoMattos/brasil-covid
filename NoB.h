#ifndef NOB_H_INCLUDED
#define NOB_H_INCLUDED

#include <iostream>

#include "Log.h"

using namespace std;

class NoB
{
private:
    int *chave; // ponteiro que aponta pra um vetor com as chaves
    int t;      // grau minimo
    NoB **C;    // ponteiro que aponta pra um vetor de ponteiros com os filhos
    int n;      // Numero de nos atuais
    bool folha; // booleano é folha

public:
    NoB(int t1, bool folha1);
    NoB *procura(int k);
    int achachave(int k);
    void inserenaocheio(int k);

    void dividefilho(int i, NoB *y);
    void remove(int k);
    void removefolha(int idx);
    void removenaofolha(int idx);

    int getPred(int idx);

    int getSucc(int idx);

    void preenche(int idx);

    void emprestaant(int idx);

    void emprestaprox(int idx);

    void juntar(int idx);

    void percorre();
    void percorreArquivo();

    friend class ArvoreB; //Marcando a arvore que usa esses nós como "amiga" para permiti-la usar os seus privados
};

#endif // NOB_H_INCLUDED