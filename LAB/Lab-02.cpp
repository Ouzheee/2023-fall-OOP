#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
    ifstream fin(argv[1], ios::in);
    ofstream fout(argv[2], ios::out);
    double lowBond, upBond;
    string Bname [9];
    int Bwidth [9] = {0};
    int Bheight [9] = {0};
    bool isSoft [9] = {false};
    string read, name, sBw, sBh, soft = " ";
    int i,number=0;
    
    getline(fin,read);
    istringstream stream(read);
    stream >> lowBond >> upBond;
    //fin >> lowBond >> upBond;
    fout << fixed << showpoint << setprecision(2) << lowBond << " " << upBond;
    while (getline(fin,read)){
        istringstream stream(read);
        stream >> name >> sBw >> sBh >> soft;//read Data
        i = int(name[1])-49;
        Bname[i] = name;   //store Data
        Bwidth[i] = stoi(sBw);
        Bheight[i] = stoi(sBh);
        if (soft == "S"){
            isSoft[i] = true;
        }
        
        
        
        soft = " ";  //reset S
        number++;
    }
    
    for (int i=0; i<number; i++){
        cout << Bname[i] << " ";
        if (!isSoft[i]){  //Hard
            //cout << "  Is hard  ";
            if (Bwidth[i] < Bheight[i]){
                cout << "{" << Bwidth[i] << "," << Bheight[i] << "} { " << Bheight[i] << "," << Bwidth[i] << "} " << endl;
            }
            else if (Bwidth[i] > Bheight[i]){
                cout << "{" << Bheight[i] << "," << Bwidth[i] << "} { " << Bwidth[i] << "," << Bheight[i] << "} " << endl;
            }
            else{
                cout << "{" << Bheight[i] << "," << Bwidth[i] << "} " << endl;
            }
        }
        else{  //soft
            int Area = Bwidth[i] * Bheight[i];
            for (int width = 1; width <= Area; width++){
                //cout << width << " ";
                if (Area % width == 0 ){
                    //cout << "remain 0 's width:" << width << endl;
                    double Dwidth = static_cast<double>(width);
                    if (Dwidth/(Area/Dwidth) >= lowBond && Dwidth/(Area/width) <= upBond){
                        cout << "{" << Dwidth << "," << Area/Dwidth << "} ";
                    }
                } 
            }
            cout << endl;
        }
    }
    
    fin.close();
    fout.close();
    return 0;
}