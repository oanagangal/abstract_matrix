#include "Matrice.h"




#ifndef MATRICE_OARECARE_H
#define MATRICE_OARECARE_H


class Matrice_Oarecare: public Matrice{

    int lin;

protected:
    istream& read(istream&) override;
    ostream& print(ostream&) override;
    
    bool Triangular() override; // matrice triunghiulara sau nu

public:
    explicit Matrice_Oarecare(int l=0);
    Matrice_Oarecare(const Matrice_Oarecare&);
    ~Matrice_Oarecare() override;

    Matrice_Oarecare&operator=(Matrice_Oarecare);
    Matrice_Oarecare& operator+(Matrice_Oarecare);

    bool Diag_Triangular() override;
    int get_dim(int) override;
    Vector& get_array(int) override;

};


#endif
