#include <iostream>
#include "hash.h"
#include <sstream>

using namespace std;

Hash::Hash(int N){
    this->numBaldes = N;
}

int Hash::hg(int k, int nivel){
    cout << "k " << k << " Baldes " << numBaldes << " pow " << (int)pow(2, nivel) << endl;
    return k % (numBaldes * (int)pow(2, nivel));
}

int Hash::hgMoreOne(int k, int nivel){
    return k % (numBaldes * (int)pow(2, (nivel + 1)));
}