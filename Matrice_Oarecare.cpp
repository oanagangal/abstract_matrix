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

Matrice_Oarecare Matrice_Oarecare::minor(Matrice_Oarecare m,int p,int q,int size)
{
    Matrice_Oarecare temp(size-1);
    int row=0;
    for(int i=0;i<size;i++)
        if (i != p)
        {
            temp.v[row].setMem(size-1);
            temp.v[row]=m.v[i].pop(q);

            row++;
        }
    return temp;
}

int Matrice_Oarecare::det(Matrice_Oarecare b, int k)
{
    int d=0;
    int sign=1;

    Matrice_Oarecare temp1;
    if(k==2)
        return b.v[0][0]*b.v[1][1] - b.v[0][1]*b.v[1][0];

    for(int i=0;i<k;i++)
    {
        temp1=minor(b,0,i,k);
        d+=sign*b.v[0][i]*det(temp1,k-1);
        sign*=-1;
    }
    return d;
}
