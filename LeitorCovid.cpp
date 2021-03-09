#include "LeitorCovid.h"

LeitorCovid::LeitorCovid(string caminhoArquivo)
{
    this->caminho_arquivo = caminhoArquivo;

    this->n = 0;

    this->arquivoEntrada();
    this->leitura();
}

LeitorCovid::LeitorCovid(string caminhoArquivo, int n)
{
    this->caminho_arquivo = caminhoArquivo;

    this->n = n;

    this->arquivoEntrada();
    this->leitura();
}

LeitorCovid::~LeitorCovid()
{
    delete hash;
}

void LeitorCovid::arquivoEntrada()
{
    this->caminho_arquivo += getSeparadorDiretorio() + "brazil_covid19_cities_processado.csv";
    cout << "Caminho corrigido: " << this->caminho_arquivo << endl;
}

void LeitorCovid::leitura()
{
    this->timerStart();
   
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

    if (this->n != 0)
        data.resize(n);

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
            unsigned int i = 0;
            if (n != 0)
            {
                while (data[i] != nullptr)
                    i = getRand(n);
            }

            vector<string> aux = explode(result[0], '-');
            //cout << "Processando Coordenadas de numero: " << pos << endl;
            CitiesCovid* u = new CitiesCovid();

            if (result.size() > 1)
            {
                u->dia = aux[2];
                u->mes = aux[1];
                u->ano = aux[0];
                u->sigla_estado = result[1];
                u->nome = result[2];
                u->codigo = strToInt(result[3]);
                u->casos = strToInt(result[4]);
                u->mortes = strToInt(result[5]);

                if (n != 0)
                    data[i] = u;
                else
                    data.push_back(u);
                pos++;
            }

            if (n != 0)
                if (pos == n)
                {
                    break;
                }
        }
    }

    this->n = pos;

    if (arquivo_entrada.is_open())
    {
        arquivo_entrada.close();
    }
    double tempo;
    tempo = this->timerEnd();

    cout << "Leitura Realizada em " << tempo << " segundos, "
         << "Comecando insecao na Tabela Hash" << endl
         << endl;

    /*tempo = 0;
    this->timerStart();
    hash = new HashEncLinear(n);
    //cout << "Inserindo no Hash" << endl;
    for (int i = 0; i < n; i++)
    {
        hash->inserir(data[i]);
    }
    tempo = this->timerEnd();
    cout << "Insercao realizada em " << tempo << " segundos" << endl;
    //hash->imprimeArquivo();*/
}

vector<CitiesCovid* > LeitorCovid::getData(){
    return data;
}

HashEncLinear* LeitorCovid::getHash()
{
    return this->hash;
}