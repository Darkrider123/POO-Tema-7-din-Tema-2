#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using namespace std;

class NRcomplex
{

    double re;
    double im;

    friend istream &operator >> (istream &in, NRcomplex &ob);
    friend ostream &operator << (ostream &out,const NRcomplex &ob);


public:
     NRcomplex();
     NRcomplex(int a,int b);
     NRcomplex (const NRcomplex &ob);
   NRcomplex operator + (const NRcomplex &ob);
   NRcomplex operator * (const NRcomplex &ob);
   NRcomplex operator - (const NRcomplex &ob);
   NRcomplex operator / (const NRcomplex &ob);
   NRcomplex operator = (const NRcomplex &ob);
   NRcomplex operator = (double a);
   int operator==(int a);
   int operator!=(const NRcomplex &ob);
   void setnumarla0();
};

#endif
