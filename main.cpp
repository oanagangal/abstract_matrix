#include <iostream>
#include "Vector.h"
#include "Matrice.h"
#include "Matrice_Oarecare.h"
#include "Matrice_Patratica.h"
#include <fstream>

bool funct(Matrice* A,Vector x,Vector y)  // verifica daca Ax=y
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


    Matrice* M;
    M=new Matrice_Patratica(3);
    Vector x(3),y;
    f>>(*M);
    f>>x>>y;
    cout<<(*M);
    cout<<"Matrice diagonala: "<<endl;
    cout<<M->Diag_Triangular()<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"Ax=y: "<<endl;
    cout<<funct(M,x,y)<<endl<<endl;

    Matrice_Oarecare N(3),P;
    f>>N>>P;
    cout<<N<<endl<<P<<endl<<N+P;

   f.close();
    return 0;
}
