#include <iostream>
#include "hash.h"

using namespace std;

Hash::Hash(int Nb){
    this->numBaldes = Nb;
}

int Hash::hg(int k, int nivel){
    int result = 0;
    cout << endl << "-----------------inicio hg----------------" << endl << "func hash k=" << k << " Balde=" << numBaldes << " nivel=" << nivel << " pow=" << (int)pow(2, nivel) << endl << endl;
    result = k % (numBaldes * (int)pow(2, nivel));
    return result;
}

int Hash::hgMoreOne(int k, int nivel){
    int result = 0;
    cout << endl << "-----------------inicio hg+1----------------" << endl << "func hash k " << k << " Baldes=" << numBaldes << " nivel=" << nivel << " pow=" << (int)pow(2, nivel) << endl << endl;
    result = k % (numBaldes * (int)pow(2, (nivel + 1)));
    return result;
}
