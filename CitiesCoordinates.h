#ifndef CITIESCOORDINATES_H
#define CITIESCOORDINATES_H

#include <iostream>

using namespace std;

class CitiesCoordinates{
    public:
        int codigo_estado;
        int codigo_cidade;
        string nome_cidade;
        double latitude;
        double longitude;
        bool capital;
};

#endif // CITIESCOORDINATES_H