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

    void arquivoEntrada();

    void leitura();


public:
    LeitorCovid(string caminhoArquivo);
    ~LeitorCovid();
};

#endif // LEITURA_LEITORCOVID_H