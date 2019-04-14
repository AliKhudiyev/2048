
#pragma once

struct Vect2D{
    int x_=0, y_=0;
    int k_=1;

    Vect2D()=default;
    Vect2D(int x, int y, int k=1): 
        x_(x), y_(y), k_(k) {}
    
    Vect2D operator+(const Vect2D& v);
    Vect2D operator-(const Vect2D& v);
    Vect2D& operator+=(const Vect2D& v);
    Vect2D& operator-=(const Vect2D& v);
    bool operator==(const Vect2D& v);
    bool operator!=(const Vect2D& v);
};
