#include <iostream>
#include "organism.h"
/* cSpell:disable */
using namespace std;

int main(){
    //initialize
    int xDoodle, yDoodle, ant1_x, ant1_y, ant2_x, ant2_y, ant3_x, ant3_y;
    char Run;
    int time=1;

    cin >> xDoodle >> yDoodle >> ant1_x >> ant1_y >> ant2_x >>
    ant2_y >> ant3_x >> ant3_y;
    DoodleBug doodle(xDoodle, yDoodle);
    Ant ant1(ant1_x, ant1_y);
    Ant ant2(ant2_x, ant2_y);
    Ant ant3(ant3_x, ant3_y);

    char **Grid = new char*[6];
    for (int i=0; i<6; i++){
      Grid[i] = new char [6];
    }
    for (int i=0; i<6;i++){
        for (int j=0;j<6;j++){
            Grid[i][j] = '-';
        }
    }
    Grid[xDoodle][yDoodle] = 'x';
    Grid[ant1_x][ant1_y] = 'o';
    Grid[ant2_x][ant2_y] = 'o';
    Grid[ant3_x][ant3_y] = 'o';
    cout << "----time0----" << endl;
    for (int i=4; i >= 0; i--){
        for (int j=0; j <5; j++){
            cout << Grid[j][i];
        }
        cout << endl;
    }
    //char* ptr = &Grid;
    cin >> Run;
    //start loop
    while (Run == 'n'){
        cout << "----time" << time << "----" << endl;

        //start moveing
        doodle.move(Grid);
        ant1.Infilled(doodle.kill);
        ant2.Infilled(doodle.kill);
        ant3.Infilled(doodle.kill);
        for (int i=5; i>=0; i--){
          for (int j=0; j<5; j++){
            if (Grid[j][i] == 'o'){
              if (j == ant1.getcorX() && i == ant1.getcorY() && ant1.isAlive() && !ant1.isMoved()){            
                  ant1.move(Grid);
              }
              else if (j == ant2.getcorX() && i == ant2.getcorY() && ant2.isAlive() && !ant2.isMoved()){

                  ant2.move(Grid);
              }
              else if (j == ant3.getcorX() && i == ant3.getcorY() && ant3.isAlive() && !ant3.isMoved()){
                  ant3.move(Grid);
              }
            }
          }
        }
        

        //reset the map
        for (int i=0; i<5;i++){
            for (int j=0;j<5;j++){
                Grid[i][j] = '-';
            }
        }
        Grid[doodle.getcorX()][doodle.getcorY()] = 'x';
        if (ant1.isAlive()){
            Grid[ant1.getcorX()][ant1.getcorY()] = 'o';
        }
        if (ant2.isAlive()){
            Grid[ant2.getcorX()][ant2.getcorY()] = 'o';
        }
        if (ant3.isAlive()){
            Grid[ant3.getcorX()][ant3.getcorY()] = 'o';
        }

        //Output the map
        for (int i=4; i >= 0; i--){
            for (int j=0; j < 5; j++){
                cout << Grid[j][i];
            }
            cout << endl;
        }
        time++;
        doodle.changeMoved();
        ant1.changeMoved();
        ant2.changeMoved();
        ant3.changeMoved();
        cin >> Run;

    }
    for (int i=0; i<5; i++){
      delete [] Grid[i];
    }
    delete [] Grid;

  return 0;
}