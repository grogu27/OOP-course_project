#include "hero.hpp"

    Hero::Hero(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
        : name(name), weapon(weapon), armor(armor), blockChance(blockChance), health(health), maxhealth(health) {}

    Hero::~Hero() {
        delete weapon;
        delete armor;
    }

    std::string Hero::getName() const {
        return name;
    }

    int Hero::getHealth() const {
        return health;
    }

    void Hero::restoreHealth()
    {
        this->health = maxhealth;
    }

    bool Hero::isAlive() const {
        return health > 0;
    }

    void Hero::equipWeapon(Weapon* newWeapon) {
        delete weapon;
        weapon = newWeapon;
    }

    void Hero::equipArmor(Armor* newArmor) {
        delete armor;
        armor = newArmor;
    }

    int Hero::attack() const {
        return weapon->getDamage();
    }

    void Hero::receiveDamage(int damage) {
        if (rand() % 100 < blockChance) {
            std::cout << this->name << " blocked the attack!\n";
        } else {
            health -= armor->reduceDamage(damage);
        }
    }

    std::string Hero::getWeaponName() const {
        // Проверка, что оружие не является nullptr
        if (weapon != NULL) {
            // Используем typeid для получения имени класса оружия
            return typeid(*weapon).name();
        }
        return "No weapon equipped";
    }

    std::string Hero::getArmorName() const {
        // Проверка, что броня не является nullptr
        if (armor != NULL) {
            // Используем typeid для получения имени класса брони
            return typeid(*armor).name();
        }
        return "No armor equipped";
    }

Gladiator::Gladiator(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health) 
    : Hero(name, weapon, armor, blockChance, health) {}

Peasant::Peasant(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
    : Hero(name, weapon, armor, blockChance, health) {}
    
Veteran::Veteran(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
    : Hero(name, weapon, armor, blockChance, health) {}
        
Knight::Knight(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
    : Hero(name, weapon, armor, blockChance, health) {}
        
Troll::Troll(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
    : Hero(name, weapon, armor, blockChance, health) {}
        
Orc::Orc(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
    : Hero(name, weapon, armor, blockChance, health) {}
        
