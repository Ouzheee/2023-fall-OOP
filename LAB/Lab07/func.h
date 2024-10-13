#include <iostream>

#ifndef _FUNC_H_
#define _FUNC_H_
#include <vector>
#include <math.h>
using namespace std;


class PolySeq{
    public:
        int* c;
        int n;
        PolySeq(int n);
        PolySeq();
        ~PolySeq();
        PolySeq& operator+(const PolySeq &rhs);
        PolySeq& Derivative();
        int Integral(int up_bound ,int low_bound);
};

namespace Poly_Int{
    int getValue(PolySeq& poly, int x);
}

namespace Poly_Float{
    float getValue(PolySeq& poly, float x);
}

#endif