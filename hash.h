#include <string>
#include <stdlib.h>
#include <math.h>

#ifndef Included_Hash_H
#define Included_Hash_H

using namespace std;

class Hash {
    private:
        int numBaldes;
    public:
        Hash(int N);
        //int transforma(chave key);
        int hg(int k, int nivel);
        int hgMoreOne(int k, int nivel);
};

#endif
