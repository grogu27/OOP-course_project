#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include <string>
#include "hero.hpp"

void teamBattle(const std::vector<Hero*>& team1, const std::vector<Hero*>& team2);
void gladiatorBattle(Hero& gladiator1, Hero& gladiator2);
void tournament(Hero& hero1, Hero& hero2);
Weapon* getRandomWeapon();
Armor* getRandomArmor();
#endif // BATTLE_H