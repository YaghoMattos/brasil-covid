#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED

#include <iostream>
#include "../nos/NoQuadtree.h"
#include "../CitiesCoordinates.h"

using namespace std;

class QuadTree
{
private:
    NoQuadTree *raiz;

    int compara(CitiesCoordinates *a, CitiesCoordinates *b)
    {
        /**
     * -1 - São Iguais
     * 0 - Suldeste
     * 1 - Nordeste
     * 2 - Suldoeste
     * 3 - Noroeste
     */

        if (a->latitude == b->latitude && a->longitude == b->longitude)
        {
            return -1;
        }
        else if (a->latitude < b->latitude)
        {
            if (a->longitude < b->longitude)
            {
                return 0; //Suldeste
            }
            else
            {
                return 1; //Nordeste
            }
        }
        else if (a->longitude < b->longitude)
        {
            return 2; //Suldoeste
        }
        else
        {
            return 3; //Noroeste
        }
    }

public:
    QuadTree() { this->raiz = nullptr; }
    QuadTree(NoQuadTree *_raiz) { this->raiz = _raiz; }
    ~QuadTree() {}

    void inserir(CitiesCoordinates *info)
    {
        //cout << "Inserindo Novo No: " << info->codigo_cidade << endl;

        if (this->raiz == nullptr)
        {
            this->raiz = new NoQuadTree(info);
            return;
        }
        else
        {
            NoQuadTree *p = this->raiz;

            while (p != nullptr)
            {
                int comp = this->compara(p->getInfo(), info);
                //cout << "Comp result: " << comp << endl;
                if (comp == 0)
                {
                    p = p->getSuldeste();
                }
                else if (comp == 1)
                {
                    p = p->getNordeste();
                }
                else if (comp == 2)
                {
                    p = p->getSuldoeste();
                }
                else if (comp == 3)
                {
                    p = p->getNoroeste();
                }
                else if (comp == -1)
                {
                    cout << "Ja existe na arvore" << endl;
                    return;
                }
            }

            //Confere se p é realmente nulo e adiciona o novo nó na árvore
            if (p == nullptr)
            {
                NoQuadTree *novoNo = new NoQuadTree(info);
                p = novoNo;
            }
        }
    };
};

#endif // QUADTREE_H_INCLUDED