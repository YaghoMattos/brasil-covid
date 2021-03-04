#ifndef NOQUADTREE_H_INCLUDED
#define NOQUADTREE_H_INCLUDED

#include <iostream>

#include "CitiesCoordinates.h"

using namespace std;

class NoQuadTree
{
private:
    CitiesCoordinates *info;
    float x;
    float y;
    
    NoQuadTree *nordeste;
    NoQuadTree *noroeste;
    NoQuadTree *suldeste;
    NoQuadTree *suldoeste;

public:
    NoQuadTree();
    NoQuadTree(CitiesCoordinates *_info);
    ~NoQuadTree();

    NoQuadTree *getNordeste();
    NoQuadTree *getSuldeste();
    NoQuadTree *getSuldoeste();
    NoQuadTree *getNoroeste();

    CitiesCoordinates *getInfo();
    void setInfo(CitiesCoordinates *var);

    void setNordeste(NoQuadTree *var);
    void setSuldeste(NoQuadTree *var);
    void setSuldoeste(NoQuadTree *var);
    void setNoroeste(NoQuadTree *var);

    float getX();
    float getY();
};

#endif // NOQUADTREE_H_INCLUDED