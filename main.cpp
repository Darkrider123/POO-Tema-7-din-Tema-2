#include "Matrice_oarecare.h"
#include "Matrice_patratica.h"
using namespace std;

int main()
{
    Matrice_oarecare b(3,1);
    cout<<"Matricea oarecare initializata automat este:\n";
    cout<<b;

    cin>>b;
    cout<<b;

Matrice_patratica a(10);
cout<<"Matricea initializata automat este:\n";
cout<<a;
a.VerificareTriunghiularitate();
cout<<endl;
cin>>a;
cout<<a;
a.VerificareTriunghiularitate();

///SUPLIMENTAR
cout<<"\nSuplimentar\n";
Matrice_oarecare c,d;
cout<<"Introdu 2 matrice pentru a le inmulti:\n";
cin>>b;
cin>>c;
d=c*b;
cout<<d;

Matrice_patratica inversa;
cout<<"\nIntrodu o matrice pentru a-i afla inversa:\n";
cin>>a;
inversa=a.inversa();
cout<<inversa;
    return 0;
}
