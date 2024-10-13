#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct NODE{
	string type;
	string name;
	NODE *f1, *f2;
};
struct NODECMP {
  bool operator() (NODE *i, NODE *j) { return (i->name < j->name);}
} nodecmp;

void Read_Netlist(string dir, map<string, int> &libsize, vector<NODE*> &allnode){
	// TODO
	int countLib, countNode, countGate, size;
	string Name;
	ifstream fin(dir);
	//Record the Libs
	fin >> countLib;
	//cout << "countLib: " << countLib <<endl;
	for (int i=0; i < countLib; i++){
		fin >> Name >> size;
		libsize[Name] = size;
		//cout << "name: " << Name << "   " << libsize[Name] << endl;
		
	}

	//create Node and pushback to vector:allnode
	fin >> countNode;
	//cout << "countNOde: " << countNode <<endl;
	for (int i=0; i<countNode; i++){
		fin >> Name;
		NODE* input = new NODE;
		input->name = Name;
		input->type = Name;
		allnode.push_back(input);
	}

	//read the link of gate
	fin >> countGate;
	string type, fan1, fan2;
	//cout << "countGate: " << countGate <<endl;
	vector<NODE*>:: iterator p = allnode.begin();
	vector<NODE*>:: iterator pf1 = allnode.begin();
	vector<NODE*>:: iterator pf2 = allnode.begin();
	for (int i=0; i<countGate; i++){
		fin >> type >> Name >> fan1 >> fan2;

		for (p=allnode.begin(); (*p)->name != Name; p++){}  //指向g3的address
		(*p)->type = type;
		for (pf1=allnode.begin(); (*pf1)->name != fan1; pf1++){}  //指向fanin1的adress
		(*p)->f1 = *pf1;
		for (pf2=allnode.begin(); (*pf2)->name != fan2; pf2++){}  //指向fanin2的adress
		(*p)->f2 = *pf2;
		//cout << "Type是 " << type << "的 "  << (*p)->name << "和 " << (*p)->f1->name << " , " << (*p)->f2->name <<endl; 
	}
	fin.close();
}

void TotalFaninSize(map<string, int> &libsize, vector<NODE*> &allnode){
	// TODO
	vector<NODE*>:: iterator p;
	int sizef1,sizef2;

	for (auto p : allnode){
		if ((p)->type != (p)->name){ //判斷是否是gate
			sizef1 = libsize[(p)->f1->type];
			sizef2 = libsize[(p)->f2->type];
			cout << p->name << ":" << (sizef1 + sizef2) << endl;
		}
	}
}

int main(int argc, char *argv[]){
	// Don't modify
	string dir = argv[1];
	
	map<string, int> libsize;
	vector<NODE*> allnode;
	Read_Netlist(dir, libsize, allnode);	
	
	sort(allnode.begin(), allnode.end(), nodecmp);
	
	for(int i = 0; i < allnode.size(); i++)
		cout << allnode[i]->name << " ";
	cout << endl;
	
	TotalFaninSize(libsize, allnode);
	
	return 0;
}
