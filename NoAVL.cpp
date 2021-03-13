#include "NoAVL.h"

NoAVL::NoAVL(int valor)
{
    this->valor = valor;
    this->balanceamento = 0;
    this->altura = 0;
    this->subArvoreEsquerda = nullptr;
    this->subArvoreDireita = nullptr;
}

NoAVL::~NoAVL()
{
    delete this->subArvoreEsquerda;
    delete this->subArvoreEsquerda;
}

void NoAVL::setBalanceamento(int n)
{
    this->balanceamento = n;
}

int NoAVL::getAltura()
{
    return this->altura;
}

int NoAVL::getBalanceamento() { return this->balanceamento; }

int NoAVL::getValor() { return this->valor; }

NoAVL *NoAVL::getSubArvores(int n)
{
    NoAVL *aux = nullptr;

    if (n == 0)
    {
        return this->subArvoreEsquerda;
    }
    else if (n == 1)
    {
        return this->subArvoreDireita;
    }

    return nullptr;
}

void NoAVL::setSubArvores(int n, NoAVL *p)
{

    if (n == 0)
    {
        this->subArvoreEsquerda = p;
    }
    else if (n == 1)
    {
        this->subArvoreDireita = p;
    }
}

void NoAVL::atualizaAltura(int k){
    this->altura = k;
}