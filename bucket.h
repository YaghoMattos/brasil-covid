#include <iostream>

#ifndef Included_Bucket_H
#define Included_Bucket_H

using namespace std;

class Bucket {
    private:
        //tamanho dos baldes, n�mero de chaves de cada balde
        int M;
        //tamanho overflow
        int O;
        //lista de chaves
        int *balde;
        //lista de overflow
        int *overflow;

    public:

        Bucket(int M, int O);
        ~Bucket();
        bool temEspaco();
        bool overflowEmpty();
        void insereOverflow(int chave);
        void removeOverflow(int pos);
        int getOverflow(int pos);
        void insereChave(int chave);
        void setChave(int pos, int k);
        void removeChave(int pos);
        int getChave(int pos);
        void imprime();
};

#endif
