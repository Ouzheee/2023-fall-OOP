#include "heap.hpp"
#include <fstream>

vector<int> Circuit::readinput(string filename){
    vector<int> delay;
    ifstream fin(filename);
    string input;
    fin >> input;
    gatecount=stoi(input);
    for(int i=0;i<gatecount;++i){
        int temp;
        fin >> input;
        temp=stoi(input);
        delay.push_back(temp);
    }
    make_heap (delay.begin(),delay.end());
    return delay;
}

void Circuit::printout(){
    for(auto a:gate_list)
        cout<<a->gatetype<<a->gateID<<" ("<<a->outputnode<<","<<a->inputnodeA<<","<<a->inputnodeB<<");"<<endl;
}

bool sortbydelay(Gate *a,Gate *b){
    //vvvv write your code here vvvv
    return ((*a).delay > (*b).delay);
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
}

void Circuit::buildgate(vector<int> &list){
    //vvvv write your code here vvvv
    gatecount = list.size();
    
    for (int i=0; i<gatecount;i++){
        Gate *tmp = new Gate;
        //calculate the delay
        if ((2*i)+1 >= gatecount){ //兩個input都在陣列外
            tmp->delay = list[i];
        }
        else if ((2*i)+2 >= gatecount){ //第二個input是intputnode(沒有連接gate)
            tmp->delay = list[i] - list[2*i+1];
        }
        else{  //2個input都連接到gate
            tmp->delay = list[i] - max(list[2*i+1],list[2*i+2]);
        }
        
        //determine the type of gate
        if (tmp->delay == 10){
            tmp->gatetype = "NOR";
            tmp->gateID = norcount++;
        }
        else if (tmp->delay == 15){
            tmp->gatetype = "NAND";
            tmp->gateID = nandcount++;
        }
        else if (tmp->delay == 20){
            tmp->gatetype = "OR";
            tmp->gateID = orcount++;
        }
        else if (tmp->delay == 25){
            tmp->gatetype = "AND";
            tmp->gateID = andcount++;
        }
        else if (tmp->delay == 30){
            tmp->gatetype = "XOR";
            tmp->gateID = xorcount++;
        }

        //set outputnode
        if (i == 0){
            tmp->outputnode = "outputnode";
        }
        else{
            tmp->outputnode = "n" + std::to_string(i);
        }
        //set inputnode
        if ((2*i)+1 >= gatecount){ //如果2i+1 在陣列外，就是inputnode
            tmp->inputnodeA = "inputnode";
            tmp->inputnodeB = "inputnode";
        }
        else if ((2*i)+2 >= gatecount){ //如果2i+2 在陣列外，就是inputnode
            tmp->inputnodeA = "n" + std::to_string(2*i+1);
            tmp->inputnodeB = "inputnode";
        }
        else{
            tmp->inputnodeA = "n" + std::to_string(2*i+1);
            tmp->inputnodeB = "n" + std::to_string(2*i+2);
        }
        gate_list.push_back(tmp);
        /*cout << "the information of tmp: " << tmp->gatetype << tmp->gateID << endl
             << "outputnode: " << tmp->outputnode << "  delay: " << tmp->delay << endl << "outputnode: " << tmp->inputnodeA << " , " << tmp->inputnodeB << endl;*/
    }
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    sort(gate_list.begin(),gate_list.end(),sortbydelay);
}
