#include <iostream>
#include <cmath>
using namespace std;
class AccountNumber{
    private:
        int *number;
        int size;
    public:
    AccountNumber(int *in_number, int length);
    ~AccountNumber();
    bool valid();
    int findvalid();
    int *getNumber();
    int getSize();

};

AccountNumber::AccountNumber(int *in_number, int length){
    size = length;
    number = new int [size];
    for (int i=0; i<size; i++){
        number[i] = in_number[i];
    }
}
AccountNumber::~AccountNumber(){
    delete [] number;
}

bool AccountNumber::valid(){
    int sum=0;
    int *tmp = new int [size];
    for (int i=0; i<size; i++){
        tmp[i] = number[i];
    }
    for (int i=(size-2); i >=0; i-=2){
        tmp[i] *=2;
        if (tmp[i] > 9){
            tmp[i] -=9;
        }
    }
    for (int i=0; i<size; i++){
        sum += tmp[i];
    }
    if (sum%10 == 0){
        return true;
    }
    else{
        return false;
    }
    delete [] tmp;
}

int AccountNumber::findvalid(){
    int ori=0;
    for (int i=0; i<size; i++){
        ori += number[i] *pow(10,size-1-i);
    }

    while(!valid()){
        ori++;
        for (int i=size-1 ; i >= 0; i--){
            number[i] = ori % 10;
            ori /= 10;
        }
        ori=0;
        for (int i=0; i<size; i++){
            ori += number[i] * pow(10, size-1-i);
        }
    }
    return ori; 
}

int *AccountNumber::getNumber(){
    return number;
}
int AccountNumber::getSize(){
    return size;
}

int main(){
    int length,inNumber;
    cout << "Please enter the account's length:";
    cin >> length;
    cout << "Please enter your account number:";
    cin >> inNumber;
    int *inArray = new int [length];
    for (int i= length-1 ; i >= 0; i--){
        inArray[i] = inNumber % 10;
        inNumber /= 10;
    }
    AccountNumber c1(inArray, length);
    if (c1.valid()){
        cout << "Account number is valid." << endl;
        cout << "Account Number:";
        for (int i=0; i<c1.getSize(); i++){
            cout << c1.getNumber()[i];
        }
    }
    else{
        cout << "Account number is not valid." << endl;
        cout << "Correct Account Number:";
        
        cout << c1.findvalid();
    }

    delete [] inArray;
    return 0;
}