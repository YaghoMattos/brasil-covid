#include <iostream>

#ifndef Included_Bucket_H
#define Included_Bucket_H

using namespace std;

class Bucket {
    private:
        //tamanho dos baldes, n�mero de chaves de cada balde
        int M;
        //lista de chaves
        int *balde;

    public:
        int *overflow;
        Bucket(int M, int O);
        ~Bucket();
        bool temEspaco();
        void insereChave(int chave);
        void removeChave(int pos);
        int getChave(int pos);
};

#endif
