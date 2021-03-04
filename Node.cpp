#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Node.h"

using namespace std;
/**************************************************************************************************
 * Definindo os metodos dos Nós da arvore
**************************************************************************************************/

// Constructor
Node::Node(int valor)
{
    this->valor = valor; //valor inserido no nó
    this->filhoDir = this->filhoEsq = nullptr; //no construtor tanto o Filho a direita quanto o da esquerda recebem null
    this->H = 0;//seta altura inicial como 0;
    this->fb = 0;//seta FB inicial como 0;
}

Node::~Node()
{

}
// declaraçoes dos Getters
int Node::getAltura()//pega a altura daquele nó
{
    return this->H;//retorna altura do no na arvore
}
int Node::getValor()//pega o valor armazenado no nó da arvore
{
    return this->valor;//retorna valor do nó
}
Node* Node::getFilhoDir()//pega o filho a direita daquele nó
{
    return this->filhoDir;//retorna filho a direita
}
Node* Node::getFilhoEsq()//pega o filho a esquerda daquele nó
{
    return this->filhoEsq;//retorna o filho a esquerda
}
int Node::getFB()//pega o FB do Nó
{
    return this->fb;//retorna o valor do FB do nó
}
//declaração dos setters
void Node::setAltura(int altura)//seta uma nova altura
{
    this->H = altura;//altura recebe a nova altura
}
void Node::setFilhoDir(Node* filhodir)//seta um novo filho a direita (padrão Nullptr)
{
    this->filhoDir = filhodir;//seta um novo filho a direita
}
void Node::setFilhoEsq(Node* filhoesq)//seta um novo filho a esquerda
{
    this->filhoEsq = filhoesq;//seta um novo filho a esquerda
}
void Node::atualizaFB()//atualiza o valor de balanceamento
{
    if(this->getFilhoDir() == nullptr && this->getFilhoEsq() != nullptr)//se o filho a direita for null, coloca o valor -1 no lugar da altura do filho da direita
    {
        this->fb = ((-1) - this->getFilhoEsq()->H);//e coloca o novo valor pra fb
    }
    else if(this->getFilhoDir() != nullptr && this->getFilhoEsq() == nullptr)//se o filho a esquerda for null
    {
        this->fb = (this->getFilhoDir()->H - (-1));//coloca o valor -1 no lugar da altura do filho da esquerda
    }
    else//se ambos forem diferentes de null
    {
        this->fb = ((this->getFilhoDir()->H) - (this->getFilhoEsq()->H) ); //seta o novo valor de balanceamento baseado nas alturas dos filhos
    }
}