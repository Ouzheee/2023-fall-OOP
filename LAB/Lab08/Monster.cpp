#include "Monster.h"
#include "Player.h" // Add this include directive to access the full definition of the Player class
#include <iostream>
using namespace std;

//write constructor
Monster::Monster(string _name, int _health, int _damage) :
LivingEntity(_name, _health, _damage), getexperience(0.5*_health){}


void Monster::attack(Player &player) {
    std::cout << name << " attacks for " << damage << " damage!" << std::endl;
    player.takeDamage(damage);
}

int Monster::getExperience() {
     // your turn
    return getexperience;
}

BossMonster::BossMonster(string _name, int _health, int _damage) 
: Monster(_name, _health, _damage){}

FlyingMonster::FlyingMonster(string _name, int _health, int _damage) 
: Monster(_name, _health, _damage){}

GroundMonster::GroundMonster(string _name, int _health, int _damage) 
: Monster(_name, _health, _damage){}

MagicMonster::MagicMonster(string _name, int _health, int _damage) 
: Monster(_name, _health, _damage){}
