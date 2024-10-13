#include "Player.h"
#include <iostream>
using namespace std;

//write player constructor
Player::Player(string _name, int _health, int _Damage) : LivingEntity(_name, _health, _Damage)
, experience(0), level(1) {}

void Player::attack(Monster &monster) {
    // your turn
    cout << name << " attacks for " << damage << " damage!" << endl;
    if (!monster.takeDamage(damage)){
        gainExperience(monster.getExperience());
    }
}

void Player::gainExperience(int amount) {
    
    // your turn  
    experience += amount;
    cout << name << " gains " << amount << " experience!" << endl;
    if (experience >= level*level*20){
        levelUp();
    }
}

void  Player::restoreHealth(int amount) {
    // your turn
    cout << name << " restores " << amount << " health!" << endl;
    health += amount;
}
void Player::levelUp() {
   // your turn
   cout << name << " levels up to level " << ++level << "!" << endl;
   health += level*20;
   damage = level*20;
  
}

    void Player::print()const{ 
    std::cout << "\n=== Player Stats ===" << std::endl;
    std::cout << "Name: " << name<< std::endl;
    std::cout << "Health: " <<health<< std::endl;
     std::cout << "Level: " << level << std::endl;
     std::cout << "Experience: " <<experience  << std::endl;
     std::cout << "Attack damage: " << damage << std::endl;
     cout<<"==================="<<endl<<endl;}