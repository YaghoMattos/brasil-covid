#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

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
    default_random_engine generator;

public:
    Base();
    ~Base();

    string getSeparadorDiretorio();
    const vector<string> explode(const string &s, const char &c);
    int strToInt(string s);
    float strToFloat(string s);
    bool strToBool(string s);
    int getRand(int maxRand);
};

#endif // BASE_H_INCLUDED