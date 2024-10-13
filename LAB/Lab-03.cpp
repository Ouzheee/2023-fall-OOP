#include <iostream>
#include <fstream>
using namespace std;
/* cSpell:disable */
int main(int argc, char* argv[]){
    ifstream fin(argv[1], ios::in);  //以argv讀檔
    int** Maze = new int* [5];  //紀錄怪獸位置的二微陣列
    for (int i=0; i<5; i++){
        Maze[i] = new int [5];
    }
    int* Mosatk = new int [25];  //對應怪獸的攻擊力
    int* Mosexp = new int [25];  //對應怪獸的經驗值
    char* move = new char [25];  //要移動的動作
    for (int i=0; i<25; i++){
        move[i] = '0'; 
    }
    int MazeId=0, n=0;
    int atk=0, exp=0;
    for (int row=0; row<5; row++){
        for(int col=0; col<5; col++){
            fin >> MazeId;
            Maze[row][col] = MazeId;
        }
    }  
    for (int row=0; row<25; row++){
        fin >> atk >> exp;
        Mosatk[row] = atk;
        Mosexp[row] = exp;
    } 
    char read;
    while (fin >> read){
        *(move+n) = read;
        n++;
    } 
    
    int HP=100, level=1,step=0, MosId=0;  //各數據初始化
    int xpos=0, ypos=0;  //以左上角為(0,0)
    exp=0; 

    while (HP>0 && step < n){
        if (move[step] == 'U'){  //往上就是y減1
            ypos--;
        }
        else if (move[step] == 'D'){
            ypos++;
        }
        else if (move[step] == 'R'){
            xpos++;
        }
        else if (move[step] == 'L'){
            xpos--;
        }
         
        MosId = Maze[ypos][xpos];  //移動後找遇到哪個怪獸，先取ypos因為前面是row，後面才是column
        HP -= Mosatk[MosId];
        if (HP <=0){  //血被扣完就結束，此判斷在經驗值之前
            cout << "DEAD";
            break;
        }
        exp += Mosexp[MosId];
        if (exp >= 100){ 
            level++;
            HP=100;
            exp=0;
        }
        cout << "Step  " << ++step << ":\nlevel:" << level ;
        cout << " hp:" << HP << " exp:" << exp << endl << endl;
    }

    
    //關閉檔案、刪除dynamic array占用的記憶體
    fin.close();
    for (int i=0; i<5; i++){
        delete [] Maze[i];
    }
    delete [] Maze;
    Maze = NULL;
    delete [] Mosatk;
    Mosatk = NULL;
    delete [] Mosexp;
    Mosexp = NULL;
    delete [] move;
    move = NULL;
    return 0;
}