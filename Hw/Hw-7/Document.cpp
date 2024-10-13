#include <iostream>
#include <string>
#include <vector>
#include "Document.h"

using namespace std; 


Document::Document(){}  // Construct which do nothing

Document::Document(const Document& doc){
    s = doc.s;
}

Document& Document::addString(string str){  //回傳reference to currnet -> 用到 this ，回傳tyoe為 Document"&"
    s.push_back(str);
    return *this;
}

int Document::getLength(){
   int sum =0;
   for (int i=0; i<s.size(); i++){
        sum += s[i].length();
   }
   return sum;
}

ostream &operator<<(ostream &out, Document &doc){
    for (int i=0; i < doc.s.size(); i++){
        out << doc.s[i] << " ";
    }
    return out;
}