#include "Matrice_oarecare.h"


Matrice_oarecare::Matrice_oarecare()
{
        lin=0;
        col=0;
}

 Matrice_oarecare::Matrice_oarecare(int n, int m):Matrice(n,m)
{ lin=n;col=m;}

Matrice_oarecare::~Matrice_oarecare()
{
    int i;

    for (i=0;i<lin;i++)
        delete[] a[i];
    delete[] a;

}

istream &operator >> (istream &in, Matrice_oarecare &ob)
{

    if (ob.lin>0||ob.col>0)
        {
            int i;

    for (i=0;i<ob.lin;i++)
        delete[] ob.a[i];
    delete[] ob.a;

        }

    cout<<"Introduceti nr de linii: ";
    in>>ob.lin;
    if (ob.lin<=0)
    {
        ob.lin=0;
        ob.col=0;
        return in;
    }
    cout<<"Introduceti nr de coloane: ";
    in>>ob.col;
    if (ob.lin<=0||ob.col<=0)
    {
        ob.lin=0;
        ob.col=0;
        return in;
    }
     cout<<"\n";
     int i,j;

           ob.a=new NRcomplex* [ob.lin];
    for (i=0;i<ob.lin;i++)
        ob.a[i]=new NRcomplex [ob.col];

    for (i=0;i<ob.lin;i++)
        for (j=0;j<ob.col;j++)
        in>>ob.a[i][j];

        cout<<"\n";

    return in;

}

ostream &operator << (ostream &out, Matrice_oarecare &ob)
{
    int i,j;
    for (i=0;i<ob.lin;i++)
    {
        for (j=0;j<ob.col;j++)
        out<<ob.a[i][j]<<"   ";
       out<<"\n\n";
    }
    return out;
}


///SUPLIMENTAR
Matrice_oarecare Matrice_oarecare::operator =(const Matrice_oarecare &ob)
{ if (this==&ob) return *this;
    int i,j;

    if (lin>0&&col>0)
    {
        for (i=0;i<lin;i++)
           delete[] a[i];

           delete[] a;
    }

    lin=ob.lin;
    col=ob.col;

    a=new NRcomplex* [lin];
    for (i=0;i<lin;i++)
        a[i]=new NRcomplex [col];

    for (i=0;i<lin;i++)
        for (j=0;j<col;j++)
         a[i][j]=ob.a[i][j];

    return *this;

}

Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare &ob)
{
        lin=ob.lin;
        col=ob.col;
        int i,j;

        a=new NRcomplex* [lin];
        for (i=0;i<lin;i++)
            a[i]=new NRcomplex [col];

        for (i=0;i<lin;i++)
            for (j=0;j<col;j++)
            a[i][j]=ob.a[i][j];

}


Matrice_oarecare Matrice_oarecare::operator *(const Matrice_oarecare &ob)
{
    int i,j,l;
    NRcomplex z;
    Matrice_oarecare c(lin,col);
    if (col!=ob.lin) return c;


     for (i=0;i<c.lin;i++)
     {

        for (j=0;j<c.col;j++)
     {
         z.setnumarla0();

        for (l=0;l<ob.lin;l++)
            z=z+a[i][l]*ob.a[l][j];


         if (z==0);
         else
            c.a[i][j]=z;
     }
     }
     return c;
}

///SUPLIMENTAR
