#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char** argv){
    ifstream fin(argv[1], ios::in);
    int num, rate;
    float sum,avg;
    string name;
    map<string, vector<int> > moviemap;
    map<string, vector<int> >::iterator it;
    vector<int>::iterator pv;
    if (fin.fail()){
        cout << "open file failed ";
        exit(1);
    }
    fin >> num;
    fin.ignore(); //跳過endl以免被getline吃掉
    for (int i=0; i<num; i++){
        getline(fin,name);
        //cout << "read the name: " << name <<endl;
        fin >> rate;
        fin.ignore();//跳過數字後的endl以免被getline吃掉
        //cout << "rate: " << rate << endl;
        moviemap[name].push_back(rate);
    }

    for (it = moviemap.begin(); it != moviemap.end(); it++){
        cout << it->first << ": ";
        sum = 0;
        for (pv=it->second.begin(); pv != it->second.end(); pv++){
            sum += *pv;
        }
        avg = sum/(it->second.size());
        if (it->second.size() == 1){
            cout << it->second.size() << " review, average of " << avg << "/5" << endl;
        }
        else{
            cout << it->second.size() << " reviews, average of " << avg << "/5" << endl;
        }
    }

    fin.close();
    return 0;
}