#include "Pairs_operation.h"
#include <iostream>
#include <fstream>
using namespace std;

//Constructor
Pairs::Pairs() : f(0), s(0) {}
Pairs::Pairs(int first,int second){
    f = first;
    s = second;
}
Pairs::Pairs(int first): s(0){
    f = first;
}

//overloading >> and <<
istream& operator >>(istream& in, Pairs & second){
    char c1,com,c3;
    int first, sec;
    in >> c1 >> first >> com >> sec >> c3;
    second.f = first;
    second.s = sec;
    return in;
}
ostream& operator <<(ostream& outs, const Pairs & second){
    outs << "(" << second.f << "," << second.s << ")";
    return outs;
}

//overlording +,-,*
Pairs Pairs::operator + (const Pairs& obj){
    return Pairs(f+obj.f, s+obj.s);
}
Pairs Pairs::operator - (const Pairs& obj){
    return Pairs(f-obj.f, s-obj.s);
}
Pairs Pairs::operator * (int obj){
    return Pairs(f*obj, s*obj);
}
