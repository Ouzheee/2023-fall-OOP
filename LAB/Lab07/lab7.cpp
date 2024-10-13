#include <iostream>
#include <cmath>
#include "func.h"

PolySeq::PolySeq(){}

PolySeq::PolySeq(int k){
    n=k;
    c = new int [k];
}

PolySeq::~PolySeq(){
    delete [] c;
}

PolySeq& PolySeq::operator+(const PolySeq &rhs)
{
    
    if (n > rhs.n){
        PolySeq* temp = new PolySeq(n);
        for (int i = n-1; i>= rhs.n; i--){
            temp->c[i] = this->c[i];
        }
        for (int i= rhs.n-1; i>=0; i--){
            temp->c[i] = this->c[i] + rhs.c[i];
        }
        return *temp;
    }
    else{
        PolySeq* temp = new PolySeq(rhs.n);
        for (int i = (rhs.n-1); i>= n; i--){
            temp->c[i] = rhs.c[i];
        }
        for (int i= n-1; i>=0; i--){
            temp->c[i] = this->c[i] + rhs.c[i];
        }
        return *temp;
    }

    
}

PolySeq& PolySeq::Derivative(){
    PolySeq* temp = new PolySeq(n-1);
    for (int i=0; i<n-1; i++){
        temp->c[i] = c[i+1] * (i+1);
    }

    return *temp;
}

int PolySeq::Integral(int up_bound ,int low_bound){
    int sum=0;

    for (int i=n-1; i>=0;i--){
        sum += (c[i] / (i+1) ) * ( pow(up_bound, i+1) - pow(low_bound, i+1));
        
    }

    return sum;
}

int Poly_Int::getValue(PolySeq& poly, int x){
    int sum=0;
    for (int i=0; i < poly.n; i++){
        sum += poly.c[i] * pow(x,i);
    }
    return sum;
}

float Poly_Float::getValue(PolySeq& poly, float x){
    float sum=0;
    for (int i=0; i < poly.n; i++){
        sum += poly.c[i] * pow(x,i);
    }
    return sum;
}