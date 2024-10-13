// 因為是headfile，要有ifndef, define 來定義headfile
#ifndef _Document_H_  
#define _Document_H_
  
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Document{

    public:        
        Document(const Document& doc);
        Document();
        Document& addString(string str);
        int getLength();

        friend ostream &operator<< (ostream &out, Document &Doc);

    
    private:
        vector<string> s; 
};

#endif