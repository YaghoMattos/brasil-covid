#include "Node.h"

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
//funçoes auxiliares
void Node::atualizaFB()//atualiza o valor de balanceamento
{
    if(this->getFilhoDir() == nullptr && this->getFilhoEsq() != nullptr)//se o filho a direita for null, coloca o valor -1 no lugar da altura do filho da direita
    {
        this->fb = ((-1) - this->getFilhoEsq()->H);//e coloca o novo valor pra fb
    }
    else if(this->getFilhoDir() == nullptr && this->getFilhoEsq() == nullptr) // se os dois filhos forem null 
    {
        this->fb = 0; // fb atualiza para 0
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

void Node::atualizaAltura()//atualiza o valor de balanceamento
{
    if(this->getFilhoDir() == nullptr && this->getFilhoEsq() != nullptr)//se o filho a direita for null, e o filho a esquerda nao for
    {
        this->setAltura(this->getFilhoEsq()->getAltura()+1);//pega o valor da altura do filho a esquerda e soma 1
    }
    else if(this->getFilhoDir() == nullptr && this->getFilhoEsq() == nullptr) // se os dois filhos forem null 
    {
        this->setAltura(0); //altura atualiza para 0
    }
    else if(this->getFilhoDir() != nullptr && this->getFilhoEsq() == nullptr)//se o filho a esquerda for null e o da direita nao for
    {
        this->setAltura(this->getFilhoDir()->getAltura()+1);//pega o valor da altura do filho a direita e soma 1
    }
    else//se ambos forem diferentes de null
    {
        if(this->getFilhoDir()->getAltura() < this->getFilhoEsq()->getAltura()) // se a altura do filho a direita for menor que o da esquerda
        {
            this->setAltura(this->getFilhoEsq()->getAltura()+1);// pega o valor do filho a esquerda e soma 1
        }
        else if(this->getFilhoDir()->getAltura() > this->getFilhoEsq()->getAltura())//se a altura do filho a direita for maior que o da esquerda
        {
            this->setAltura(this->getFilhoDir()->getAltura()+1);// atualiza a altura somando 1 a altura do filho a direita
        }
    }
}