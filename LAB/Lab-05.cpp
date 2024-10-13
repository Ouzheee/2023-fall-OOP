#include "operator.h"

const Complex Complex::operator+(const Complex &rhs)
{   
    return Complex(re+rhs.re , im+rhs.im);
}

const Complex operator-(const Complex &lhs, const Complex &rhs)
{
    return Complex(lhs.re - rhs.re,lhs.im - rhs.im); 
}

const Complex Complex::operator*(const Complex &rhs)
{
    double real = re * rhs.re - (im*rhs.im);
    double ima = im * rhs.re + re*rhs.im;
    
    return Complex(real,ima);
}

const Complex operator!(const Complex &c)
{
    return Complex(c.re, -c.im);
}

bool operator==(const Complex &lhs, const Complex &rhs)
{
    return (lhs.re == rhs.re && lhs.im == rhs.im);
}

bool Complex::operator!=(const Complex &rhs)
{
    return (re != rhs.re || im != rhs.im);
}

ostream &operator<<(ostream &out, const Complex &rhs)
{
    if (rhs.im > 0){
        out << rhs.re << "+" << rhs.im << "i";
    }
    else if (rhs.im == 0){
        out << rhs.re << "+0i";
    }
    else{
        out << rhs.re << rhs.im << "i";
    }
    return out;
}

istream &operator>>(istream &in, Complex &rhs)
{
    in >> rhs.re >> rhs.im;
    return in;
}

Complex::Complex(double r, double i) : re(r), im(i) {}