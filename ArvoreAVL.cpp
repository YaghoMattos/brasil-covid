#include "ArvoreAVL.h"

ArvoreAVL::ArvoreAVL()
{
    this->raiz = nullptr;
    this->resetaComparacoes();
}

ArvoreAVL::~ArvoreAVL()
{
    delete raiz;
}

int ArvoreAVL::getAltura(NoAVL *p)
{
    if (p == nullptr)
    {
        return -1;
    }

    return p->getAltura();
}

int ArvoreAVL::getBalanceamento(NoAVL *p)
{   
    cout << "GET BALANCEAMENTO" << endl;
    if (p != nullptr)
    {
        cout << "p!=null\n";
        return p->getSubArvores(1)->getAltura() - p->getSubArvores(0)->getAltura();
    }
    return 0;
}

void ArvoreAVL::insert(int valor)
{
    //cout << "Inserindo: " << valor << endl;
    this->raiz = insertAux(this->raiz, valor);
}

NoAVL *ArvoreAVL::insertAux(NoAVL *p, int valor)
{
    //cout << "Inserir Auxiliar" << endl;
    if (p == nullptr)
    {
        p = new NoAVL(valor);
        return p;
    }
    else
    {
        cout << "No p nao nulo" << endl;
        if (valor < p->getValor())
        {
            this->aumentaNumComp();
            cout << "1" << endl;
            p->setSubArvores(0, this->insertAux(p->getSubArvores(0), valor));
        }
        else
        {
            cout << "2" << endl;
            p->setSubArvores(1, this->insertAux(p->getSubArvores(1), valor));
        }
    }

    if (p->getSubArvores(0)->getAltura() > p->getSubArvores(1)->getAltura())
    {
        cout << "Atualizando Altura" << endl;
        p->atualizaAltura(p->getSubArvores(0)->getAltura() + 1);
    }else
    {
        cout << "Atualizando Altura" << endl;
        p->atualizaAltura(p->getSubArvores(1)->getAltura() + 1);
    }

    int fatorB = getBalanceamento(p);

    if (fatorB == 2)
    {
        NoAVL *no = p->getSubArvores(1);
        int fatorB_aux = getBalanceamento(no);
        if (fatorB_aux == 1 || fatorB_aux == 0)
            return rotSimplesEsq(p);

        if (fatorB_aux == -1)
            return rotDuplaEsq(p);
    }

    if (fatorB == -2)
    {
        NoAVL *no = p->getSubArvores(0);
        int fatorB_aux = getBalanceamento(no);
        if (fatorB_aux == 1 || fatorB_aux == 0)
            return rotSimplesDir(p);

        if (fatorB_aux == -1)
            return rotDuplaDir(p);
    }

    return p;
}

void ArvoreAVL::imprimir()
{
    NoAVL *p = raiz;

    imprimeAux(p, 0);
}

void ArvoreAVL::imprimeAux(NoAVL *p, int nivel)
{
    if (p != nullptr)
    {
        cout << "Valor: " << p->getValor() << " Nivel: " << nivel << endl;
        imprimeAux(p->getSubArvores(0), nivel + 1);
        imprimeAux(p->getSubArvores(1), nivel + 1);
    }
}

NoAVL *ArvoreAVL::rotSimplesEsq(NoAVL *p)
{
    cout << "Rotacao Simples Esquerda\n";
    NoAVL *no = p->getSubArvores(1);

    p->setSubArvores(1, no->getSubArvores(0));
    no->setSubArvores(0, p);

    if (p->getSubArvores(0)->getAltura() > p->getSubArvores(1)->getAltura())
    {
        p->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        no->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
    }
    else
    {
        p->atualizaAltura(1 + p->getSubArvores(1)->getAltura());
        no->atualizaAltura(1 + p->getSubArvores(1)->getAltura());
    }

    return no;
}
NoAVL *ArvoreAVL::rotSimplesDir(NoAVL *p)
{
    cout << "Rotacao Simples Direita\n";
    NoAVL *no = p->getSubArvores(0);

    p->setSubArvores(0, no->getSubArvores(1));
    no->setSubArvores(1, p);

    if (p->getSubArvores(0)->getAltura() > p->getSubArvores(1)->getAltura())
    {
        p->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        no->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
    }
    else
    {
        p->atualizaAltura(1 + p->getSubArvores(1)->getAltura());
        no->atualizaAltura(1 + p->getSubArvores(1)->getAltura());
    }

    return no;
}


NoAVL *ArvoreAVL::rotDuplaEsq(NoAVL *p)
{
    cout << "Rotacao Dupla Esquerda\n";
    NoAVL *no = p->getSubArvores(1);
    NoAVL *n = no->getSubArvores(0);

    p->setSubArvores(1,n->getSubArvores(0));
    no->setSubArvores(0,n->getSubArvores(1));
    n->setSubArvores(0,p);
    n->setSubArvores(1,no);

    
    if (p->getSubArvores(0)->getAltura() > p->getSubArvores(1)->getAltura())
    {
        p->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        no->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        n->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
    }
    else
    {
        p->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        no->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        n->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
    }
    return n;
}

NoAVL *ArvoreAVL::rotDuplaDir(NoAVL *p)
{
    cout << "Rotacao Dupla Direita\n";
    NoAVL *no = p->getSubArvores(0);
    NoAVL *n = no->getSubArvores(1);

    p->setSubArvores(0,n->getSubArvores(0));
    no->setSubArvores(1,n->getSubArvores(1));
    n->setSubArvores(1,p);
    n->setSubArvores(0,no);

    
    if (p->getSubArvores(0)->getAltura() > p->getSubArvores(1)->getAltura())
    {
        p->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        no->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        n->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
    }
    else
    {
        p->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        no->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
        n->atualizaAltura(1 + p->getSubArvores(0)->getAltura());
    }
    return n;
}
