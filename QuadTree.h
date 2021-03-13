#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include "Log.h"
#include "BaseArvores.h"
#include "NoQuadtree.h"
#include "CitiesCoordinates.h"

using namespace std;

class QuadTree : public BaseArvores
{
private:
    NoQuadTree *raiz;
    
    int compara(NoQuadTree *p, CitiesCoordinates *b);
    void imprimirTelaAux(NoQuadTree *p, int nivel);
    void imprimirAux(NoQuadTree *p, int nivel);
    void searchIntervalAux(NoQuadTree *p, float x1, float y1, float x2, float y2);

public:
    QuadTree();
    QuadTree(NoQuadTree *_raiz);
    ~QuadTree();
    
    vector<CitiesCoordinates *> data;

    void inserir(CitiesCoordinates *info);
    void searchInterval(float x1, float y1, float x2, float y2);

    void imprimirTela();
    void imprimir();
};

#endif // QUADTREE_H_INCLUDED