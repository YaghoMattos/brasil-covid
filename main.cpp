#include <iostream>
#include <string>

/*Bibliotecas criadas*/
#include "QuadTree.h"
#include "HashEncLinear.h"
#include "ArvoreAVL.h"
#include "LeitorCoordinates.h"
#include "LeitorCovid.h"

using namespace std;
string caminho_diretorio;

/*Funções correspondentes ao menu principal do programa*/
int menu();
void laco();
void selecionado(int chave);
int menuTestes();
void moduloTestes();
void selecionadoTestes(int chave);

/*Casos de Teste*/
void quadTree();
void funcaoHash();
void arvoreAVL();
void arvoreB();

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
         << " [0] Sair;" << endl;
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 0)
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
        leitorCoordinate = new LeitorCoordinates(caminho_diretorio); //Lê todos os arquivos
        delete leitorCoordinate;
        break;
    case 2:
        leitorCovid = new LeitorCovid(caminho_diretorio); //Lê todos os arquivos
        delete leitorCovid;
        break;
    case 3: //Trabalho Propriamente dito
        break;
    case 4:
        moduloTestes(); //Modulo de Testes
        break;
    default:
        break;
    }
}

int menuTestes()
{
    int opcao;

    cout << "\t\tModulo de testes" << endl
         << "*----------------------------------------------------------------------*" << endl;
menu:
    cout << "[01] Insercao de N chaves na QuadTree; " << endl
         << "[02] Insercao de N registros na TabelaHash; " << endl
         << "[03] Insercao de N chaves na Arvore AVL; " << endl
         << "[04] Insercao de N chaves na Arvore B; " << endl
         << " [0] Sair;" << endl;
    cout << "Opcao: ";
    cin >> opcao;

    if (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 0)
    {
        goto menu;
    }

    return opcao;
}

void moduloTestes()
{
    int selecao = -1;

    while (selecao != 0)
    {
        selecao = menuTestes();
        if (selecao >= 0 && selecao < 6)
        {
            selecionadoTestes(selecao);
        }
    }

    cout << "Finalizando menu de testes..." << endl;
    return;
}

void selecionadoTestes(int chave)
{
    switch (chave)
    {
    case 1:
        quadTree();
        break;
    case 2:
        funcaoHash();
        break;
    case 3:
        arvoreAVL();
        break;
    case 4:
        arvoreB();
        break;
    default:
        break;
    }
}

/**
 * Modulo de Testes da Árvore QuadTree
 * 
 */
void quadTree()
{

    int n = 0; //Número de Registros a ser lido

    cout << "Selecione o numero de chaves a ser inserido na QuadTree: ";
    cin >> n;

    LeitorCoordinates *leitorCoordinate = new LeitorCoordinates(caminho_diretorio, n); //Cria um novo Leitor 
    QuadTree *quad = leitorCoordinate->getQuadTree(); //Recebe a QuadTree gerada por esse leitor

    if (n <= 20) //Caso o número de Chaves seja menor que 20, será impresso na tela
    {
        quad->imprimirTela();
    }
    else //Se não, iremos imprimir em um arquivo
    {
        quad->imprimir();
    }
    delete leitorCoordinate;
    delete quad;
}

void funcaoHash()
{
    int n = 0;
    cout << "Selecione o numero de registros a ser inserido na Tabela Hash de Encadeamento Linear: ";
    cin >> n;
    LeitorCovid* leitorCovid = new LeitorCovid(caminho_diretorio, n);
    HashEncLinear* hash = new HashEncLinear(n);
    vector<CitiesCovid*> data = leitorCovid->getData();

    for (int i = 0; i < n; i++)
    {
        hash->inserir(data[i]);
    }

    if (n <= 20)
    {
        hash->imprime();
    }
    else
    {
        hash->imprimeArquivo();
    }

    data.clear();
    delete leitorCovid;
    delete hash;
}

void arvoreAVL(){
    int n = 0;
    cout << "Selecione o numero de chaves a ser inserido na arvore AVL: ";
    cin >> n;
    LeitorCovid* leitorCovid = new LeitorCovid(caminho_diretorio, n);
    HashEncLinear* hash = new HashEncLinear(n);
    vector<CitiesCovid*> data = leitorCovid->getData();

    for (int i = 0; i < n; i++)
    {
        hash->inserir(data[i]);
    }

    ArvoreAVL* arvore = new ArvoreAVL();

    for(int i = 0; i < n; i++)
    {
        //cout << "Inserindo na arvore" << endl;
        arvore->insertNode(hash->getHashMap(i).chave);
       //arvore->insertNode(i);
    }

    if (n <= 20)
    {
        arvore->imprimeArvore();
    }
    else
    {
        
    }
    delete leitorCovid;
    //delete hash; 
}

void arvoreB(){

}