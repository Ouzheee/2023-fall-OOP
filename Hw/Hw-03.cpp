#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

char* deleteRepeats(char* letters, int& size){
    int sn=size;
    size = 0;
    char *delete_array = new char[sn+1];
    for (int i=0; i < sn; i++){
        char* str = strchr(letters,letters[i]);
        if (str-letters == i){
            delete_array[size] = letters[i];
            size++;
        }
    }
    return delete_array;
}

int main(){
    int n;
    cout << "Please enter the size of string: ";
    cin >> n;
    

    cout << "Please enter string: ";
    char* oriarray = new char [n+1];
    cin >> oriarray;

    //char *delete_array = new char[n+1];
    int size=n;
    delete_array = deleteRepeats(oriarray, size);

    cout << "The new size of string is " << size << endl;
    cout << "The string after deleteRepeats is ";
    for (int i=0; i < size; i++){
        cout << delete_array[i];
    }

    delete [] oriarray;
    delete [] delete_array;
    return 0;
}