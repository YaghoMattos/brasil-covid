#include <iostream>
#include <vector>
#include "hash.h"
#include "bucket.h"

using namespace std;

//armazena e manipula os baldes
class Table {
    private:
        //n�vel da tabela
        int g;
        //numero de chaves por balde
        int Mb;
        //n�mero de baldes por n�vel
        int N;
        //posi��es no overflow
        int O;
        //numero total de baldes
        int Nb;
        //numero de chaves inseridas
        int chaves;
        //ponteiro para indicar o balde
        int split;
        int *overflow;

    public:
        Table(int N, int M, int O);
        //lista de baldes
        vector<Bucket*> tabela;
        bool verificaDivisao();
        void ultimoBaldeNivelG();
        void divideBalde();
        void criaBalde();
        double fatorCarga();
        int getNivel();
        void setNivel(int nivel);
        int getNumBaldes();
        void setNumBaldes(int Nb);
        void setSplit(int split);
        int getSplit();
        void insercao(int k1);
        void imprimir();
};
