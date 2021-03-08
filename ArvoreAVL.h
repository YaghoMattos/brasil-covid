#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Node.h"
#include "BaseArvores.h"

using namespace std;

class ArvoreAVL : public BaseArvores
{
private:
    Node* noRaiz;//nó raiz da arvore, aponta para o primeiro nó da arvore
    
public:
     ArvoreAVL();//construtor
    ~ArvoreAVL();//destrutor
    Node* getRaiz();//retorna a raiz da arvore
    void setRaiz(Node* novaRaiz);//aponta para uma raiz pre definida
    Node* buscadorDeNoPai(int valor, Node* noRaiz);//caminha pela arvore procurando pelo nó e no final retorna se ele existe ou nao
    bool estahNaArvore(int valor, Node* noRaiz); // caminha recursivamente para verificação se o nó está na arvore ou nao
    void insertNode(int id); // insere novo no na arvore
    void checkbalance (int valor, Node* raiz); //confere o balanceamento da arvore
    void rotacaoSimplesEsq(Node* noDesbalanceado); //efetua a rotacao simples a esquerda
    void rotacaoSimplesDir(Node* noDesbalanceado); //efetua a rotacao simples a direita
    void rotacaoDuplaEsq(Node* noDesbalanceado); //efetua a rotacao dupla a esquerda
    void rotacaoDuplaDir (Node* noDesbalanceado); // efetua a rotacao dupla a direita
    void imprimeNo(int valor);//imprime valor
};

#endif // ARVOREAVL_H_INCLUDED

