#include "table.h"

using namespace std;

Table::Table(int N, int Mb, int O) {
    g = 0;
    this->N = N;
    this->Mb = Mb;
    this->O = O;
    chaves = 0;
    split = 0;
    of = 0;

    for(int i = 0; i < N; i++) {
        Bucket* balde = new Bucket(Mb, O);
        tabela.push_back(balde);
    }
    Nb = N;
}

void Table::criaBalde() {
    Bucket* novoBalde = new Bucket(Mb, O);
    tabela.push_back(novoBalde);
    Nb++;
}

bool Table::verificaDivisao() {
    //verifica se houve divisão no nível g
    if(g * N > Nb)
        return true;
    return false;
}

float Table::fatorCarga(int of) {
    float fc = 0;
    fc = (float)chaves / (Nb * Mb + of);
    cout << endl << "conferindo valores do fator de carga -> chaves = " << chaves << ", Nb = " << Nb << ",  Mb = "  << Mb << ", O = " << of << endl;
    cout << "fc = " << fc << endl;
    return fc;
}

bool Table::ultimoBaldeNivelG() {
    //verifica se split aponta para o ultimo balde do nível g
    if(split == N) {
        cout << "split = " << split << ", N = " << endl;
        split = 0; //reinicia split para o primeiro balde
        g++;
        cout << "ultimo balde no nivel g (split = 0 e g++), g = " << g << endl;
        return true;
    }
    return false;
}

void Table::insercaoDivideBalde(int chave, int index, int i) {
    cout << "insercao divide balde i = " << i << endl;
    //exceção, se o hg+1 der um index maior que a posição do ultimo balde, insere no ultimo balde
    if(index > Nb-1) {
        index = Nb-1;
        tabela.at(index)->insereChave(chave);
        tabela.at(split)->removeChave(i);
        cout << "**********chave distribuida no ultimo balde**********" << endl << endl;
    }
    //hg+1 deu certo e segue o fluxo normal de execução
    else {
        int indice = index, teste = 0;
        //caso balde apontado por index esteja cheio, procura o primeiro balde com espaço vazio
        while(!tabela.at(index)->temEspaco()) {

            for(int j = 0; j < N; j++) {
                if(tabela.at(index)->getChave(j) == chave) {
                    cout << "Nao troca de balde" << endl;
                    teste = 1;
                    break;
                }
            }
            if(teste == 1) {
                break;
            } else {
                cout << "index antes de atualizar = " << index << endl;
                index++;
            }
        }
        cout << "index depois de atualizar = " << index << ", indice " << indice << endl;
        //verifica se existe a chave no balde, caso o indice de insercao igual o de remocao
        if(index == indice && teste == 1) {
            cout << "index == indice" << endl;
        }
        else {
            tabela.at(split)->imprime();
            tabela.at(index)->insereChave(chave);
            tabela.at(split)->imprime();
            tabela.at(split)->removeChave(i);
            cout << "chave do balde" << split << ", removida da posicao" << i << endl;
            tabela.at(split)->imprime();
        }
        cout << "**********chave distribuida**********" << endl << endl;
    }
}

void Table::divideBalde() {
    criaBalde();
    Hash haux(N);
    //pega o balde apontado por split e divide as chaves com hgmoreone
    for(int i = 0; i < Mb; i++) {
        //verifica se está acessando posição valida
        if(tabela.at(split)->getChave(i) != -1) {
            cout << endl << "**********inicia distribuicao de chave**********" << endl;
            int chaveTroca = 0, index = 0;
            //chaveTroca recebe chave na posição i do balde apontado por split
            chaveTroca = tabela.at(split)->getChave(i);
            cout << "chave que sera trocada de balde = " << chaveTroca << ", indice chave = " << i << endl;
            index = haux.hgMoreOne(chaveTroca, g);

            cout << "split = " << split << endl;
            insercaoDivideBalde(chaveTroca, index, i);

        }
    }
    //atualiza as chaves que restaram no balde para baldes com indice menores
    if(tabela.at(split)->getChave(0) == -1) {
        for(int j=0; j < Mb-1; j++) {
        tabela.at(split)->setChave(j, tabela.at(split)->getChave(j+1));
        tabela.at(split)->removeChave(j+1);
        }
    }
    ultimoBaldeNivelG();
    //se for o ultimo balde do nivel g, então tem que dividir também por hg+1 as chaves do overflow
    //if(ultimoBaldeNivelG()) {
    /****************************** erro refazer ******************************/
    int chave = 0, index = 0;
    for(int i = 0; i < Nb; i++) {
        for(int j = 0; j < O; j++) {
            //verifica se pode acessar a posição do overflow
            if(tabela.at(i)->getOverflow(j) != -1) {
                cout << endl << "**********overflow inicia distribuicao de chave**********" << endl;
                chave = tabela.at(i)->getOverflow(j);
                index = haux.hgMoreOne(chave, g);

                //insercaoDivideBalde(chaveTroca, index, j);

                cout << "insercao divide/overflow balde i = " << i << endl;
                //exceção, se o hg+1 der um index maior que a posição do ultimo balde, insere no ultimo balde
                if(index > Nb-1) {
                    index = Nb-1;
                    tabela.at(index)->insereChave(chave);
                    tabela.at(i)->removeOverflow(j);
                    cout << "**********chave distribuida no ultimo balde**********" << endl << endl;
                }
                //hg+1 deu certo e segue o fluxo normal de execução
                else {
                    int indice = index, teste = 0;
                    //caso balde apontado por index esteja cheio, procura o primeiro balde com espaço vazio
                    while(!tabela.at(index)->overflowEmpty()) {

                        for(int j = 0; j < N; j++) {
                            if(tabela.at(index)->getOverflow(j) == chave) {
                                cout << "Nao retirar do overflow" << endl;
                                teste = 1;
                                break;
                            }
                        }
                        if(teste == 1) {
                            break;
                        } else {
                            cout << "index antes de atualizar = " << index << endl;
                            index++;
                        }
                    }
                    cout << "index depois de atualizar = " << index << ", indice " << indice << endl;
                    //verifica se existe a chave no balde, caso o indice de insercao igual o de remocao
                    if(index == indice && teste == 1) {
                        cout << "index == indice" << endl;
                    }
                    else {
                        tabela.at(i)->imprime();
                        tabela.at(index)->insereChave(chave);
                        tabela.at(i)->imprime();
                        tabela.at(i)->removeOverflow(j);
                        cout << "overflow do balde" << split << ", removido da posicao" << j << endl;
                        tabela.at(i)->imprime();
                    }
                    cout << "**********chave distribuida**********" << endl << endl;
                }

            //ao retirar uma chave do overflow, diminui o valor de of
            of--;
            }
        }
    }
    //}
    split++;
}

void Table::insercao(int k1) {
    Hash funcHash(N);
    int h = 0, k = k1;

    cout << endl << "-------------iniciando insercao------------" << endl;

    h = funcHash.hg(k, getNivel());
    cout << "k = " << k << ", h = " << h << ", nivel = " << getNivel() << endl;
    if(h < split) {
        h = funcHash.hgMoreOne(k, getNivel());
    }
    //exceção, se h gerado por hg+1 for maior que a posição do ultimo balde, insere no ultimo balde
    if(h > Nb-1) {
        cout << "h > que o indece do ultimo balde" << endl;
        //insere a chave no ultimo balde
        tabela.at(Nb-1)->insereChave(k);
        chaves++;
    }
    //h está certo e verifica se tem espaço no balde
    else if(tabela.at(h)->temEspaco()) {
        cout << "balde na posicao h tem espaco" << endl;
        //insere a chave na posição h
        tabela.at(h)->insereChave(k);
        chaves++;
    }
    //balde da posição h está cheio e tem que inserir no overflow
    else {
        //verifica se tem espaço no overflow do balde da posição h
        if(tabela.at(h)->overflowEmpty()) {
            //encontra a posição para inserir no overflow do balde da posição h
            tabela.at(h)->insereOverflow(k);
            chaves++;
            of ++;
        }
        else cout << "overflow sem espaço" << endl;
    }
    float fc = fatorCarga(O);
    if(split != 1 && split != 2) {
        if(fc >= 0.8) {
        cout << "fc > 0.8 entao divideBalde" << endl;
        divideBalde();
        }
    }
    else {
        if(fc >= 0.73) {
        cout << "fc > 0.8 entao divideBalde" << endl;
        divideBalde();
        }
    }

    cout << "------------------fim------------------" << endl;
}

void Table::imprimir() {
    for(int i = 0; i < Nb; i++) {
        cout << "balde [" << i << "]" << "-> ";
        tabela.at(i)->imprime();
    }
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
