#include "HashEncLinear.h"

HashEncLinear::HashEncLinear(int tam)
{
    this->tamanho = tam;
    this->primo = this->encontraPrimo(tam);

    this->HashMap = new HashItem[tam];
    for (int i = 0; i < tam; i++)
    {
        HashMap[i].data = "";
        HashMap[i].chave = -1;
    }
}

HashEncLinear::~HashEncLinear()
{
    delete[] HashMap;
}

void HashEncLinear::inserir(CitiesCovid *item)
{
    string data = "";
    data += item->dia;
    data += item->mes;
    data += item->ano;
    //cout << "Antes do calculo da funcao de divisao" << endl;
    int hash = divisao(item->codigo, data);
    //cout << "Valor do Hash: " << hash << endl;
    if (this->isPosicaoVazia(hash)) //Verifica se não há colisão
    {
        HashMap[hash] = criaItem(item);
    }
    else
    {
        int j = 0;
        int hash_search = hash + 1;
        while (j < this->tamanho)
        {
            if (hash_search >= this->tamanho)
            {
                hash_search = 0;
            }
            if (isPosicaoVazia(hash_search))
            {
                HashMap[hash_search] = criaItem(item);
                break;
            }
            j++;
            hash_search++;
        }
    }
}

bool HashEncLinear::buscar(CitiesCovid *item)
{
    string data = "";
    data += item->dia + item->mes + item->ano;

    int hash = divisao(item->codigo, data);

    if (HashMap[hash].chave == item->codigo && HashMap[hash].data.compare(item->dia + "-" + item->mes + "-" + item->ano))
    {
        return true;
    }

    int j = 1;
    int hash_search = hash + 1;
    while (j < this->tamanho)
    {
        if (HashMap[hash_search].chave == item->codigo && HashMap[hash].data.compare(item->dia + "-" + item->mes + "-" + item->ano))
        {
            return true;
        }
        j++;
        hash_search++;
        if (hash_search >= tamanho)
        {
            hash_search = 0;
        }
    }

    return false;
}

HashItem HashEncLinear::criaItem(CitiesCovid *item)
{
    HashItem h;
    h.chave = item->codigo;
    h.data = item->dia + "-" + item->mes + "-" + item->ano;
    return h;
}

void HashEncLinear::imprime()
{
    cout << endl
         << "---------- Imprimindo Tabela Hash ------------" << endl
         << endl;
    for (int i = 0; i < this->tamanho; i++)
    {
        cout << "#" << i << ": "
             << "id: " << HashMap[i].chave << ", "
             << "data: " << HashMap[i].data << endl;
    }
}

void HashEncLinear::imprimeArquivo()
{
    Log::getInstance().iniciaArquivoSaida("Saidas\\HashEncLinear.txt");

    string line = "";
    line += "---------- Imprimindo Tabela Hash ------------";
    Log::getInstance().lineArquivo(line);

    for (int i = 0; i < this->tamanho; i++)
    {
        line = "";
        line += "#" + to_string(i) + ": " +
                "id: " + to_string(HashMap[i].chave) + ", " + "data: " + HashMap[i].data;

        Log::getInstance().lineArquivo(line);
    }
}

bool HashEncLinear::isPosicaoVazia(int pos)
{
    return HashMap[pos].chave == -1;
}

int HashEncLinear::encontraPrimo(int x)
{

    long long int nNew = ((x * 2 + 3) - 2) / 2;
    bool *colore = new bool[nNew + 1];
    for (long long int k = 0; k < nNew + 1; k++)
    {
        colore[k] = false;
    }
    int primo = x;

    for (int i = 1; i <= nNew; i++)
    {
        for (long long int j = i; (i + j + 2 * i * j) <= nNew; j++)
        {
            try
            {
                colore[i + j + 2 * i * j] = true;
            }
            catch (exception e)
            {
                break;
            }
        }

        for (long long int k = x / 2; k < nNew + 1; k++)
        {
            if (!colore[k] && (k * 2 + 1) > x)
            {
                primo = k * 2 + 1;
                break;
            }
        }
    }

    return primo;
}

int HashEncLinear::geraNumero(int id, string data)
{
    int num = stoi(data);
    if (errno == ERANGE)
    {
        cout << "int range error on " << num << endl;
        errno = 0;
        num = 0;
    }

    return num + id;
}

int HashEncLinear::divisao(int id, string data)
{
    //cout << "Gerando numero" << endl;
    int num = (geraNumero(id, data) % primo) % tamanho;

    return num;
}

HashItem HashEncLinear::getHashMap(int pos){
    return HashMap[pos];
}