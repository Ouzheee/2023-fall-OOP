#include <set>
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv){
    ifstream fin(argv[1]);
    string name;
    set<string> nameset;
    set<string>::iterator it;
    while (getline(fin,name)){
        nameset.insert(name);
    }
    for (it = nameset.begin(); it != nameset.end(); it++){
        cout << *it << endl;
    }

    fin.close();
    return 0;
}