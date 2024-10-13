#include <iostream>
#include "money.h"

const bool operator < (const Money& lhs, const Money& rhs){
    if (lhs.allCents < rhs.allCents){
        return true;
    }
    else{
        return false;
    }
}
const bool operator <= (const Money& lhs, const Money& rhs){
    if (lhs.allCents <= rhs.allCents){
        return true;
    }
    else{
        return false;
    }
}
const bool operator > (const Money& lhs, const Money& rhs){
    if (lhs.allCents > rhs.allCents){
        return true;
    }
    else{
        return false;
    }
}
const bool operator >= (const Money& lhs, const Money& rhs){
    if (lhs.allCents >= rhs.allCents){
        return true;
    }
    else{
        return false;
    }
}


Money Money::percent(float per){
    long sum = allCents * per / 100;
    return Money(sum/100, sum%100);
}
