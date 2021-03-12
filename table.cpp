#include "table.h"

using namespace std;

Table::Table(int N, int Mb, int O) {
    g = 0;
    this->N = N;
    this->Mb = Mb;
    this->O = O;
    chaves = 0;
    split = 0;

    for(int i = 0; i < N; i++) {
        Bucket* balde = new Bucket(Mb, O);
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
        split = 0; //reinicia split para o primeiro balde
        g++;
        cout << "reseta split, g = " << g << endl;
    }
}

void Table::divideBalde() {
    criaBalde();
    Hash haux(Nb);
    //pega o balde apontado por split e divide as chaves com hgmoreone
    for(int i = 0; i < Mb; i++) {
        //verifica se está acessando posição valida
        if(tabela.at(split)->getChave(i) != -1) {
            int chaveTroca;
            int index;
            //chaveTroca recebe chave na posição i do balde apontado por split
            chaveTroca = tabela.at(split)->getChave(i);
            cout << endl << "**********inicia distribuicao de chave**********" << endl;
            cout << "chaveTroca = " << chaveTroca << endl;
            index = haux.hgMoreOne(chaveTroca, g);
            cout << "index inicial = " << index << endl;

            //exceção, se o hg+1 der um index maior que a posição do ultimo balde, insere no ultimo balde
            if(index > Nb-1) {
                index = Nb-1;
                tabela.at(index)->insereChave(chaveTroca);
                tabela.at(split)->removeChave(i);
                cout << "**********chave distribuida if**********" << endl << endl;
            }
            //hg+1 deu certo e segue o fluxo normal de execução
            else {
                //verifica se a chave precisa mesmo mudar de balde
                //if(index != split) {
                   //procura o primeiro balde com espaço vazio de indice >= index
                    while(!tabela.at(index)->temEspaco()) {
                        index++;
                    }
                    cout << "index final = " << index << endl;
                    tabela.at(index)->insereChave(chaveTroca);
                    tabela.at(split)->removeChave(i);
                    cout << "**********chave distribuida**********" << endl << endl;
                //}
            }
        }

    }
    split++;
    ultimoBaldeNivelG();
}

void Table::criaBalde() {
    Bucket* novoBalde = new Bucket(Mb, O);
    tabela.push_back(novoBalde);
    Nb++;
}

double Table::fatorCarga(int of) {
    cout << endl << "chaves=" << chaves << " numBalde=" << Nb << "  M="  << Mb << endl;
    cout << "fc=" << (float)chaves/(Nb*Mb+of) << endl;
    return (float)chaves / (Nb * Mb + of);
}

void Table::insercao(int k1) {
    Hash funcHash(Nb);

    int h = 0;
    int k = k1;
    int of = 0;

    h = funcHash.hg(k, getNivel());
    cout << "h =" << h << " nivel =" << getNivel() << endl;
    if(h < split) {
        h = funcHash.hgMoreOne(k, getNivel());
    }
    //exceção, se h maior que a posição do ultimo balde, insere no ultimo balde
    if(h > Nb-1) {
        cout << "h > que o indece do ultimo balde" << endl;
        //insere a chave no ultimo balde
        tabela.at(Nb-1)->insereChave(k);
        chaves++;
    }
    else if(tabela.at(h)->temEspaco()) {
        cout << "tem espaco" << endl;
        //insere a chave na posição h
        tabela.at(h)->insereChave(k);
        chaves++;
    }
    else {
        //verifica a ultima posição de overflow e se ela tem espaço
        if(tabela.at(h)->overflow[O-1] == -1) {
            //encontra a posição para inserir no overflow do balde nas posição h
            for(int i=0; i < O; i++) {
                if(tabela.at(h)->overflow[i] == -1) {
                    tabela.at(h)->overflow[i] = k;
                    cout << "overflow [" << i << "] = " << tabela.at(h)->overflow[i] << endl;
                    chaves++;
                    of ++;
                    break;
                }
            }
        }
        else cout << "overflow sem espaço" << endl;
    }
    float fc = fatorCarga(of);
    if(fc >= (float)0.8) {
        cout << "fc > 8 divideBalde" << endl;
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
