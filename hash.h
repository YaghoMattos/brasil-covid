#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Hash {
    private:
        int numBaldes;
    public:
        Hash(int N);
        int hg(int k, int nivel);
        int hgMoreOne(int k, int nivel);
};
