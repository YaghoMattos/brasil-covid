#include "bucket.h"
#include <vector>

using namespace std;

//armazena e manipula os baldes
class Table {
    private:
        //nivel da tabela
        int g;
        //numero de chaves por balde
        int M;
        //numero de baldes por n�vel
        int N;
        //numero total de baldes
        int numBaldes;
        //numero de chaves inseridas
        int chaves;
        //ponteiro para indicar o balde
        int split;


    public:
        //lista de baldes
        vector<Bucket*> tabela;
        Table(int N, int M);
        bool verificaDivisao();
        void ultimoBaldeNivelG();
        void divideBalde();
        void criaBalde();
        int fatorCarga();
        int getNivel();
        void setNivel(int nivel);
        int getNumBaldes();
        void setNumBaldes(int numBaldes);
        void setSplit(int split);
        int getSplit();
};
