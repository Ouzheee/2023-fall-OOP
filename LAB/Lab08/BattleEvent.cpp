#include "BattleEvent.h"
#include <iostream>
using namespace std;
void BattleEvent::start(Player &player, Monster &monster) {
    while (player.isAlive() && monster.isAlive()) {
        monster.print();
        player.print();
        //write by yourself
        player.attack(monster);
        if (monster.isAlive()){
            monster.attack(player);
        }

    }
}
