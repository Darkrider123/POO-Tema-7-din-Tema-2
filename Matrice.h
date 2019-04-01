#ifndef MATRICE_H_
#define MATRICE_H_
#include "Complex.h"
using namespace std;

class Matrice:protected NRcomplex
{
protected:

    NRcomplex **a;

public:

    Matrice();
    Matrice(int n, int m);
    ~Matrice();

};


#endif
