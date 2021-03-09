#ifndef LEITURA_LEITORCOVID_H
#define LEITURA_LEITORCOVID_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include "Base.h"
#include "CitiesCovid.h"
#include "QuadTree.h"
#include "Log.h"
#include "HashEncLinear.h"

using namespace std;

class LeitorCovid : public Base
{
private:
    string caminho_arquivo;
    int n; //Numero de registros;
    HashEncLinear* hash;
    vector<CitiesCovid* > data;
    void arquivoEntrada();

    void leitura();


public:
    LeitorCovid(string caminhoArquivo);
    LeitorCovid(string caminhoArquivo,int n);
    ~LeitorCovid();
    vector<CitiesCovid* > getData();
    HashEncLinear* getHash();
};

#endif // LEITURA_LEITORCOVID_H