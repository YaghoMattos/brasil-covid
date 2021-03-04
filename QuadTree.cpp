#include "QuadTree.h"

QuadTree::QuadTree() { this->raiz = nullptr; }
QuadTree::QuadTree(NoQuadTree *_raiz) { this->raiz = _raiz; }
QuadTree::~QuadTree() {}

void QuadTree::inserir(CitiesCoordinates *info)
{
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

        while (true)
        {
            if (p->getX() < novoNo->getX())
            {
                if (p->getY() < novoNo->getX())
                {
                    if (p->getSuldeste() == nullptr){
                        //cout << "Suldeste\n";
                        p->setSuldeste(novoNo);
                        break;
                    }else
                        p = p->getSuldeste();
                }
                else
                {
                    if (p->getNordeste() == nullptr){
                        //cout << "Nordeste\n";
                        p->setNordeste(novoNo);
                        break;
                    }else
                        p = p->getNordeste();
                }
            }
            else if (p->getY() < novoNo->getY())
            {
                if (p->getSuldoeste() == nullptr){
                    //cout << "Suldeste\n";
                    p->setSuldeste(novoNo);
                    break;
                }else
                    p = p->getSuldoeste();
            }
            else
            {
                if (p->getNoroeste() == nullptr){
                    //cout << "Noroeste\n";
                    p->setNoroeste(novoNo);
                    break;
                }else
                    p = p->getNoroeste();
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
        if (no->getY() < p->getX())
        {
            no = no->getSuldeste();
        }
        else
        {
            no = no->getNordeste();
        }
    }
    else if (no->getY() < p->getY())
    {
        no = no->getSuldoeste();
    }
    else
        no = no->getNoroeste();

    return true;
}