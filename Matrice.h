#include "Vector.h"


#ifndef MATRICE_H
#define MATRICE_H


class Matrice{

protected:
    Vector *v;
   // constructori/destructor:

    explicit Matrice(int);
    Matrice(const Matrice&obj);
    virtual ~Matrice();

    virtual bool Triangular()=0; // verific daca o matrice e triunghiulara

    virtual istream& read(istream&)=0;
    virtual ostream& print(ostream&)=0;


public:

    friend istream&operator>>(istream&,Matrice&);
    friend ostream&operator<<(ostream&,Matrice&);


    virtual bool Diag_Triangular()=0; // verific daca matrice triunghiulara e diagonala
    virtual int get_dim(int)=0;
    virtual Vector& get_array(int)=0;

};


#endif
