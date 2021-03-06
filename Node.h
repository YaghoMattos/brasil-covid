#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

class Node //classe do no da arvore
{
private:
    int H; //altura do no 
    int valor; // valor do nó
    Node* filhoDir; // ponteiro para o proximo a direita
    Node* filhoEsq; //ponteiro para o proximo a esquerda
    int fb; //valor a ser verificado para balanceamento (fator de balanceamento)

public:
    Node(int valor);//construtor passando valor como parametro
    ~Node();//destrutor
    int getAltura();//get altura
    int getValor();//get do valor do nó
    Node* getFilhoDir();//retorna o filho a direita
    Node* getFilhoEsq();//retorna filho a esquerda
    int getFB();//pega o valor do FB para balanceamento
    void setAltura(int altura);//coloca uma nova altura para o nó
    void setFilhoDir(Node* filhodir);//aponta para um novo nó filho a direita
    void setFilhoEsq(Node* filhoesq);//aponta para um novo nó filho a esquerda
    void atualizaFB();//atualiza o valor de FB de acordo com os filhos
    void atualizaAltura(); // atualiza altura apos inserção de no
};

#endif // NODE_H_INCLUDED
