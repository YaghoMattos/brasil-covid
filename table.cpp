#include "table.h"
#include "bucket.h"
#include "hash.h"
//#define M 5

using namespace std;

Table::Table(int N, int M) {
    g = 0;
    this->N = N;
    this->M = M;
    chaves = 0;

    Bucket* b1 = new Bucket();
    Bucket* b2 = new Bucket();
    Bucket* b3 = new Bucket();
    Bucket* b4 = new Bucket();
    Bucket* b5 = new Bucket();
    tabela.push_back(b1);
    tabela.push_back(b2);
    tabela.push_back(b3);
    tabela.push_back(b4);
    tabela.push_back(b5);

    numBaldes = 5;
    split = 0;
}

bool Table::verificaDivisao() {
    //verifica se houve divisao no nivel g
    if(g * N > numBaldes)
        return true;
    return false;
}

void Table::ultimoBaldeNivelG() {
    //verifica se split aponta para o ultimo balde do nivel g
    if( split == N - 1 || split == g * N - 1) {
        g++;
        split = (N * g) + 1; //reinicia split para o primeiro do nivel g
    }
}

void Table::divideBalde() {
    //pega o balde apontado por split e divide as chaves com hgmoreone
    criaBalde();
    Hash haux(N);
    for(int i = 0; i < M; i++) {
        int chaveTroca;
        int index;
        chaveTroca = tabela.at(split)->getChave(i);
        tabela.at(split)->removeChave(i);
        index = haux.hgMoreOne(chaveTroca, g);
        tabela.at(index)->insereChave(chaveTroca);
    }
    ultimoBaldeNivelG();
}

void Table::criaBalde() {
    Bucket* novoBalde = new Bucket();
    tabela.push_back(novoBalde);
}

int Table::fatorCarga() {
    return chaves / (numBaldes * M);
}

int Table::getNivel() {
    return g;
}
void Table::setNivel(int nivel) {
    g = nivel;
}

int Table::getNumBaldes() {
    return numBaldes;
}

void Table::setNumBaldes(int numBaldes) {
    this->numBaldes = numBaldes;
}

int Table::getSplit() {
    return split;
}

void Table::setSplit(int split) {
    this->split = split;
}
