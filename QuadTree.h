#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED

#include <iostream>
#include <fstream>
#include "Log.h"
#include "NoQuadtree.h"
#include "CitiesCoordinates.h"

using namespace std;

class QuadTree
{
private:
    NoQuadTree *raiz;

    int compara(NoQuadTree* p, CitiesCoordinates *b);
    void imprimirTelaAux(NoQuadTree* p, int nivel);
    void imprimirAux(NoQuadTree* p, int nivel);
public:
    QuadTree();
    QuadTree(NoQuadTree *_raiz);
    ~QuadTree();

    void inserir(CitiesCoordinates *info);
    bool search(NoQuadTree* p);

    void imprimirTela();
    void imprimir();
};

#endif // QUADTREE_H_INCLUDED