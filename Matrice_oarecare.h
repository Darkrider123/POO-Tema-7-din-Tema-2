#ifndef MATRICE_OARECARE_H_
#define MATRICE_OARECARE_H_
#include "Matrice.h"

class Matrice_oarecare:private Matrice
{
    int lin;
    int col;

public:

    Matrice_oarecare();
    Matrice_oarecare(int n, int m);
    ~Matrice_oarecare();

    ///SUPLIMENTAR
    Matrice_oarecare operator =(const Matrice_oarecare &ob);
    Matrice_oarecare (const Matrice_oarecare &ob);
    Matrice_oarecare operator *(const Matrice_oarecare &ob);
    ///SUPLIMENTAR

    friend istream &operator >> (istream &in, Matrice_oarecare &ob);
    friend ostream &operator << (ostream &out, Matrice_oarecare &ob);
};





#endif // MATRICE_OARECARE_H_
