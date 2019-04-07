#include "Matrice_Oarecare.h"
using namespace std;


Matrice_Oarecare::Matrice_Oarecare(int l) : Matrice(l)
{
    lin=l;

}

Matrice_Oarecare::Matrice_Oarecare(const Matrice_Oarecare &obj): Matrice(obj)
{
    lin=obj.lin;
    v=new Vector[lin];

    for(int i=0;i<lin;i++)
        v[i]=obj.v[i];

}


Matrice_Oarecare::~Matrice_Oarecare()
{

    delete[] v;
}


istream &Matrice_Oarecare::read(istream &in)
{
   if(lin==0)
   {
       in>>lin;
       delete[]v;
       v=new Vector[lin];
   }
   int size;
   in>>size;

   for(int i=0;i<lin;i++)
   {
       v[i].setSize(size);
       in>>v[i];
   }


    return in;
}

ostream &Matrice_Oarecare::print(ostream &out)
{
    for(int i=0;i<lin;i++)
        out<<v[i]<<endl;
    //if(lin==v->getSize())
        //out<<this->det(*this,lin);

    return out;
}

Matrice_Oarecare &Matrice_Oarecare::operator=(Matrice_Oarecare obj){

    lin=obj.lin;
    delete[]v;
    v=new Vector[lin];

    for(int i=0;i<lin;i++)
        v[i]=obj.v[i];
    return *this;
}

bool Matrice_Oarecare::Triangular()
{
    if(lin!=v->getSize())
    {
        cout<<"matricea nu e patratica"<<endl;
        return false;
    }

    int k=0;

        for(int i=0;i<lin;i++)
            if(v[i][i]==0)
                return false;

    for(int j=0;j<lin;j++)  // upper triangular matrix
        for(int i=j+1;i<lin;i++)
            if(v[i][j]!=0)
                break;
            else
                k++;

    return k == (lin * lin - lin) / 2;  // inseamna ca triunghiulara daca true

}

bool Matrice_Oarecare::Diag_Triangular()
{
    if(!this->Triangular())
        return false;

    if(this->Triangular())
    {
        int k=0;
        for(int j=lin-1;j>=0;j--)  // lower triangular matrix
            for(int i=j-1;i>=0;i--)
                if(v[i][j]!=0)
                    break;
                else
                    k++;

        if(k==(lin*lin-lin)/2)
            return true;
    }

    return false;
}

Matrice_Oarecare& Matrice_Oarecare::operator+(Matrice_Oarecare m)
{
    if(lin!=m.lin&&v->getSize()!=m.v->getSize())
    {
        cout<<"dimensiunile matricelor nu corespund"<<endl;
        return *this;
    }
    for(int i=0;i<lin;i++)
        v[i]=v[i]+m.v[i];
    return *this;
}

int Matrice_Oarecare::get_dim(int i)
{
    if(i==1)
    return v->getSize();
    else
        return lin;
}

Vector &Matrice_Oarecare::get_array(int i) {
    if(i>lin)
        cout<<"element matrice inexistent"<<endl;
    return v[i];
}
