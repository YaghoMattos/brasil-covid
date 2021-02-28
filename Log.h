/**
 * Universidade Federal de Juiz de Fora
 * Log.h
 * Propósito: Classe com os métodos para a impressão dos arquivos
 * Classe Baseada em códigos anteriores da disciplina
*/
#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Log
{

public:
    static Log &getInstance()
    {
        static Log instance;

        return instance;
    };

private:
    Log(){};
    ~Log(){
        fechaArqSaida();
    };

    Log(Log const &);
    void operator=(Log const &);

    ofstream arqSaida;

public:
    void iniciaArquivoSaida(string caminhoArqSaida)
    {
        arqSaida.open(caminhoArqSaida.c_str(), fstream::in | fstream::out | fstream::trunc); //Abre o Arquivo de saída

        if (!arqSaida || !arqSaida.is_open()) //Verifica se o arquivo de saída foi aberto
        {
            cout << "Impossivel abrir o arquivo de saida para escrita" << endl;
            cout << "Com o arquivo: " << caminhoArqSaida << endl;
            cout << "O diretorio 'saidas' foi criado no diretorio raiz (o que esta a main.cpp) ?" << endl;
            exit(1); // sai do programa se nao conseguir abrir o arquivo
        }
    }

    void line(string texto)
    {
        cout << texto << endl;
        arqSaida << texto << endl;
    }

    void lineArquivo(string texto)
    {
        arqSaida << texto << endl;
    }

    void semEndl(string texto)
    {
        cout << texto;
        arqSaida << texto;
    }

    void breakLine(string texto)
    {
        cout << endl;
        arqSaida << endl;
    }

    void fechaArqSaida()
    {
        if (arqSaida.is_open())
        {
            arqSaida.close();
        }
    }
};

#endif // LOG_H