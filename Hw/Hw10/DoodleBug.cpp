#include <iostream>
#include "DoodleBug.h"
using namespace std;

DoodleBug::DoodleBug(int x, int y) : Organism(x,y){
    kill[0] = 5;
    kill[1] = 5;
}

void DoodleBug::move(char** array){
    Hasmoved = !Hasmoved;
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
    else if (array[corx][cory-1] == 'o' && ((cory-1) >=0)){  //Downward
        cory--;
        kill[0] = corx;
        kill[1] = cory;
        array[corx][cory] = 'x';
        array[corx][cory+1] = '-';
    }
    else if (array[corx-1][cory] == 'o' && ((corx-1) <=4)){  //leftward
        corx--;
        kill[0] = corx;
        kill[1] = cory;
        array[corx][cory] = 'x';
        array[corx+1][cory] = '-';
    }
    //--------¤@¯ë±¡ªp------------
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