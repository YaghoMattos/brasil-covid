#include "LeitorCoordinates.h"
LeitorCoordinates::LeitorCoordinates()
{
    this->caminho_arquivo = "";
    //this->caminho_arquivo = "C:\\Users\\Renan\\Desktop\\Datasets";

    this->n = 0;

    this->arquivoEntrada();
    this->leitura();
}

LeitorCoordinates::LeitorCoordinates(string caminhoArquivo, int num)
{
    this->caminho_arquivo = caminhoArquivo;

    this->n = num;

    this->arquivoEntrada();
    this->leitura();
}

LeitorCoordinates::LeitorCoordinates(string caminhoArquivo)
{
    this->caminho_arquivo = caminhoArquivo;

    this->n = 0;

    this->arquivoEntrada();
    this->leitura();
}

LeitorCoordinates::~LeitorCoordinates(){};
void LeitorCoordinates::arquivoEntrada()
{
    this->caminho_arquivo += getSeparadorDiretorio() + "brazil_cities_coordinates.csv";
    cout << "Caminho corrigido: " << this->caminho_arquivo << endl;
}

void LeitorCoordinates::leitura()
{
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

    if(this->n != 0)
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
            if(n != 0)
            {
                while(data[i] != nullptr)
                    i = getRand(n);
            }

            //cout << "Processando Coordenadas de numero: " << pos << endl;
            CitiesCoordinates *u = new CitiesCoordinates();

            if (result.size() > 1)
            {
                u->codigo_estado = strToInt(result[0]);
                u->codigo_cidade = strToInt(result[1]);
                u->nome_cidade = result[2];
                u->latitude = strToFloat(result[3]);
                u->longitude = strToFloat(result[4]);
                u->capital = strToBool(result[5]);

                if(n != 0)
                    data[i] = u;
                else
                    data.push_back(u);
                pos++;
            }

            if(n != 0)
                if(pos == n)
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

    //cout << "Inserindo na QuadTree" << endl;
    coordinates = new QuadTree();
    for (auto it = data.begin(); it != data.end(); it++)
    {
        //cout << "Inserindo QuadTree\n";
        coordinates->inserir(*it);
    }
}

QuadTree* LeitorCoordinates::getQuadTree(){
    return this->coordinates;
}