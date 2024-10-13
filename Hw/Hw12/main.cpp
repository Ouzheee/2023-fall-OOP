#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;
using std::stack;

template <class T>
class RPN{
    public:
        RPN(){};
        stack<T> s;
        void plus(){
            int t1 = s.top();
            s.pop();
            int t2 = s.top();
            s.pop();
            s.push(t1+t2);
        }

        void minus(){
            int t1 = s.top();
            s.pop();
            int t2 = s.top();
            s.pop();
            s.push(t2-t1);
        }

        void multiple(){
            int t1 = s.top();
            s.pop();
            int t2 = s.top();
            s.pop();
            s.push(t1*t2);
        }

        void of(){
            int t1 = s.top();
            s.pop();
            int t2 = s.top();
            s.pop();
            s.push(t2/t1);
        }
};

int main(int argc, char* argv[]){
    ifstream fin(argv[1], ios::in);
    if (fin.fail()){
        cout << "ERROR!!!";
        exit(1);
    }
    RPN<int> stack;
    string input;
    int number;
    fin >> input;
    while (input != "q"){
        if ((input == "+" || input == "-" || input == "*" || input == "/" ) && stack.s.size() < 2){
            cout << "ERROR!!!";
            exit(1);
        }
        
        else if (input == "+"){
            stack.plus();
        }
        else if (input == "-"){
            stack.minus();
        }
        else if (input == "*"){
            stack.multiple();
        }
        else if (input == "/"){
            stack.of();
        }
        else{
            number = stoi(input);
            stack.s.push(number);
        }
        fin >> input;
    }
    cout << "The top of the stack is: " << stack.s.top();
    fin.close();
    return 0;
}
