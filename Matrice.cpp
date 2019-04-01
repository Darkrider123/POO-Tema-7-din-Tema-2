#include "Matrice.h"
    Matrice::Matrice()
    {

    }

    Matrice::Matrice(int n,int m)
    {int i,j;
           a=new NRcomplex* [n];
    for (i=0;i<n;i++)
        a[i]=new NRcomplex [m];

        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
            a[i][j].setnumarla0();
    }

    Matrice::~Matrice()
    {

    }
