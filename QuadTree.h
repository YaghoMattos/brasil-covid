#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED

#include <iostream>
#include "NoQuadtree.h"
#include "CitiesCoordinates.h"

using namespace std;

class QuadTree
{
private:
    NoQuadTree *raiz;

    int compara(CitiesCoordinates *a, CitiesCoordinates *b);

public:
    QuadTree();
    QuadTree(NoQuadTree *_raiz);
    ~QuadTree();

    void inserir(CitiesCoordinates *info);
};

#endif // QUADTREE_H_INCLUDED