/*#include <iostream>
#include <string>
#include "bucket.h"
#include "table.h"
#include "hash.h"

//#define MAX_CHAVES = 1431490

using namespace std;

int main()
{
    cout << "--------------- Iniciando Hash Linear ----------------" << endl;

    int N = 0, M = 0, h = 0;

    cout << "Digite o numero de chaves por balde" << endl;
    cin >> M;
    cout << "Digite o numero de baldes" << endl;
    cin >> N;

    Table t(N, M);
    Hash funcHash(N);

    long long k = 1245632045;
    cout << funcHash.hg(k, 0) << endl;

    h = funcHash.hg(k, t.getNivel());
    if(h < t.getSplit()) {
        h = funcHash.hgMoreOne(k, t.getNivel());
    }
    Bucket *baldinho = t.tabela.at(h);
    if(baldinho->temEspaco()) {
        t.tabela.at(h);
    }
    else { }

    if(t.fatorCarga() == 0.8) {
        t.divideBalde();
    }

    return 0;
}*/
