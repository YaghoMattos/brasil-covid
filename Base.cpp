#include "Base.h"

Base::Base() {}

Base::~Base() {}

string Base::getSeparadorDiretorio()
{
#ifdef _WIN32
    return "\\";
#else
    return "/";
#endif
}

const vector<string> Base::explode(const string &s, const char &c)
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
}

int Base::strToInt(string s)
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
}

float Base::strToFloat(string s)
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
}

bool Base::strToBool(string s)
{
    return (s == "TRUE" || s == "true");
}

int Base::getRand(int maxRand)
{
    uniform_int_distribution<int> distribuition(0, maxRand);
    return distribuition(generator);
}