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
        //numero de baldes por nivel
        int N;
        //posicoes no overflow
        int O;
        //numero total de baldes
        int Nb;
        //numero de chaves inseridas
        int chaves;
        //ponteiro para indicar o balde
        int split;

        int of;

    public:
        //lista de baldes
        vector<Bucket*> tabela;
        Table(int N, int M, int O);
        bool verificaDivisao();
        bool ultimoBaldeNivelG();
        void insercaoDivideBalde(int chave, int index, int i);
        void divideBalde();
        void criaBalde();
        float fatorCarga(int of);
        int getNivel();
        void setNivel(int nivel);
        int getNumBaldes();
        void setNumBaldes(int Nb);
        void setSplit(int split);
        int getSplit();
        void insercao(int k1);
        void imprimir();
};
