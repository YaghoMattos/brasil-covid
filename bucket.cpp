#include "bucket.h"
#include <iostream>

using namespace std;

Bucket::Bucket(int M) {
    this->M = M;
    balde = new int[M];

    for(int i = 0; i < M; i++) {
        balde[i] = -1;
    }
}

Bucket::~Bucket() {
    delete [] balde;
}

bool Bucket::temEspaco() {
    for(int i = 0; i < M; i++) {
        if(balde[i] == -1) {
            cout << "i=" << i << endl;
            return true;
        }
    }
    return false;
}

void Bucket::insereChave(int chave) {
    /*insere na primeira posição vazia do balde*/
    for(int i = 0; i < M; i++) {
        if(balde[i] != -1) {
            balde[i] = chave;
            M++;
        }
    }
}

void Bucket::removeChave(int pos) {
    balde[pos] = -1;
}

int Bucket::getChave(int pos) {
    return balde[pos];
}
