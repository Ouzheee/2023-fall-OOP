#include <iostream>
#include "func.h"
using namespace std;

int main(){
    int n1, n2;
    int x1, x2;
    float x3;
    cin >> n1;
    PolySeq P1(n1);
    for (int i=n1-1; i>=0; i--){
        cin >> P1.c[i];
    }
    cin >> n2;
    PolySeq P2(n2);
    for (int i=n2-1; i>=0; i--){
        cin >> P2.c[i];
    }
    cin >> x1 >> x2 >> x3;

    PolySeq P3 = P1 + P2;
    cout << Poly_Int::getValue(P3, x1) << endl;
    
    cout << Poly_Float::getValue(P1.Derivative(), x3) << endl;

    cout << P2.Integral(x2, x1) << endl;
}