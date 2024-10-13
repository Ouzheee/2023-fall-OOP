#include "polynomial.h"

void PolySeq::setDegree(int d)
{
    this->highest_degree = d;
    c = new double[this->highest_degree+1];
    for(int i=0;i<=this->highest_degree;i++){ c[i]=0; }
}

void PolySeq::setCoeff(int exp, double coef)
{
    c[exp] = coef;
}

PolySeq::~PolySeq()
{
    // vvvvv put your code here vvvvv
    delete [] c;
    // ^^^^^ put your code here ^^^^^
}

const double PolySeq::getValue(double x)
{
    // vvvvv put your code here vvvvv
    double sum=0;
    for (int i=0; i <= highest_degree; i++){
        sum += c[i] * pow(x,i);
    }
    return sum;
    // ^^^^^ put your code here ^^^^^
}

istream &operator>>(istream &in, PolySeq &poly)
{
    // vvvvv put your code here vvvvv
    for (int i=poly.highest_degree; i>=0 ; i--){
        in >> poly.c[i];
    }
    return in;
    // ^^^^^ put your code here ^^^^^
}

ostream &operator<<(ostream &out, const PolySeq &poly)
{
    // vvvvv put your code here vvvvv
    for (int i=poly.highest_degree; i>=0 ; i--){
        out << poly.c[i] << "x^" << i;
        if (i != 0){
            out << " + ";
        }
    }
    return out;
    // ^^^^^ put your code here ^^^^^   
}

PolySeq& PolySeq::operator=(const PolySeq &rhs){
    // vvvvv put your code here vvvvv
    if (this == &rhs){
         return *this;
    }
    delete [] c;
    highest_degree = rhs.highest_degree;
    c = new double [highest_degree+1];
    for (int i=0; i<= highest_degree; i++){
        c[i] = rhs.c[i];
    }
    return *this;
    
    // ^^^^^ put your code here ^^^^^
}

const PolySeq operator+(const PolySeq &lhs, const PolySeq &rhs)
{
    // vvvvv put your code here vvvvv
    PolySeq temp;
    PolySeq* bigger, smaller;
    int maxDegree, secDegree;
    if (lhs.highest_degree > rhs.highest_degree){
        temp.setDegree(lhs.highest_degree);
        for (int i = lhs.highest_degree; i> rhs.highest_degree; i--){
            temp.c[i] = lhs.c[i];
        }
        for (int i= rhs.highest_degree; i>=0; i--){
            temp.c[i] = lhs.c[i] + rhs.c[i];
        }
    }
    else{
        temp.setDegree(rhs.highest_degree);
        for (int i = rhs.highest_degree; i> lhs.highest_degree; i--){
            temp.c[i] = rhs.c[i];
        }
        for (int i= lhs.highest_degree; i>=0; i--){
            temp.c[i] = lhs.c[i] + rhs.c[i];
        }
    }

    return temp;
    // ^^^^^ put your code here ^^^^^
}

const PolySeq operator*(const PolySeq &lhs, const PolySeq &rhs)
{
    // vvvvv put your code here vvvvv
    PolySeq temp;
    temp.setDegree(rhs.highest_degree + lhs.highest_degree);
    for (int i=0; i <= lhs.highest_degree; i++){
        for (int j=0; j<= rhs.highest_degree; j++){
            temp.c[i+j] += lhs.c[i] * rhs.c[j];
        }
    }
    return temp;    
    // ^^^^^ put your code here ^^^^^
}

const PolySeq PolySeq::Derivative()
{
    // vvvvv put your code here vvvvv  
    PolySeq temp;
    temp.setDegree( max(0, highest_degree-1));
    for (int i=0; i<highest_degree; i++){
        temp.c[i] = c[i+1]*(i+1);
    }
    return temp;
    // ^^^^^ put your code here ^^^^^
}

const double PolySeq::Integral(int up_bound, int low_bound)
{
    // vvvvv put your code here vvvvv
    double sum = 0;

    for (int i=0; i<highest_degree+1; i++){
        sum += (c[i] / (i+1) ) * ( pow(up_bound, i+1) - pow(low_bound, i+1));
    }
    return sum;
    // ^^^^^ put your code here ^^^^^
}