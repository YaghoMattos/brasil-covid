#ifndef BASEARVORES_H_INCLUDED
#define BASEARVORES_H_INCLUDED

#include <iostream>

using namespace std;

class BaseArvores{
    private:
        int num_comparacoes;
    public:
        BaseArvores();
        ~BaseArvores();

        void resetaComparacoes();
        void aumentaNumComp();

        int getNumComparacoes();
};

#endif // BASEARVORES_H_INCLUDED