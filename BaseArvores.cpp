#include "BaseArvores.h"

BaseArvores::BaseArvores()
{
    this->num_comparacoes = 0;
}
BaseArvores::~BaseArvores()
{
}

void BaseArvores::resetaComparacoes(){
    this->num_comparacoes = 0;
}

void BaseArvores::aumentaNumComp(){
    this->num_comparacoes++;
}

int BaseArvores::getNumComparacoes(){
    return this->num_comparacoes;
}