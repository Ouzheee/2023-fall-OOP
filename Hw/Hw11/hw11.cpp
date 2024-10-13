#include <iostream>
#include <fstream>
using namespace std;

////////////////////////////////////////////////////
////// Finish deleteRepeats template function///////
//////        Write your code below          ///////
template <class T>
void deleteRepeats(T& letters, int& size){
    int sn=0;
    bool check[256] = {false}; //用包含所有ASCII code 的陣列紀錄是否出現過，沒出現過就是false
    for (int i=0; i < size; i++){
        if (check[letters[i]] == false){
            letters[sn] = letters[i];
            sn++;
            check[letters[i]] = true;  //更新成true，這樣之後就不會再使用
        }
    }
    size = sn;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////

int main(int argc, char **argv){
  ifstream input;
  input.open(argv[1]);

  if(!input){
		cerr << "Fail to open input";
		exit(1);
	}

  char str[100];
  int arr[100];
  int num_ch, num_int;

  input >> num_ch;
  for(int i=0; i<num_ch; i++){
    input >> str[i];
  }
  input >> num_int;
  for(int i=0; i<num_int; i++){
    input >> arr[i];
  }

  //template function
  deleteRepeats(str, num_ch);
  deleteRepeats(arr, num_int);

  //cout
  for(int i=0; i<num_ch; i++){
    cout<<str[i]<<" ";
  }
  cout<<num_ch;
  cout<<endl;
  for(int i=0; i<num_int; i++){
    cout<<arr[i]<<" ";
  }
  cout<<num_int;
  cout<<endl;
	
  return 0;
}




