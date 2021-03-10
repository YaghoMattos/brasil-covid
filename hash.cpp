#include <iostream>
#include "hash.h"
#include <sstream>

using namespace std;

Hash::Hash(int N){
    this->numBaldes = N;
}

int Hash::hg(int k, int nivel){
    long int result = 0;
    cout << endl << "-----------------inicio----------------" << endl << "func hash k=" << k << " Balde=" << numBaldes << " nivel=" << nivel << " pow=" << (int)pow(2, nivel) << endl << endl;
    result = k % (numBaldes * (int)pow(2, nivel));
    return result;
}

int Hash::hgMoreOne(int k, int nivel){
    long int result = 0;
    cout << endl << "-----------------inicio----------------" << endl << "func hash k " << k << " Baldes=" << numBaldes << " nivel=" << nivel << " pow=" << (int)pow(2, nivel) << endl << endl;
    result = k % (numBaldes * (int)pow(2, (nivel + 1)));
    return result;
}
