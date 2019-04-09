#include "Matrice.h"

#ifndef MATRICE_PATRATICA_H
#define MATRICE_PATRATICA_H


class Matrice_Patratica: public Matrice{

    int n;

protected:
    istream& read(istream&) override;
    ostream& print(ostream&) override;

    bool Triangular() override;
    Matrice_Patratica minor(Matrice_Patratica,int,int,int); // returneaza minor de ordin inferior, folosesc in det()
    int det(Matrice_Patratica,int);  // calculeaza determinantul

public:

    explicit  Matrice_Patratica(int size=0);
    Matrice_Patratica(const Matrice_Patratica&);
    ~Matrice_Patratica() override;

    Matrice_Patratica&operator=(Matrice_Patratica);
    Matrice_Patratica&operator+(Matrice_Patratica);
    Matrice_Patratica&operator-(Matrice_Patratica); // modificata in lab

    bool Diag_Triangular() override;
    int get_dim(int) override;
    Vector& get_array(int) override;
};


#endif
