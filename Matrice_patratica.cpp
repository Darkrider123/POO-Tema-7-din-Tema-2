#include "Matrice_patratica.h"


Matrice_patratica::Matrice_patratica()
{
  dim=0;
}

 Matrice_patratica::Matrice_patratica(int n):Matrice(n,n)
 {dim=n;}

Matrice_patratica::~Matrice_patratica()
{
     int i;

    for (i=0;i<dim;i++)
        delete[] a[i];
    delete[] a;
}

istream &operator >> (istream &in, Matrice_patratica &ob)
{
    if (ob.dim>0)
        {
            int i;

    for (i=0;i<ob.dim;i++)
        delete[] ob.a[i];
    delete[] ob.a;
        }

    cout<<"Introduceti dimensiunea matricii patratice: ";
    in>>ob.dim;
    if (ob.dim<=0)
    {
        ob.dim=0;
        return in;
    }
     cout<<"\n";
     int i,j;

     ob.a=new NRcomplex* [ob.dim];
    for (i=0;i<ob.dim;i++)
        ob.a[i]=new NRcomplex [ob.dim];

    for (i=0;i<ob.dim;i++)
        for (j=0;j<ob.dim;j++)
        in>>ob.a[i][j];

        cout<<"\n";

    return in;

}

ostream &operator << (ostream &out, Matrice_patratica &ob)
{
     int i,j;
    for (i=0;i<ob.dim;i++)
    {
        for (j=0;j<ob.dim;j++)
        out<<ob.a[i][j]<<"   ";
       out<<"\n\n";
    }
    if (ob.dim==0)out<<"Determinantul nu exista\n";
    else
    {
    out<<"Determinantul este: ";
    out<<ob.Determinant();
    out<<"\n";
    }
    return out;
}


NRcomplex Matrice_patratica::Determinant()
{
     int x,i,j,subi=0,subj=0;
    NRcomplex det;

    if (dim==1) return a[0][0];

    if (dim==2)
        return (a[0][0]*a[1][1])-(a[1][0]*a[0][1]);

        Matrice_patratica suba(dim);


    for(x=0;x<dim;x++)
    {
        subi=0;
        for (i=1;i<dim;i++)
        {
            subj=0;

            for (j=0;j<dim;j++)
              if (j==x);
              else
              {
                  suba.a[subi][subj]=a[i][j];
                  subj++;
              }
          subi++;
        }
        if (x%2==0)
        {
            suba.dim=suba.dim-1;
            det=det+a[0][x]*suba.Determinant();
            suba.dim=suba.dim+1;
        }
        else
         {
            suba.dim=suba.dim-1;
            det=det-a[0][x]*suba.Determinant();
            suba.dim=suba.dim+1;
        }

    }


    return det;

}

void Matrice_patratica::VerificareTriunghiularitate()
{NRcomplex b;
    int i,j,ok=1;
    if (dim==0) {cout<<"Matricea nu exista\n";return;}

    for (i=0;i<dim;i++)
        for (j=0;j<dim;j++)

         if (j>i&&a[i][j]!=b) ok=0;

         if (ok==1){cout<<"Triunghiulara superior\n";}
           else cout<<"Nu e triunghiulara superior\n";

         ok=1;
         for (i=0;i<dim;i++)
        for (j=0;j<dim;j++)
         if (j<i&&a[i][j]!=b) ok=0;

         if (ok==1){cout<<"Triunghiulara inferior\n"; return;}

         cout<<"Nu e triunghiulara inferior\n";
}

///SUPLIMENTAR

Matrice_patratica::Matrice_patratica(const Matrice_patratica &ob)
{
     dim=ob.dim;
        int i,j;

        a=new NRcomplex* [dim];
        for (i=0;i<dim;i++)
            a[i]=new NRcomplex [dim];

        for (i=0;i<dim;i++)
            for (j=0;j<dim;j++)
            a[i][j]=ob.a[i][j];
}

Matrice_patratica Matrice_patratica::operator =(const Matrice_patratica &ob)
{
    int i,j;

    if (dim>0)
    {
        for (i=0;i<dim;i++)
           delete[] a[i];

           delete[] a;
    }

    dim=ob.dim;
    a=new NRcomplex* [dim];
    for (i=0;i<dim;i++)
        a[i]=new NRcomplex [dim];

    for (i=0;i<dim;i++)
        for (j=0;j<dim;j++)
         a[i][j]=ob.a[i][j];

    return *this;

}

Matrice_patratica Matrice_patratica::operator +(const Matrice_patratica &ob)
{ int i,j;

   Matrice_patratica c(dim);
   if (dim!=ob.dim) return c;

    for (i=0;i<dim;i++)
        for (j=0;j<dim;j++)
    {
        c.a[i][j]=a[i][j]+ob.a[i][j];
    }
    return c;
}


Matrice_patratica Matrice_patratica::operator *(const Matrice_patratica &ob)
{
    int i,j,l;
      NRcomplex z(0,0);
    Matrice_patratica c;
    if (dim!=ob.dim) return c;

    c.dim=dim;

    c.a=new NRcomplex* [dim];
    for (i=0;i<dim;i++)
        c.a[i]=new NRcomplex [dim];

     for (i=0;i<c.dim;i++)
     {

        for (j=0;j<c.dim;j++)
     {
         z.setnumarla0();

        for (l=0;l<ob.dim;l++)
            z=z+a[i][l]*ob.a[l][j];


         if (z==0);
         else
            c.a[i][j]=z;
     }
     }
     return c;
}


Matrice_patratica Matrice_patratica::transpusa()
{
    Matrice_patratica c(dim);

    int i,j;



    for (i=0;i<dim;i++)
        for (j=0;j<dim;j++)
            c.a[j][i]=a[i][j];

          return c;

}



Matrice_patratica Matrice_patratica::adjuncta()
{
        int x,y,i,j,subi=0,subj=0;
NRcomplex semn(-1,0);
    if (dim==1) return *this;

        Matrice_patratica suba(dim-1),c(dim);



         for (x=0;x<dim;x++)
            for (y=0;y<dim;y++)
         {
             subi=0;
             for (i=0;i<dim;i++)
             {
                 subj=0;

                for (j=0;j<dim;j++)

             {
                 if (i==x||j==y);
                 else
                 {
                     suba.a[subi][subj]=a[i][j];
                     subj++;
                 }

             }
             if (i==x);
             else
            subi++;


         }
         if((x+y)%2==0)
            c.a[x][y]=suba.Determinant();
         else
            c.a[x][y]=semn*suba.Determinant();
         }

    return c;

}

Matrice_patratica Matrice_patratica::inversa()
{
    Matrice_patratica b,c(dim),gol;
    int i,j;
     if (Determinant()==0) {cout<<"Nu exista inversa " ;return gol;}
     gol=transpusa();
    b=gol.adjuncta();

    for (i=0;i<dim;i++)
        for (j=0;j<dim;j++)
            c.a[i][j]=b.a[i][j]/Determinant();


    return c;
}
///SUPLIMENTAR
