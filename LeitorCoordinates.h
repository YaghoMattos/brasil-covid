#ifndef LEITURA_LEITORCOORDINATES_H
#define LEITURA_LEITORCOORDINATES_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include "Base.h"

#include "CitiesCoordinates.h"
#include "QuadTree.h"

using namespace std;

class LeitorCoordinates : public Base
{
private:
    string caminho_arquivo;
    int n; //Numero de registros;
    QuadTree *coordinates;

    void arquivoEntrada();

    void leitura();

public:
    LeitorCoordinates();

    LeitorCoordinates(string caminhoArquivo);

    ~LeitorCoordinates();
};

#endif // LEITURA_LEITORCOORDINATES_H