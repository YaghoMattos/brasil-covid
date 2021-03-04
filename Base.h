#ifndef LEITURA_BASE_H_INCLUDED
#define LEITURA_BASE_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <random>

using namespace std;

class Base
{
private:
    string caminho_diretorio;

public:
    Base();
    ~Base();

    string getSeparadorDiretorio();
    const vector<string> explode(const string &s, const char &c);
    int strToInt(string s);
    float strToFloat(string s);
    bool strToBool(string s);
};

#endif // LEITURA_BASE_H_INCLUDED