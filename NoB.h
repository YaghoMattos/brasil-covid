#ifndef NOB_H_INCLUDED
#define NOB_H_INCLUDED

#include <iostream>
#include <string>

#include "Log.h"

using namespace std;

class NoB
{
private:
    int *chave; // ponteiro que aponta pra um vetor com as chaves
    string* data; //Datas
    int t;      // grau minimo
    NoB **C;    // ponteiro que aponta pra um vetor de ponteiros com os filhos
    int n;      // Numero de nos atuais
    bool folha; // booleano é folha

public:
    NoB(int t1, bool folha1);
    NoB *procura(int k);
    int achachave(int k);
    void inserenaocheio(int k,string d);

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

    int getChave(int k){return this->chave[k];};
    string getData(int k){return this->data[k];};

    friend class ArvoreB; //Marcando a arvore que usa esses nós como "amiga" para permiti-la usar os seus privados
};

#endif // NOB_H_INCLUDED