#include "NoAVL.h"

NoAVL::NoAVL(int valor)
{
    this->valor = valor;
    this->balanco = 0;
    this->pai = nullptr;
    this->subArvoreEsquerda = nullptr;
    this->subArvoreDireita = nullptr;
}

NoAVL::~NoAVL()
{
    delete this->subArvoreEsquerda;
    delete this->subArvoreEsquerda;
}

void NoAVL::setBalanco(int n)
{
    this->balanco = n;
}

int NoAVL::getBalanco() { return this->balanco; }

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