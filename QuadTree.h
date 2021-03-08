#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED

#include <iostream>
#include "BaseArvores.h"
#include "NoQuadtree.h"
#include "CitiesCoordinates.h"

using namespace std;

class QuadTree : public BaseArvores
{
private:
    NoQuadTree *raiz;

    int compara(NoQuadTree* p, CitiesCoordinates *b);

public:
    QuadTree();
    QuadTree(NoQuadTree *_raiz);
    ~QuadTree();

    void inserir(CitiesCoordinates *info);
    bool search(NoQuadTree* p);
};

#endif // QUADTREE_H_INCLUDED