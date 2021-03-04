#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Node.h"

using namespace std;

class ArvoreAVL
{
private:
    Node* noRaiz;//nó raiz da arvore, aponta para o primeiro nó da arvore
    
public:
     ArvoreAVL();//construtor
    ~ArvoreAVL();//destrutor
    Node* getRaiz();//retorna a raiz da arvore
    void setRaiz(Node* novaRaiz);//aponta para uma raiz pre definida
    Node* buscadorDeNoPai(int valor);//caminha pela arvore procurando pelo nó e no final retorna se ele existe ou nao
    bool estahNaArvore(int valor, Node* noRaiz); // caminha recursivamente para verificação se o nó está na arvore ou nao
    void insertNode(int id); // insere novo no na arvore
    void checkbalance (int valor, Node* raiz); //confere o balanceamento da arvore
};

#endif // ARVOREAVL_H_INCLUDED

