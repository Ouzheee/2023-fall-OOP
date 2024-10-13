#include <fstream>
#include "CNumpy.h"
using namespace std;

CNumpy::CNumpy(const char *input_filename){
    ifstream fin(input_filename);
    int read;
    fin >> row >> col;
    matrix = new int* [row];
    for (int i=0; i<row; i++){  //建立陣列
        matrix[i] = new int [col];
    }
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            fin >> read;
            matrix[i][j] = read;
        }
    }
}
CNumpy::~CNumpy(){
    for (int i=0; i<row; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}

//getter
int **CNumpy::getMatrix()const{
    return matrix;
}
int CNumpy::getRow()const{
    return row;
}
int CNumpy::getCol()const{
    return col;
}

//////////part 2///////////////
int CNumpy::min()const{
    int mini= matrix[0][0];
    for (int i=0; i< row; i++){
        for (int j=0; j<col; j++){
            if (matrix[i][j] < mini){
                mini = matrix[i][j];
            }
        }
    }
    return mini;
}
int CNumpy::max()const{
    int Max= matrix[0][0];
    for (int i=0; i< row; i++){
        for (int j=0; j<col; j++){
            if (matrix[i][j] > Max){
                Max = matrix[i][j];
            }
        }
    }
    return Max;
}
void CNumpy::argmin(int *idx1, int *idx2){
    int mini= matrix[0][0];
    *idx1 = 0;
    *idx2 = 0;
    for (int i=0; i< row; i++){
        for (int j=0; j<col; j++){
            if (matrix[i][j] < mini){
                mini = matrix[i][j];
                *idx1 = i;
                *idx2 = j;
            }
        }
    }
    return;
}
void CNumpy::argmax(int *idx1, int *idx2){
    int Max= matrix[0][0];
    *idx1 = 0;
    *idx2 = 0;
    for (int i=0; i< row; i++){
        for (int j=0; j<col; j++){
            if (matrix[i][j] > Max){
                Max = matrix[i][j];
                *idx1 = i;
                *idx2 = j;
            }
        }
    }
    return;
}

/////part 3////////////
void CNumpy::concatenate(const CNumpy &c2, int axis){
    int **m2 = c2.getMatrix();
    int row2 = c2.getRow();
    int col2 = c2.getCol();
    if (axis == 0){
        int **tmp = new int* [row+row2];
        for (int i=0; i<row+row2; i++){
            tmp[i] = new int [col];
        }
        for (int i=0; i<row; i++){ //先把原資料儲存下來
            for (int j=0; j<col; j++){
              tmp[i][j] = matrix[i][j];
            }  
        }
        for (int i=0; i<row2; i++){
            for (int j=0; j<col2; j++){
              tmp[i+row][j] = m2[i][j];
            }
        }
        for (int i=0; i<row; i++){  //先清除原陣列
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = tmp;  //指定成新的
        row += row2;
    }
    
    else{
        int **tmp = new int* [row];   //建立暫存用陣列
        for (int i=0; i<row; i++){
            tmp[i] = new int [col+col2];
        }

        for (int i=0; i<row; i++){  //儲存原本的值
            for (int j=0; j<col; j++){
                tmp[i][j] = matrix[i][j];
            } 
            for (int z=0; z<col2; z++){
                tmp[i][z+col] = m2[i][z]; //插入新的值
            }
        }
        for (int i=0; i<row; i++){  //刪除原陣列
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = tmp;  //取代
        col += col2;  //變更col值
    }

    return;
}


void CNumpy::render(){
    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){
            if(matrix[i][j] > 127){
                cout << "@@";
            }
            else{
                cout << "__";
            }
        }
        cout << endl;
    }
}
