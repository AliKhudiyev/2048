#include"vect2d.hpp"

Vect2D Vect2D::operator+(const Vect2D& v){
    Vect2D vect;

    vect.x_=k_*x_+v.k_*v.x_;
    vect.y_=k_*y_+v.k_*v.y_;
    vect.k_=1;

    return vect;
}

Vect2D Vect2D::operator-(const Vect2D& v){
    Vect2D vect;

    vect.x_=k_*x_-v.k_*v.x_;
    vect.y_=k_*y_-v.k_*v.y_;
    vect.k_=1;

    return vect;
}

Vect2D& Vect2D::operator+=(const Vect2D& v){
    x_+=v.x_;
    y_+=v.y_;
    
    return *this;
}

Vect2D& Vect2D::operator-=(const Vect2D& v){
    x_-=v.x_;
    y_-=v.y_;

    return *this;
}

bool Vect2D::operator==(const Vect2D& v){
    return (x_==v.x_ && y_==v.y_);
}

bool Vect2D::operator!=(const Vect2D& v){
    return (x_!=v.x_ || y_!=v.y_);
}