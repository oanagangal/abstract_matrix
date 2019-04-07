#include "Vector.h"


using namespace std;

Vector::Vector(int size)
{
    dim=size;
    a=new int[dim];
}

Vector::Vector(const Vector &p)
{

    dim=p.dim;

    a=new int[dim];

    for(int i=0;i<dim;i++)
        a[i]=p.a[i];

}

Vector::~Vector()
{
    delete[] a;
}


void Vector::setSize(int size)
{
    dim=size;
}


int Vector::getSize()
{
    return dim;
}

istream &operator>>(istream &in, Vector &p)
{
    if(p.dim==0)
      in >> p.dim;

    delete[] p.a;
    p.a = new int[p.dim];

    for(int i=0;i<p.dim;i++ )
        in>>p.a[i];

    return in;
}


ostream &operator<<(ostream &out, Vector &p)
{
    for(int i=0;i<p.dim;i++)
        out<<p.a[i]<<" ";
    return out;
}



int Vector::sum()
{
    int s=0;
    for(int i=0;i<dim;i++)
        s=s+a[i];
    return s;
}


void Vector::max()
{
    int m=0,i;
    for(i=1;i<dim;i++)
        if(a[m]<a[i])
            m=i;

    cout<<" VAL MAX: "<<a[m]<<"  POZITIE: "<<m<<endl;
}


void Vector::sort()
{
    int i,j, m=0;

    for(i=0;i<dim-1;i++)
    {
        m=i;
        for(j=i;j<dim;j++)
            if(a[m]>a[j])
                m=j;
        swap(a[i],a[m]);
    }
}



Vector& Vector::operator=(Vector p){

    delete[]a;
    dim=p.dim;
    a=new int[dim];

    for(int i=0;i<dim;i++)
        a[i]=p.a[i];

    return *this;
}


int Vector::operator*(Vector p)
{
    if(p.dim!=dim)
    {
        cout<<"Vectorii nu au aceiasi dimensiune"<<endl;
        return -1;
    }

    int s=0;

    for( int i=0; i < dim; i++)
        s=s+p.a[i] * a[i];

    return s;
}


Vector Vector::operator+(Vector p)
{
    if(dim!=p.dim)
    {
        cout<<"vectorii nu au aceiasi dimensiune"<<endl;
        Vector t;
        return t;
    }
    for(int i=0;i<dim;i++)
        a[i]=a[i]+p.a[i];

    return *this;
}

int Vector::operator[](int i)
{
    if(i>=dim)
        cout<<"argument out of bound"<<endl;

    return a[i];
}

Vector Vector::pop(int u)
{
   Vector b;
   b.dim=dim-1;
   b.a=new int[dim-1];
   int j=0;

   for(int i=0;i<dim;i++)
       if(i!=u)
       {
           b.a[j]=a[i];
           j++;
       }


    return b;
}

void Vector::setMem(int size)
{
  delete[]a;
  dim=size;
  a=new int[size];
}




