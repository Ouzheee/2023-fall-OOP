#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string filename;
    cout << "Please enter the filename: ";
    cin >> filename;
    ifstream fin(filename);

    if (fin.fail()){
        cout << "File \"" << filename << "\" dees not exist.\n";
        fin.close();
    }
    else{
        string outname;
        cout << "Please enter the output filename: ";
        cin >> outname;
        ofstream fout(outname);
        int number=0, letter=0, notwhite=0, characters=0;
        
        while(!fin.eof()){
            string read;
            getline(fin,read);
            
            for (int i=0; i < read.length(); i++){  //逐一判斷每行的每個字是不是whiltespace
                char c = read[i];
                characters++; //讀成功 -> 必唯一種characters -> characters加1
                if (isalpha(c)){
                    letter++;  //如果是 alphabetic letter -> letters加1
                }
                
                if (isspace(c) && !isspace(read[i+1])){  //如果是whiltspace且下一個就不是whitespace -> 換字 -> number加1
                    //number++;
                }
                if (!isspace(c)){  //Not whilespace -> notwhite加1
                    notwhite++;
                }
            }
            
            if (!fin.eof()){  //還沒到最後一行前，要算上換黃的，所以number、characters加1
                //number++;
                characters++;
            }
        }
	fin.close();
        ifstream fin(filename);
        string word;
        while(fin >> word){
            number++;
        }
        cout << "Total number of words: " << number << endl;
        cout << "Total number of characters: " << characters << endl;
        cout << "Total number of non-whitespace characters: " << notwhite << endl;
        cout << "Total number of letters: " << letter << endl << endl;
        fout << "Total number of characters: " << characters << endl;
        fout << "Total number of non-whitespace characters: " << notwhite << endl;
        fout << "Total number of letters: " << letter << endl << endl;
    
        fin.close();  //關檔案釋放記憶體
        fout.close();
    }
    return 0;
}
