#include <bits/stdc++.h>

using namespace std;

class Money{
    public:
        Money(int dollars, int cents){
                allCents = dollars * 100 + cents;
        };

        // ----------------------------

        //     writ your class defination here
        friend const bool operator < (const Money& lhs, const Money& rhs);
        friend const bool operator <= (const Money& lhs, const Money& rhs);
        friend const bool operator > (const Money& lhs, const Money& rhs);
        friend const bool operator >= (const Money& lhs, const Money& rhs);
        Money percent(float per);

        // ----------------------------

        float getMoney(){
            return float(allCents)/100;
        };

    private:
        long allCents;
};