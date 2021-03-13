#include "bucket.h"

using namespace std;

Bucket::Bucket(int M, int O) {
    this->M = M;
    this->O = O;

    balde = new int[M];
    for(int i = 0; i < M; i++) {
        balde[i] = -1;
    }

    overflow = new int[O];
    for(int i=0; i < O; i++) {
        overflow[i] = -1;
    }
}

Bucket::~Bucket() {
    delete [] balde;
}

bool Bucket::temEspaco() {
    for(int i = 0; i < M; i++) {
        if(balde[i] == -1) {
            return true;
        }
    }
    return false;
}

bool Bucket::overflowEmpty() {
    for(int i = 0; i < O; i++) {
        if(overflow[i] == -1) {
            return true;
        }
    }
    return false;
}

void Bucket::insereChave(int chave) {
    /*insere na primeira posição vazia do balde*/
    for(int i = 0; i < M; i++) {
        if(balde[i] == -1) {
            balde[i] = chave;
            cout << "balde -> insere chave na posicao [" << i << "] = " << chave << ", valor que ficou: " << balde[i] << endl;
            return;
        }
    }
}

void Bucket::setChave(int pos, int k) {
    balde[pos] = k;
}

void Bucket::removeChave(int pos) {
    balde[pos] = -1;
}

int Bucket::getChave(int pos) {
    return balde[pos];
}

void Bucket::insereOverflow(int chave) {
    /*insere na primeira posição vazia do overflow*/
    for(int i = 0; i < M; i++) {
        if(overflow[i] == -1) {
            overflow[i] = chave;
            cout << "Overflow -> insere chave = " << overflow[i] << " na posicao [" << i << "]" << endl;
            return;
        }
    }
}

void Bucket::removeOverflow(int pos) {
    overflow[pos] = -1;
}

int Bucket::getOverflow(int pos) {
    return overflow[pos];
}

void Bucket::imprime() {
    for(int i = 0; i < M; i++) {
        cout << "[" << i << "] = " << balde[i] << ", ";
    }
    cout << endl;
}
