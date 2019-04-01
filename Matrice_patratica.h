#ifndef MATRICE_PATRATICA_H_
#define MATRICE_PATRATICA_H_
#include "Matrice.h"


class Matrice_patratica:private Matrice
{
    int dim;

public:
    Matrice_patratica();
    Matrice_patratica(int n);
    ~Matrice_patratica();
    NRcomplex Determinant();
    void VerificareTriunghiularitate();

    ///SUPLIMENTAR
    Matrice_patratica(const Matrice_patratica &ob);
    Matrice_patratica operator = (const Matrice_patratica&ob);
   Matrice_patratica operator +(const Matrice_patratica &ob);
   Matrice_patratica operator *(const Matrice_patratica &ob);
   Matrice_patratica transpusa();
 Matrice_patratica adjuncta();
    Matrice_patratica inversa();
    ///SUPLIMENTAR

    friend istream &operator >> (istream &in, Matrice_patratica &ob);
    friend ostream &operator << (ostream &out, Matrice_patratica &ob);

};

#endif // MATRICE_PATRATICA_H_
