/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int jump(int n, int* arr, int pos){

    if (pos >= n-3){  //如果已到倒數第3個->直接加到最後一個已省略步驟
           return arr[n-1];
    }

    else{
        int move1 = arr[pos+1] + jump(n, arr, pos+1);
        int move2 = arr[pos+2] + jump(n, arr, pos+2);
        return min(move1,move2);  //可能移動一步或兩步，遞迴計算完總數後後取最小值
    }
}

int main()
{
    string filename;
    cout<<"Please enter the filename: ";
    cin >> filename;
    ifstream fin(filename);
    if (fin.fail()){
        cout << "File \"" << filename << "\" dees not exist.\n";
        fin.close();
        exit(1);
    }

    int n,sum;
    fin >> n;
    int *array = new int [n];  //建立陣列
    for (int i=0; i<n; i++){
        fin >> array[i];
    }
    sum = jump(n, array, 0);
    cout << "the lowest cost is " << sum << endl;
    delete array;
    fin.close();
    return 0;
}