#include "NoQuadTree.h"

NoQuadTree::NoQuadTree()
{
    this->info = nullptr;
    this->x = 0;
    this->y = 0;
    this->nordeste = nullptr;
    this->suldeste = nullptr;
    this->suldoeste = nullptr;
    this->suldeste = nullptr;
}

NoQuadTree::NoQuadTree(CitiesCoordinates *_info)
{
    this->info = _info;
    this->x = info->latitude;
    this->y = info->longitude;
    this->nordeste = nullptr;
    this->suldeste = nullptr;
    this->suldoeste = nullptr;
    this->suldeste = nullptr;
}

NoQuadTree *NoQuadTree::getNordeste() { return this->nordeste; }
NoQuadTree *NoQuadTree::getSuldeste() { return this->suldeste; }
NoQuadTree *NoQuadTree::getSuldoeste() { return this->suldoeste; }
NoQuadTree *NoQuadTree::getNoroeste() { return this->noroeste; }
CitiesCoordinates *NoQuadTree::getInfo() { return this->info; }

void NoQuadTree::setInfo(CitiesCoordinates *var)
{
    this->info = var;
    this->x = var->latitude;
    this->y = var->longitude;
}

void NoQuadTree::setNordeste(NoQuadTree *var) { this->nordeste = var; }
void NoQuadTree::setSuldeste(NoQuadTree *var) { this->suldeste = var; }
void NoQuadTree::setSuldoeste(NoQuadTree *var) { this->suldoeste = var; }
void NoQuadTree::setNoroeste(NoQuadTree *var) { this->noroeste = var; }

float NoQuadTree::getX() { return this->x; }
float NoQuadTree::getY() { return this->y; }