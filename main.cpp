#include <iostream>
#include "Vector.h"
#include "Matrice.h"
#include "Matrice_Oarecare.h"
#include "Matrice_Patratica.h"
#include <fstream>

bool funct(Matrice* A,Vector x,Vector y)
{
    if(A->get_dim(1)!=x.getSize()||A->get_dim(2)!=y.getSize())
    {

        cout<<"vectori incompatibili cu matricea A"<<endl;
        return false;
    }

    for(int i=0;i<A->get_dim(2);i++)
        if (A->get_array(i) * x != y[i])
           return false;

    return true;
}

int main() {
    ifstream f;
    f.open("Matrice_Oarecare");


   Matrice_Patratica M(3);
    f>>M;
    cout<<M<<endl;
   Vector x(3),y(3);
   f>>x>>y;
   cout<<funct(&M,x,y);

   f.close();
    return 0;
}