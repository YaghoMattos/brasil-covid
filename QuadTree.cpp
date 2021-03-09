#include "QuadTree.h"

QuadTree::QuadTree()
{
    this->raiz = nullptr;
    this->resetaComparacoes();
}
QuadTree::QuadTree(NoQuadTree *_raiz)
{
    this->raiz = _raiz;
    this->resetaComparacoes();
}
QuadTree::~QuadTree() {}

void QuadTree::inserir(CitiesCoordinates *info)
{
    //cout << "Inserindo No: " << info->codigo_cidade << endl;
    if (this->raiz == nullptr)
    {
        //cout << "Raiz\n";
        this->raiz = new NoQuadTree(info);
        return;
    }
    else
    {
        NoQuadTree *novoNo = new NoQuadTree(info);

        if (!this->search(novoNo))
        {
            cout << "O no ja existe na arvore" << endl;
            return;
        }

        NoQuadTree *p = this->raiz;
        bool flag = true;
        while (flag)
        {
            if (p->getX() < novoNo->getX())
            {
                this->aumentaNumComp();
                if (p->getY() < novoNo->getX())
                {
                    this->aumentaNumComp();
                    if (p->getSuldeste() == nullptr)
                    {
                        //cout << "Suldeste\n";
                        p->setSuldeste(novoNo);
                        flag = false;
                    }
                    else
                    {
                        //cout << "Proximo Suldeste\n";
                        p = p->getSuldeste();
                    }
                }
                else
                {
                    if (p->getNordeste() == nullptr)
                    {
                        //cout << "Nordeste\n";
                        p->setNordeste(novoNo);
                        flag = false;
                    }
                    else
                    {
                        //cout << "Proximo Nordeste\n";
                        p = p->getNordeste();
                    }
                }
            }
            else if (p->getY() < novoNo->getY())
            {
                this->aumentaNumComp();
                if (p->getSuldoeste() == nullptr)
                {
                    //cout << "Suldoeste\n";
                    p->setSuldoeste(novoNo);
                    flag = false;
                }
                else
                {
                    //cout << "Proximo Suldoeste\n";
                    p = p->getSuldoeste();
                }
            }
            else
            {
                if (p->getNoroeste() == nullptr)
                {
                    //cout << "Noroeste\n";
                    p->setNoroeste(novoNo);
                    flag = false;
                }
                else
                {
                    //cout << "Proximo Noroeste\n";
                    p = p->getNoroeste();
                }
            }
        }
    }
}

int QuadTree::compara(NoQuadTree *p, CitiesCoordinates *b)
{
    /**
     * -1 - São Iguais
     * 0 - Suldeste
     * 1 - Nordeste
     * 2 - Suldoeste
     * 3 - Noroeste
     */

    if (p->getX() == b->latitude && p->getY() == b->longitude)
    {
        return -1;
    }
    else if (p->getX() < b->latitude)
    {
        if (p->getY() < b->longitude)
        {
            return 0; //Suldeste
        }
        else
        {
            return 1; //Nordeste
        }
    }
    else if (p->getY() < b->longitude)
    {
        return 2; //Suldoeste
    }
    else
    {
        return 3; //Noroeste
    }
}

bool QuadTree::search(NoQuadTree *p)
{
    if (this->raiz == nullptr)
        return false;

    NoQuadTree *no = this->raiz;
    if (no->getX() < p->getX())
    {
        this->aumentaNumComp();
        if (no->getY() < p->getX())
        {
            this->aumentaNumComp();
            no = no->getSuldeste();
        }
        else
        {
            no = no->getNordeste();
        }
    }
    else if (no->getY() < p->getY())
    {
        this->aumentaNumComp();
        no = no->getSuldoeste();
    }
    else
        no = no->getNoroeste();

    return true;
}

void QuadTree::imprimirTela()
{
    NoQuadTree *p = this->raiz;
    int nivel = 0;
    this->imprimirTelaAux(p, nivel);
}

void QuadTree::imprimirTelaAux(NoQuadTree *p, int nivel)
{
    if (p != nullptr)
    {
        cout << "( nivel: " << nivel << " )";
        cout << "---> " << p->getInfo()->codigo_cidade << " X: " << p->getX() << " Y: " << p->getY() << endl;

        imprimirTelaAux(p->getNordeste(), nivel + 1);
        imprimirTelaAux(p->getNoroeste(), nivel + 1);
        imprimirTelaAux(p->getSuldeste(), nivel + 1);
        imprimirTelaAux(p->getSuldoeste(), nivel + 1);
    }

    return;
}

void QuadTree::imprimir()
{
    Log::getInstance().iniciaArquivoSaida("Saidas\\Quadtree.txt");

    NoQuadTree *p = this->raiz;
    int nivel = 0;
    this->imprimirAux(p, nivel);
}

void QuadTree::imprimirAux(NoQuadTree *p, int nivel)
{
    string line = "";
    if (p != nullptr)
    {
        line += "( nivel: " + to_string(nivel) + " )";
        line += "---> " + to_string(p->getInfo()->codigo_cidade);
        line += " X: " + to_string(p->getX()) + " Y: " + to_string(p->getY());

        Log::getInstance().lineArquivo(line);

        imprimirAux(p->getNordeste(), nivel + 1);
        imprimirAux(p->getNoroeste(), nivel + 1);
        imprimirAux(p->getSuldeste(), nivel + 1);
        imprimirAux(p->getSuldoeste(), nivel + 1);
    }
}