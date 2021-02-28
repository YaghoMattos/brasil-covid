#ifndef NOQUADTREE_H_INCLUDED
#define NOQUADTREE_H_INCLUDED

#include <iostream>

#include "../CitiesCoordinates.h"

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
    NoQuadTree()
    {
        this->info = nullptr;
        this->x = 0;
        this->y = 0;
        this->nordeste = nullptr;
        this->suldeste = nullptr;
        this->suldoeste = nullptr;
        this->suldeste = nullptr;
    };
    NoQuadTree(CitiesCoordinates *_info)
    {
        this->info = _info;
        this->x = info->latitude;
        this->y = info->longitude;
        this->nordeste = nullptr;
        this->suldeste = nullptr;
        this->suldoeste = nullptr;
        this->suldeste = nullptr;
    };
    ~NoQuadTree();

    NoQuadTree *getNordeste() { return this->nordeste; };
    NoQuadTree *getSuldeste() { return this->suldeste; };
    NoQuadTree *getSuldoeste() { return this->suldoeste; };
    NoQuadTree *getNoroeste() { return this->noroeste; };

    CitiesCoordinates *getInfo() { return this->info; };
    void setInfo(CitiesCoordinates *var)
    {
        this->info = var;
        this->x = var->latitude;
        this->y = var->longitude;
    };

    void setNordeste(NoQuadTree *var) { this->nordeste = var; };
    void setSuldeste(NoQuadTree *var) { this->suldeste = var; };
    void setSuldoeste(NoQuadTree *var) { this->suldoeste = var; };
    void setNoroeste(NoQuadTree *var) { this->noroeste = var; };

    float getX() { return this->x; };
    float getY() { return this->y; };
};

#endif // NOQUADTREE_H_INCLUDED