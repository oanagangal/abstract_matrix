#include "Matrice.h"
Matrice::Matrice(int size)
{

    v=new Vector[size];
}

Matrice::Matrice(const Matrice &obj)
{

}

Matrice::~Matrice()
= default;

istream &operator>>(istream &in, Matrice &obj) {
    return obj.read(in) ;
}

ostream &operator<<(ostream &out, Matrice &obj) {
    return obj.print(out);
}








