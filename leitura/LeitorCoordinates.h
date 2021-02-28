#ifndef LEITURA_LEITORCOORDINATES_H
#define LEITURA_LEITORCOORDINATES_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include "Base.h"

#include "../CitiesCoordinates.h"
#include "../arvores/QuadTree.h"

using namespace std;

class LeitorCoordinates : public Base
{
private:
    string caminho_arquivo;
    int n; //Numero de registros;
    QuadTree *coordinates;

    void arquivoEntrada()
    {
        this->caminho_arquivo += getSeparadorDiretorio() + "brazil_cities_coordinates.csv";
        cout << "Caminho corrigido: " << this->caminho_arquivo << endl;
    };

    void leitura()
    {
        coordinates = new QuadTree();
        vector<CitiesCoordinates *> data;
        bool headerProcessado;
        string line;
        fstream arquivo_entrada;

        arquivo_entrada.open(this->caminho_arquivo.c_str());

        //Verifica se o arquivo de entrada foi aberto
        if (!arquivo_entrada || !arquivo_entrada.is_open())
        {
            cout << "Nao foi possivel abrir o arquivo" << endl
                 << "Verifique se o caminho ate o diretorio foi passado corretamente" << endl
                 << "Caso o erro continue, verifique pessoalmente a funcao 'arquivoEntrada' presente na classe LeitorCoordinates.cpp" << endl;
            exit(-2); //Caso não tenha sido possivel abrir o arquivo, encerra-se o programa
        }

        cout << "Arquivo brazil_cities_coordinates.csv aberto" << endl;
        headerProcessado = false;
        int pos = 0;

        while (getline(arquivo_entrada, line))
        {
            vector<string> result = explode(line, ','); // Quebra a string em partes menores

            /*for(int i = 0; i < 5; i++)
                cout << " " << result[i];
            cout << endl;*/

            if (!headerProcessado)
            {
                //cout << "Header Processado" << endl;
                headerProcessado = true;
            }
            else
            {
                //cout << "Processando Coordenadas de numero: " << pos << endl;
                CitiesCoordinates *u = new CitiesCoordinates();

                u->codigo_estado = strToInt(result[0]);
                u->codigo_cidade = strToInt(result[1]);
                u->nome_cidade = result[2];
                u->latitude = strToFloat(result[3]);
                u->longitude = strToFloat(result[4]);
                u->capital = strToBool(result[5]);

                data.push_back(u);
                pos++;
            }
        }

        this->n = pos;

        if (arquivo_entrada.is_open())
        {
            arquivo_entrada.close();
        }

        cout << "Inserindo na QuadTree" << endl;
        for (int i = 0; i < n; i++)
        {
            coordinates->inserir(data[i]);
        }
    };

public:
    LeitorCoordinates()
    {
        this->caminho_arquivo = "C:\\Users\\Renan\\Desktop\\Datasets";

        this->arquivoEntrada();
        this->leitura();
    };

    LeitorCoordinates(string caminhoArquivo)
    {
        this->caminho_arquivo = caminhoArquivo;

        this->arquivoEntrada();
        this->leitura();
    };

    ~LeitorCoordinates(){};
};

#endif // LEITURA_LEITORCOORDINATES_H