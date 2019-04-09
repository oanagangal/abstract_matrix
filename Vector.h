#include <iostream>

using namespace std;

#ifndef VECTOR_H
#define VECTOR_H


class Vector{

    int dim;
    int* a;

public:
    // Constructor - Destructor

    explicit Vector(int size=0);
    Vector(const Vector&); // copy constructor
    ~Vector();


    // setter/getter

    void setSize(int);
    int getSize();
    void setMem(int);

    // supraincarcare << >>

    friend istream& operator>>(istream&,Vector&);
    friend ostream&  operator<<(ostream&,Vector&);



    //op. overloading

    Vector& operator=(Vector);
    int operator*(Vector);
    Vector&operator+(Vector);
    Vector&operator-(Vector); // modificata in lab
    int operator[](int);



    // Metode

    int sum(); // suma elementelor din vector
    void max(); // elementul maxim si pozitia sa
    void sort(); // sorteaza crescator vectorul
    Vector pop(int);



};


#endif
