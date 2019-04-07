#include "Matrice_Patratica.h"

Matrice_Patratica::Matrice_Patratica(int size) : Matrice(size)
{
    n=size;

}

Matrice_Patratica::Matrice_Patratica(const Matrice_Patratica &obj) : Matrice(obj)
{
  n=obj.n;
  v=new Vector[n];

  for(int i=0;i<n;i++)
      v[i]=obj.v[i];
}

Matrice_Patratica::~Matrice_Patratica()
{
   delete[] v;
}

istream &Matrice_Patratica::read(istream &in)
{
    if(n==0)
    {
        in>>n;
        delete[]v;
        v=new Vector[n];
    }

    for(int i=0;i<n;i++)
    {
        v[i].setSize(n);
        in>>v[i];
    }
    return in;
}

ostream &Matrice_Patratica::print(ostream &out)
{
    for(int i=0;i<n;i++)
        out<<v[i]<<endl;
    out<<"det = "<<this->det(*this,n);
    return out;
}

Matrice_Patratica &Matrice_Patratica::operator=(Matrice_Patratica obj){

    n=obj.n;
    delete[]v;
    v=new Vector[n];

    for(int i=0;i<n;i++)
        v[i]=obj.v[i];

    return *this;
}

bool Matrice_Patratica::Triangular()
{
    int k=0;

    for(int i=0;i<n;i++)
        if(v[i][i]==0)
            return false;

    for(int j=0;j<n;j++)  // upper triangular matrix
        for(int i=j+1;i<n;i++)
            if(v[i][j]!=0)
                break;
            else
                k++;

    return k == (n * n - n) / 2;  // inseamna ca e triunghiulara daca true

}

bool Matrice_Patratica::Diag_Triangular()
{
    if(!this->Triangular())
        return false;

    if(this->Triangular())
    {
        int k=0;
        for(int j=n-1;j>=0;j--)  // lower triangular matrix
            for(int i=j-1;i>=0;i--)
                if(v[i][j]!=0)
                    break;
                else
                    k++;

        if(k==(n*n-n)/2)
            return true;
    }

    return false;
}


Matrice_Patratica Matrice_Patratica::minor(Matrice_Patratica m,int p, int q, int size)
{
    Matrice_Patratica temp(size-1);
    int row=0;
    for(int i=0;i<size;i++)
            if (i != p)
            {
                temp.v[row].setMem(size);
                temp.v[row]=m.v[i].pop(q);

                row++;
            }
    return temp;
}

int Matrice_Patratica::det(Matrice_Patratica b,int k)
{
    int d=0;
 int sign=1;

    Matrice_Patratica temp1;
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

Matrice_Patratica& Matrice_Patratica::operator+(Matrice_Patratica m)
{
    if(n!=m.n&&v->getSize()!=m.v->getSize())
    {
        cout<<"dimensiunile matricelor nu corespund"<<endl;
        return *this;
    }
    for(int i=0;i<n;i++)
        v[i]=v[i]+m.v[i];
    return *this;
}

int Matrice_Patratica::get_dim(int i)
{
    return n;
}

Vector &Matrice_Patratica::get_array(int i)
{
    if(i>n)
        cout<<"element matrice inexistent"<<endl;
    return v[i];
}
