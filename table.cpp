#include "table.h"

//#define M 5

using namespace std;

Table::Table(int N, int Mb, int O) {
    g = 0;
    this->N = N;
    this->Mb = Mb;
    this->O = O;
    chaves = 0;
    split = 0;
    overflow = new int[O];

    for(int i=0; i < O; i++) {
        overflow[i] = -1;
    }

    for(int i = 0; i < N; i++) {
        Bucket* balde = new Bucket(Mb);
        tabela.push_back(balde);
    }
    Nb = N;
}

bool Table::verificaDivisao() {
    //verifica se houve divis�o no n�vel g
    if(g * N > Nb)
        return true;
    return false;
}

void Table::ultimoBaldeNivelG() {
    //verifica se split aponta para o ultimo balde do n�vel g
    if( split == N - 1 || split == g * N - 1) {
        g++;
        split = (N * g) + 1; //reinicia split para o primeiro do nivel g
    }
}

void Table::divideBalde() {
    //pega o balde apontado por split e divide as chaves com hgmoreone
    criaBalde();
    Hash haux(N);
    for(int i = 0; i < Mb; i++) {
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
    Bucket* novoBalde = new Bucket(Mb);
    tabela.push_back(novoBalde);
}

double Table::fatorCarga() {
    cout << endl << "chaves=" << chaves << " numBalde=" << Nb << "  M="  << Mb << endl;
    return (float)chaves / (Nb * Mb);
}

void Table::insercao(int k1) {
    Hash funcHash(N);
    /*long long h = 0;
    long long int k = 20200327120005;*/

    int h = 0;
    int k = k1;

    h = funcHash.hg(k, getNivel());
    cout << "h=" << h << " nivel=" << getNivel() << endl;
    if(h < getSplit()) {
        h = funcHash.hgMoreOne(k, getNivel());
    }

    if(tabela.at(h)->temEspaco()) {
        cout << "tem espaco=" << tabela.at(h)->temEspaco() << endl;
        //insere a chave na posi��o h
        tabela.at(h)->insereChave(k);
        chaves++;
    }
    else {
        //verifica a ultima posi��o de overflow e se ela � nula tem espa�o
        if(overflow[O-1] == -1) {
            for(int i=0; i < O; i++) {
                if(overflow[i] == -1) {
                    overflow[i] = k;
                }
            }
        }
    }

    cout << "fc=" << (float)chaves/(Nb*Mb+O) << endl;
    if(fatorCarga() >= 0.8) {
        divideBalde();
    }
    cout << "------------------fim------------------" << endl;
}

void imprimir() {
}

int Table::getNivel() {
    return g;
}
void Table::setNivel(int nivel) {
    g = nivel;
}

int Table::getNumBaldes() {
    return Nb;
}

void Table::setNumBaldes(int numBaldes) {
    this->Nb = numBaldes;
}

int Table::getSplit() {
    return split;
}

void Table::setSplit(int split) {
    this->split = split;
}
