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
    Base(){};
    ~Base(){};

    string getSeparadorDiretorio()
    {
#ifdef _WIN32
        return "\\";
#else
        return "/";
#endif
    };

    const vector<string> explode(const string &s, const char &c)
    {
        if (s == "" || s.length() <= 0)
        {
            cout << "explode(): string vazia" << endl;
            return vector<string>();
        }

        string buff{""};
        vector<string> v;

        for (auto n : s)
        {
            if (n != c)
                buff += n;
            else if (n == c && buff != "")
            {
                v.push_back(buff);
                buff = "";
            }
        }
        if (buff != "")
            v.push_back(buff);

        return v;
    };

    int strToInt(string s)
    {
        int i = stoi(s);
        if (errno == ERANGE)
        {
            cout << "int range error on " << s << endl;
            errno = 0;
            i = 0;
        }
        //cout << "I: " << i << endl;
        return i;
    };

    float strToFloat(string s)
    {
        float i = stof(s);
        if (errno == ERANGE)
        {
            cout << "int range error on " << s << endl;
            errno = 0;
            i = 0;
        }

        //cout << "I: " << i << endl;
        return i;
    };

    bool strToBool(string s)
    {
        return (s == "TRUE" || s == "true");
    };
};

#endif // LEITURA_BASE_H_INCLUDED