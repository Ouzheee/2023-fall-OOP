#include <iostream>
#include "organism.h"
using namespace std;
/* cSpell:disable */
Organism::Organism(int x, int y):corx(x), cory(y), Hasmoved(false){}

int Organism::getcorX(){
    return corx;
}
int Organism::getcorY(){
    return cory;
}

bool Organism::isMoved(){
    return Hasmoved;
}

void Organism::changeMoved(){
    Hasmoved = false;
}

void Organism::move(char** array){
    Hasmoved = true;
    if (array[corx][cory+1] == '-' && ((cory+1) <=4)){  //Upward
        //cout << "(" << corx << "," << cory << ") moved upward" << endl;
        cory++;
        array[corx][cory] = 'o';
        array[corx][cory-1] = '-';        
    }
    else if (array[corx+1][cory] == '-' && ((corx+1) <=4)){  //rightward
        //cout << "(" << corx << "," << cory << ") moved rightward" << endl;
        corx++;
        array[corx][cory] = 'o';
        array[corx-1][cory] = '-';
    }
    else if (array[corx][cory-1] == '-' && ((cory-1) >=0)){  //Downward
        //cout << "(" << corx << "," << cory << ") moved downward" << endl;
        cory--;
        array[corx][cory] = 'o';
        array[corx][cory+1] = '-';
    }
    else if (array[corx-1][cory] == '-' && ((corx-1) >=0)){  //leftward
        //cout << "(" << corx << "," << cory << ") moved leftward" << endl;
        corx--;
        array[corx][cory] = 'o';
        array[corx+1][cory] = '-';
    }
}

//-----------DoodleBug-------------------------
DoodleBug::DoodleBug(int x, int y) : Organism(x,y){
    kill[0] = 5;
    kill[1] = 5;
}


void DoodleBug::move(char** array){
    Hasmoved = true;
    
    if (corx == 0){ //在最左邊
        //hunt
        if (array[corx][cory+1] == 'o' && ((cory+1) <=4)){  //Upward
            cory++;
            kill[0] = corx;
            kill[1] = cory;
            array[corx][cory] = 'x';
            array[corx][cory-1] = '-';
        }
        else if (array[corx+1][cory] == 'o' && ((corx+1) <=4)){  //rightward
            corx++;
            kill[0] = corx;
            kill[1] = cory;
            array[corx][cory] = 'x';
            array[corx-1][cory] = '-';
        }
        else if (array[corx][cory-1] == 'o' && ((cory-1) >0)){  //不看左邊，Downward
            cory--;
            kill[0] = corx;
            kill[1] = cory;
            array[corx][cory] = 'x';
            array[corx][cory+1] = '-';
        }
        //在最左邊且純移動
        else if (array[corx][cory+1] == '-' && ((cory+1) <= 4)){  //Upward
            //cout << "Doo (" << corx << "," << cory << ") moved upward" << endl;
            cory++;
            array[corx][cory] = 'x';
            array[corx][cory-1] = '-';
        }
        else if (array[corx+1][cory] == '-'){  //rightward
            //cout << "Doo (" << corx << "," << cory << ") moved rightward" << endl;
            corx++;
            array[corx][cory] = 'x';
            array[corx-1][cory] = '-';
        }
        else{  //上述條件都不達成，最後一定要Downward
            //cout << "Doo (" << corx << "," << cory << ") moved downward" << endl;
            cory--;
            array[corx][cory] = 'x';
            array[corx][cory+1] = '-';
        }
    
    }
    else if (corx == 4){ //在最右邊
        //hunt
        if (array[corx][cory+1] == 'o' && ((cory+1) <=4)){  //Upward
            cory++;
            kill[0] = corx;
            kill[1] = cory;
            array[corx][cory] = 'x';
            array[corx][cory-1] = '-';
        }
        else if (array[corx][cory-1] == 'o' && ((cory-1) >0)){  //Downward
            cory--;
            kill[0] = corx;
            kill[1] = cory;
            array[corx][cory] = 'x';
            array[corx][cory+1] = '-';
        }
        else if (array[corx-1][cory] == 'o' && ((corx-1) >0)){  //leftward
            corx--;
            kill[0] = corx;
            kill[1] = cory;
            array[corx][cory] = 'x';
            array[corx+1][cory] = '-';
        }
        //-------最右邊且純移動----------------
        else if (array[corx][cory+1] == '-' && ((cory+1) <= 4)){  //Upward
            //cout << "Doo (" << corx << "," << cory << ") moved upward" << endl;
            cory++;
            array[corx][cory] = 'x';
            array[corx][cory-1] = '-';
        }
        else if (array[corx][cory-1] == '-' && ((cory-1) >=0)){  //Downward
            //cout << "Doo (" << corx << "," << cory << ") moved downward" << endl;
            cory--;
            array[corx][cory] = 'x';
            array[corx][cory+1] = '-';
        }
        else{  //leftward
            //cout << "Doo (" << corx << "," << cory << ") moved leftward" << endl;
            corx--;
            array[corx][cory] = 'x';
            array[corx+1][cory] = '-';
        }
    }
    
    //------------不在最左邊或最右邊----------------
    else if (array[corx][cory+1] == 'o' && ((cory+1) <=4)){  //Upward
        cory++;
        kill[0] = corx;
        kill[1] = cory;
        array[corx][cory] = 'x';
        array[corx][cory-1] = '-';
    }
    else if (array[corx+1][cory] == 'o' && ((corx+1) <=4)){  //rightward
        corx++;
        kill[0] = corx;
        kill[1] = cory;
        array[corx][cory] = 'x';
        array[corx-1][cory] = '-';
    }
    else if (array[corx][cory-1] == 'o' && ((cory-1) >=0)){  //Downward
        cory--;
        kill[0] = corx;
        kill[1] = cory;
        array[corx][cory] = 'x';
        array[corx][cory+1] = '-';
    }
    else if (array[corx-1][cory] == 'o' && ((corx-1) >=0)){  //leftward
        corx--;
        kill[0] = corx;
        kill[1] = cory;
        array[corx][cory] = 'x';
        array[corx+1][cory] = '-';
    }
    //-------------一般情況--------------
    else if (array[corx][cory+1] == '-' && ((cory+1) <= 4)){  //Upward
        //cout << "Doo (" << corx << "," << cory << ") moved upward" << endl;
        cory++;
        array[corx][cory] = 'x';
        array[corx][cory-1] = '-';
    }
    else if (array[corx+1][cory] == '-' && ((corx+1) <= 4)){  //rightward
        //cout << "Doo (" << corx << "," << cory << ") moved rightward" << endl;
        corx++;
        array[corx][cory] = 'x';
        array[corx-1][cory] = '-';
    }
    else if (array[corx][cory-1] == '-' && ((cory-1) >=0)){  //Downward
        //cout << "Doo (" << corx << "," << cory << ") moved downward" << endl;
        cory--;
        array[corx][cory] = 'x';
        array[corx][cory+1] = '-';
    }
    else if (array[corx-1][cory] == '-' && ((corx-1) >=0)){  //leftward
        //cout << "Doo (" << corx << "," << cory << ") moved leftward" << endl;
        corx--;
        array[corx][cory] = 'x';
        array[corx+1][cory] = '-';
    }
}

//-----------------Ant-------------------------
Ant::Ant(int x, int y) : Organism(x,y), alive(true){}

void Ant::move(char** array){
    Hasmoved = true;
    if (array[corx][cory+1] == '-' && ((cory+1) <=4)){  //Upward
        //cout << "(" << corx << "," << cory << ") moved upward" << endl;
        cory++;
        array[corx][cory] = 'o';
        array[corx][cory-1] = '-';        
    }
    else if (array[corx+1][cory] == '-' && ((corx+1) <=4)){  //rightward
        //cout << "(" << corx << "," << cory << ") moved rightward" << endl;
        corx++;
        array[corx][cory] = 'o';
        array[corx-1][cory] = '-';
    }
    else if (array[corx][cory-1] == '-' && ((cory-1) >=0)){  //Downward
        //cout << "(" << corx << "," << cory << ") moved downward" << endl;
        cory--;
        array[corx][cory] = 'o';
        array[corx][cory+1] = '-';
    }
    else if (array[corx-1][cory] == '-' && ((corx-1) >=0)){  //leftward
        //cout << "(" << corx << "," << cory << ") moved leftward" << endl;
        corx--;
        array[corx][cory] = 'o';
        array[corx+1][cory] = '-';
        
    }
}

void Ant::Infilled(char kill[]){
    if (corx == kill[0] && cory == kill[1]){
        alive = false;
        //cout << "(" << corx << "," << cory << ") is killed" << endl;
    }
}

bool Ant::isAlive(){
    return alive;
}