#include <iostream>
#include "Ant.h"

Ant::Ant(int x, int y) : Organism(x,y), alive(true){}

void Ant::move(char** array){
    Hasmoved = !Hasmoved;
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