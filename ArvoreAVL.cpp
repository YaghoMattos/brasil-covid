#include "ArvoreAVL.h"
ArvoreAVL::ArvoreAVL() { this->raiz = nullptr; }

ArvoreAVL::~ArvoreAVL() { this->clear(); }

void ArvoreAVL::inserir(int valor)
{
    bool hAlterada = false;

    this->inserirAux(this->raiz, valor, hAlterada,nullptr);
}

bool ArvoreAVL::search(int valor)
{
    NoAVL *p = this->raiz;

    while (p != nullptr)
    {
        if (valor > p->getValor())
        {
            p = p->getSubArvores(1);
        }
        else if (valor < p->getValor())
        {
            p = p->getSubArvores(0);
        }
        else if (valor == p->getValor())
        {
            return true;
        }
    }

    return false;
}

void ArvoreAVL::clear()
{
    delete raiz;
    this->raiz = nullptr;
}

void ArvoreAVL::imprimir()
{
    cout << endl
         << "Impressao Arvore AVL" << endl;

    NoAVL *p = this->raiz;
    while (p != nullptr)
    {
        cout << "Valor de p " << p->getValor() << endl;
        p = p->pai;
    }
    cout << "P nulo\n";
    //imprimirAux(p, 0);
}

void ArvoreAVL::imprimirAux(NoAVL *p, int nivel)
{
    cout << "Valor: " << p->getValor() << " Nivel: " << nivel << endl;
    if (p->getSubArvores(0) != nullptr)
    {
        imprimirAux(p->getSubArvores(0), nivel + 1);
    }
    if (p->getSubArvores(1) != nullptr)
    {
        imprimirAux(p->getSubArvores(1), nivel + 1);
    }
}

void ArvoreAVL::rotacaoDupla(NoAVL *&p, int dir)
{
    int oposto = this->oposto(dir);
    NoAVL *filho = p->getSubArvores(dir)->getSubArvores(oposto);
    p->getSubArvores(dir)->setSubArvores(oposto, filho->getSubArvores(dir));
    filho->setSubArvores(dir, p->getSubArvores(dir));
    p->setSubArvores(dir, filho);
    filho = p->getSubArvores(dir);
    p->setSubArvores(dir, filho->getSubArvores(oposto));
    filho->setSubArvores(oposto, p);
    p = filho;
}

void ArvoreAVL::rotacaoSimples(NoAVL *&p, int dir)
{
    int oposto = this->oposto(dir);
    NoAVL *filho = p->getSubArvores(dir);
    p->setSubArvores(dir, filho->getSubArvores(oposto));
    filho->setSubArvores(oposto, p);
    p = filho;
}

void ArvoreAVL::aumentaBalanceamento(NoAVL *p, int dir)
{
    int oposto = this->oposto(dir);
    int balance = p->getSubArvores(dir)->getSubArvores(oposto)->getBalanco();

    if (balance == dir)
    {
        p->setBalanco(2); //Verifica se é igual
        p->getSubArvores(dir)->setBalanco(oposto);
    }
    else
    {
        p->setBalanco(p->getSubArvores(dir)->getBalanco());
    }
    p->getSubArvores(dir)->getSubArvores(oposto)->setBalanco(2);
}

void ArvoreAVL::rebalanceamentoInserir(NoAVL *&p, int dir, bool hAlterada)
{
    int oposto = this->oposto(dir);

    if (p->getBalanco() == dir)
    {
        if (p->getSubArvores(dir)->getBalanco() == dir)
        {
            p->getSubArvores(dir)->setBalanco(2);
            p->setBalanco(2);

            this->rotacaoSimples(p, dir);
        }
        else
        {
            this->aumentaBalanceamento(p, dir);
            this->rotacaoDupla(p, dir);
        }
        hAlterada = false;
    }
    else if (p->getBalanco() == oposto)
    {
        p->setBalanco(2);
        hAlterada = false;
    }
    else
    {
        p->setBalanco(dir);
    }
}

void ArvoreAVL::inserirAux(NoAVL *&p, int valor, bool hAlterada, NoAVL *pai)
{
    if (p == nullptr)
    {
        p = new NoAVL(valor);
        p->pai = pai;
        hAlterada = true;
        return;
    }
    else if (p->getValor() == valor)
    {
        return;
    }
    else
    {
        //cout << "Terceiro Else" << endl;
        int dir = (valor > p->getValor()) ? 1 : 0;
        //cout << "DIR: " << dir << endl;
        hAlterada = false;
        NoAVL *&a = p = p->getSubArvores(dir);
        inserirAux(a, valor, hAlterada, p);
        if (hAlterada)
        {
            this->rebalanceamentoInserir(p, dir, hAlterada);
        }
    }
}

int ArvoreAVL::oposto(int dir)
{
    return (dir == 1) ? 0 : 1;
}