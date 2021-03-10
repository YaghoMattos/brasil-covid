#include "table.h"

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
    //verifica se houve divisão no nível g
    if(g * N > Nb)
        return true;
    return false;
}

void Table::ultimoBaldeNivelG() {
    //verifica se split aponta para o ultimo balde do nível g
    if( split == N - 1 || split == g * N - 1) {
        split = (N * g) + 1; //reinicia split para o primeiro do nivel g
    }
}

void Table::divideBalde() {
    criaBalde();
    g++;
    Hash haux(Nb);
    //pega o balde apontado por split e divide as chaves com hgmoreone
    for(int i = 0; i < Mb; i++) {
        int chaveTroca;
        int index;
        //chaveTroca recebe chave na posição i do balde apontado por split
        chaveTroca = tabela.at(split)->getChave(i);
        cout << "chaveTroca = " << chaveTroca << endl;
        index = haux.hgMoreOne(chaveTroca, g);

        cout << "index = " << index << endl;
        //procura o primeiro balde com espaço vazio de indice >= index
        while(!tabela.at(index)->temEspaco()) {
            index++;
        }
        tabela.at(index)->insereChave(chaveTroca);
        tabela.at(split)->removeChave(i);
    }
    ultimoBaldeNivelG();
}

void Table::criaBalde() {
    Bucket* novoBalde = new Bucket(Mb);
    tabela.push_back(novoBalde);
    Nb++;
}

double Table::fatorCarga() {
    cout << endl << "chaves=" << chaves << " numBalde=" << Nb << "  M="  << Mb << endl;
    cout << "fc=" << (float)chaves/(Nb*Mb+O) << endl;
    return (float)chaves / (Nb * Mb + O);
}

void Table::insercao(int k1) {
    Hash funcHash(Nb);

    int h = 0;
    int k = k1;

    h = funcHash.hg(k, getNivel());
    cout << "h=" << h << " nivel=" << getNivel() << endl;
    if(h < getSplit()) {
        h = funcHash.hgMoreOne(k, getNivel());
    }

    if(tabela.at(h)->temEspaco()) {
        cout << "tem espaco" << endl;
        //insere a chave na posição h
        tabela.at(h)->insereChave(k);
        chaves++;
    }
    else {
        //verifica a ultima posição de overflow e se ela é nula tem espaço
        if(overflow[O-1] == -1) {
            //encontra a posição para inserir no overflow
            for(int i=0; i < O; i++) {
                if(overflow[i] == -1) {
                    overflow[i] = k;
                    cout << "overflow [" << i << "] = " << overflow[i] << endl;
                    chaves++;
                    break;
                }
            }
        }
        else cout << "overflow sem espaço" << endl;
    }

    if(fatorCarga() >= 0.79) {
        cout << "erro aqui" << endl;
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
