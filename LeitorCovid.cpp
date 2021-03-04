#include "LeitorCovid.h"

LeitorCovid::LeitorCovid(string caminhoArquivo)
{
    this->caminho_arquivo = caminhoArquivo;

        this->arquivoEntrada();
        this->leitura();
}

LeitorCovid::~LeitorCovid() {}

void LeitorCovid::arquivoEntrada()
{
    this->caminho_arquivo += getSeparadorDiretorio() + "brazil_cities_covid_cities_processado.csv";
    cout << "Caminho corrigido: " << this->caminho_arquivo << endl;
}

void LeitorCovid::leitura()
{
    //Hash = new Hash();
    vector<CitiesCovid *> data;
    bool headerProcessado;
    string line;
    fstream arquivo_entrada;

    arquivo_entrada.open(this->caminho_arquivo.c_str());

    //Verifica se o arquivo de entrada foi aberto
    if (!arquivo_entrada || !arquivo_entrada.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo" << endl
             << "Verifique se o caminho ate o diretorio foi passado corretamente" << endl
             << "Caso o erro continue, verifique pessoalmente a funcao 'arquivoEntrada' presente na classe LeitorCovid.cpp" << endl;
        exit(-2); //Caso não tenha sido possivel abrir o arquivo, encerra-se o programa
    }

    cout << "Arquivo brazil_cities_covid_cities_processado.csv aberto" << endl;
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
            CitiesCovid *u = new CitiesCovid();

            u->dia;
            u->mes;
            u->ano;
            u->sigla_estado;
            u->nome;
            u->codigo;
            u->casos;
            u->mortes;

            data.push_back(u);
            pos++;
        }
    }

    this->n = pos;

    if (arquivo_entrada.is_open())
    {
        arquivo_entrada.close();
    }

    /*cout << "Inserindo no Hash" << endl;
        for (int i = 0; i < n; i++)
        {
            Hash->inserir(data[i]);
        }*/
}
