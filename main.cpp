#include <iostream>
#include <string>

/*Bibliotecas criadas*/
#include "arvores/QuadTree.h"
#include "leitura/LeitorCoordinates.h"
#include "leitura/LeitorCovid.h"

using namespace std;
string caminho_diretorio;

/*Funções correspondentes ao menu principal do programa*/
int menu();
void laco();
void selecionado(int chave);
void menuTestes();

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        caminho_diretorio = argv[1];
    }
    else
    {
        cerr << "O numero de argumentos passados como parametro eh insuficiente" << endl
             << "Certifique-se de que esteja na forma <executavel> <caminho_diretorio>" << endl;
        exit(-1);
    }

    laco();
    return 0;
}

/**
 * Menu Principal da Aplicação
 * autor: Renan Nunes da Costa Gonçalves e Yagho de Mattos
 * @return int 
 */
int menu()
{
    int opcao;

    cout << "\t\tTrabalho de Estrutura de Dados 2" << endl
         << "*----------------------------------------------------------------------*" << endl;
menu:
    cout << "[01] Carregamento do arquivo de cidades; " << endl
         << "[02] Carregamento do arquivo pre-processado de casos; " << endl
         << "[03] Estrutura de Dados Balanceadas; " << endl
         << "[04] Modulo de Testes; " << endl
         << "[05] Gerar arquivo brazil_covid19_cities.csv; " << endl
         << " [0] Sair;" << endl;
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 0)
    {
        goto menu;
    }

    return opcao;
}

/**
 * Laço de execução que garante que o menu continue funcionando
 * autor: Renan Nunes da Costa Gonçalves e Yagho de Mattos
 * 
 */
void laco()
{
    int selecao = -1;

    while (selecao != 0)
    {
        selecao = menu();
        if (selecao >= 0 && selecao < 6)
        {
            selecionado(selecao);
        }
    }

    cout << "Finalizando execucao..." << endl;
    return;
}

void selecionado(int chave)
{
    LeitorCoordinates *leitorCoordinate;
    LeitorCovid *leitorCovid;

    switch (chave)
    {
    case 1:
        leitorCoordinate = new LeitorCoordinates(caminho_diretorio);
        delete leitorCoordinate;
        break;
    case 2:
        leitorCovid = new LeitorCovid(caminho_diretorio,true);
        delete leitorCovid;
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        leitorCovid = new LeitorCovid(caminho_diretorio,false);
        delete leitorCovid;
        break;
    default:
        break;
    }
}
