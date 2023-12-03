#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include <string>
#include "weapon.hpp"
#include "armor.hpp"

class Hero {
protected:
    std::string name;
    Weapon* weapon;
    Armor* armor;
    int blockChance;
    int health;
    int maxhealth;

public:
    Hero(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health);
        

    virtual ~Hero();

    std::string getName() const;

    int getHealth() const;
  
    void restoreHealth();
    
    bool isAlive() const ;
   
    void equipWeapon(Weapon* newWeapon);
  
    void equipArmor(Armor* newArmor);
   
    int attack() const;
 
    void receiveDamage(int damage);
  
    std::string getWeaponName() const;

    std::string getArmorName() const;

};

class Gladiator : public Hero {
public:
    Gladiator(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health);
};

class Peasant : public Hero {
public:
    Peasant(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health);
        
};

class Veteran : public Hero {
public:
    Veteran(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health);
       
};

class Knight : public Hero {
public:
    Knight(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health);
        
};

class Troll : public Hero {
public:
    Troll(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health);
       
};

class Orc : public Hero {
public:
    Orc(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health);
        
};

#endif // HERO_H
