#include <iostream>
#include "hash.h"

using namespace std;

Hash::Hash(int N){
    this->numBaldes = N;
}

int Hash::hg(int k, int nivel){
    int result = 0;
    cout << endl << "|||||||| hash por hg ||||||||" << endl << "func hash k = " << k << ", baldes = " << numBaldes << ", nivel = " << nivel << ", pow = " << (int)pow(2, nivel) << ", k % " << numBaldes * (int)pow(2, (nivel)) << endl << endl;
    result = k % (numBaldes * (int)pow(2, nivel));
    return result;
}

int Hash::hgMoreOne(int k, int nivel){
    int result = 0;
    cout << endl << "|||||||| hash por hg+1 ||||||||" << endl << "func hash k = " << k << ", baldes = " << numBaldes << ", nivel = " << nivel << ", pow = " << (int)pow(2, nivel) << ", k % " << numBaldes * (int)pow(2, (nivel + 1)) << endl << endl;
    result = k % (numBaldes * (int)pow(2, (nivel + 1)));
    cout << "result hg+1 = " << k % (numBaldes * (int)pow(2, (nivel + 1))) << endl;
    return result;
}
