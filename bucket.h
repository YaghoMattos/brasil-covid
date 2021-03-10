/*armazenar e operar com as chaves*/
#ifndef Included_Bucket_H
#define Included_Bucket_H

using namespace std;

class Bucket {
    private:
        //tamanho dos baldes, número de chaves de cada balde
        int M;
        //lista de chaves
        int *balde;
    public:
        Bucket(int M);
        ~Bucket();
        bool temEspaco();
        void insereChave(int chave);
        void removeChave(int pos);
        int getChave(int pos);
};

#endif
