#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include <string>

class Weapon {
public:
    virtual int getDamage() const = 0;
};

class Armor {
public:
    virtual int reduceDamage(int damage) const = 0;
};

class Hero {
protected:
    std::string name;
    Weapon* weapon;
    Armor* armor;
    int blockChance;
    int health;
    int maxhealth;

public:
    Hero(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
        : name(name), weapon(weapon), armor(armor), blockChance(blockChance), health(health), maxhealth(health) {}

    virtual ~Hero() {
        delete weapon;
        delete armor;
    }

    std::string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    void restoreHealth()
    {
        this->health = maxhealth;
    }

    bool isAlive() const {
        return health > 0;
    }

    void equipWeapon(Weapon* newWeapon) {
        delete weapon;
        weapon = newWeapon;
    }

    void equipArmor(Armor* newArmor) {
        delete armor;
        armor = newArmor;
    }

    int attack() const {
        return weapon->getDamage();
    }

    void receiveDamage(int damage) {
        if (rand() % 100 < blockChance) {
            std::cout << this->name << " blocked the attack!\n";
        } else {
            health -= armor->reduceDamage(damage);
        }
    }

    std::string getWeaponName() const {
        // Проверка, что оружие не является nullptr
        if (weapon != NULL) {
            // Используем typeid для получения имени класса оружия
            return typeid(*weapon).name();
        }
        return "No weapon equipped";
    }

    std::string getArmorName() const {
        // Проверка, что броня не является nullptr
        if (armor != NULL) {
            // Используем typeid для получения имени класса брони
            return typeid(*armor).name();
        }
        return "No armor equipped";
    }
};

class Sword : public Weapon {
public:
    int getDamage() const override {
        return 60;
    }
};

class LongSword : public Weapon {
public:
    int getDamage() const override {
        return 70;
    }
};

class Bow : public Weapon {
public:
    int getDamage() const override {
        return 40;
    }
};

class Hammer : public Weapon {
public:
    int getDamage() const override {
        return 80;
    }
};

class Firearm : public Weapon {
public:
    int getDamage() const override {
        return 1000;
    }
};

class Gladius : public Weapon {
public:
    int getDamage() const override {
        return 60;
    }
};

class LightArmor : public Armor {
public:
    int reduceDamage(int damage) const override {
        return damage - 15;
    }
};

class MediumArmor : public Armor {
public:
    int reduceDamage(int damage) const override {
        return damage - 20;
    }
};

class HeavyArmor : public Armor {
public:
    int reduceDamage(int damage) const override {
        return damage - 30;
    }
};

class NoArmor : public Armor {
public:
    int reduceDamage(int damage) const override {
        return damage;
    }
};

class Gladiator : public Hero {
public:
    Gladiator(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health) : Hero(name, weapon, armor, blockChance, health) {}
};

class Peasant : public Hero {
public:
    Peasant(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
        : Hero(name, weapon, armor, blockChance, health) {}
};

class Veteran : public Hero {
public:
    Veteran(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
        : Hero(name, weapon, armor, blockChance, health) {}
};

class Knight : public Hero {
public:
    Knight(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
        : Hero(name, weapon, armor, blockChance, health) {}
};

class Troll : public Hero {
public:
    Troll(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
        : Hero(name, weapon, armor, blockChance, health) {}
};

class Orc : public Hero {
public:
    Orc(const std::string& name, Weapon* weapon, Armor* armor, int blockChance, int health)
        : Hero(name, weapon, armor, blockChance, health) {}
};

Weapon* getRandomWeapon() {
    int weaponType = rand() % 4; 

    switch (weaponType) {
        case 0:
            return new Sword();
        case 1:
            return new Bow();
        case 2:
            return new Hammer();
        case 3:
            return new Firearm();
        default:
            return new Sword(); // По умолчанию выбираем меч
    }
}

Armor* getRandomArmor() {
    int armorType = rand() % 4;

    switch (armorType) {
        case 0:
            return new LightArmor();
        case 1:
            return new MediumArmor();
        case 2:
            return new HeavyArmor();
        case 3:
            return new NoArmor();
        default:
            return new LightArmor(); // По умолчанию выбираем легкую броню
    }
}

void teamBattle(const std::vector<Hero*>& team1, const std::vector<Hero*>& team2) {
    int scoreTeam1 = 0, scoreTeam2 = 0;

    std::cout << "Team 1 has " << team1.size() << " heroes\n";
    std::cout << "Team 2 has " << team2.size() << " heroes\n";

    size_t i = 0, j = 0;

    while (i < team1.size() && j < team2.size()) {

        Hero* attacker = team1[i];
        Hero* defender = team2[j];

        while (attacker->isAlive() && defender->isAlive()) {
            std::cout << "--------------------------------------------\n";
            std::cout << attacker->getName() << " - Health: " << attacker->getHealth() << "    Weapon: " << attacker->getWeaponName() << "    Armor: " << attacker->getArmorName();
            std::cout << "          " << "Battle " << i + 1 << "          " << defender->getName() << " - Health: " << defender->getHealth() << "    Weapon: " << defender->getWeaponName() << "    Armor: " << defender->getArmorName() << "\n";

            int attackerDamage = attacker->attack();
            
            std::string turnInfo = "Turn: " + attacker->getName() + " attacks " + defender->getName() + " for " + std::to_string(attackerDamage) + " damage.";
            std::cout << std::setw(60) << std::right << turnInfo << "\n";
            defender->receiveDamage(attackerDamage);
            std::cout << attacker->getName() << " Health: " << attacker->getHealth() << ", " << defender->getName() << " Health: " << defender->getHealth() << ". ";
            std::cout << "Score: " << scoreTeam1 << " : " << scoreTeam2 << "\n";
            
            if (!defender->isAlive()) {
                if (attacker == team1[i]) {
                    scoreTeam1++;
                } else {
                    scoreTeam2++;
                }
                std::cout << "--------------------------------------------\n";
                std::cout << "--------------------------------------------\n";
                break;
            }

            // Случайный выбор атакующего и защищающегося героев на следующем "сражении"
            std::swap(attacker, defender);
        }

        // Переход к следующему герою в команде
        (attacker == team1[i]) ? j++ : i++;
    }

    std::cout << "--------------------------------------------\n";
    std::cout << "Team Battle ended!\n";

    if (scoreTeam1 > scoreTeam2) {
        std::cout << "Team 1 wins!\n";
    } else if (scoreTeam1 < scoreTeam2) {
        std::cout << "Team 2 wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }
}

void gladiatorBattle(Hero& gladiator1, Hero& gladiator2) {
    int step = 1;
    std::cout << "gladiatorBattle\n";
    while(gladiator1.isAlive() && gladiator2.isAlive())
    {
        std::cout << "--------------------------------------------\n\n\n";
        std::cout << std::setw(40) <<"Step: " << step << std::endl;
        std::cout << std::setw(30) << std::left << gladiator1.getName() << " - Health: " << gladiator1.getHealth() << "    Weapon: " << gladiator1.getWeaponName() << "    Armor: " << gladiator1.getArmorName();
        std::cout << std::setw(30) << std::right << gladiator2.getName() << " - Health: " << gladiator2.getHealth() << "    Weapon: " << gladiator2.getWeaponName() << "    Armor: " << gladiator2.getArmorName() << "\n";

        Hero& attacker = (rand() % 2 == 0) ? gladiator1 : gladiator2;
        Hero& defender = (&attacker == &gladiator1) ? gladiator2 : gladiator1;
        int attackerDamage = attacker.attack();

        std::string turnInfo = "Turn: " + attacker.getName() + " attacks " + defender.getName() + " for " + std::to_string(attackerDamage) + " damage.";
        std::cout << std::setw(60) << std::right << turnInfo << "\n";

        defender.receiveDamage(attackerDamage);

        std::cout << "--------------------------------------------\n";
        std::cout << gladiator1.getName() << " Health: " << gladiator1.getHealth() << "\t " << gladiator2.getName() << " Health: " << gladiator2.getHealth() << ".\n";

        std::cout << "--------------------------------------------\n";
        
        step++;
        }
        if (!gladiator1.isAlive()) {
            std::cout << gladiator2.getName() << " wins!\n";
        } else {
            std::cout << gladiator1.getName() << " wins!\n";
        }
        std::cout << "Gladiator Battle ended!\n";
}

void tournament(Hero& hero1, Hero& hero2) {
    int round = 1;
    int scoreHero1 = 0, scoreHero2 = 0;
    const int maxScore = 5;
    while (scoreHero1 < maxScore && scoreHero2 < maxScore) 
    {
        hero1.equipWeapon(getRandomWeapon());
        hero1.equipArmor(getRandomArmor());
        hero2.equipWeapon(getRandomWeapon());
        hero2.equipArmor(getRandomArmor());

        while(hero1.isAlive() && hero2.isAlive())
        {
            std::cout << "--------------------------------------------\n";
            std::cout  << hero1.getName() << " - Health: " << hero1.getHealth() << "    Weapon: " << hero1.getWeaponName() << "    Armor: " << hero1.getArmorName();
            std::cout << "             "<< "Round " << round << " - Score: " << scoreHero1 << " : " << scoreHero2 << "             " << hero2.getName() << " - Health: " << hero2.getHealth() << "    Weapon: " << hero2.getWeaponName() << "    Armor: " << hero2.getArmorName() << "\n";

            Hero& attacker = (rand() % 2 == 0) ? hero1 : hero2;
            Hero& defender = (&attacker == &hero1) ? hero2 : hero1;
            int attackerDamage = attacker.attack();

            std::string turnInfo = "Turn: " + attacker.getName() + " attacks " + defender.getName() + " for " + std::to_string(attackerDamage) + " damage.";
            std::cout << std::setw(60) << std::right << turnInfo << "\n";

            defender.receiveDamage(attackerDamage);

            std::cout << hero1.getName() << " Health: " << hero1.getHealth() << "\t " << hero2.getName() << " Health: " << hero2.getHealth() << ".\n";
            
        
            if (!defender.isAlive()) {
                if (&attacker == &hero1) {
                    scoreHero1++;
                    std::cout <<"Round win: " << hero1.getName() << std::endl;
                } else {
                    scoreHero2++;
                    std::cout <<"Round win: " << hero2.getName() << std::endl;
                }
            
            }
            std::cout << "--------------------------------------------\n";
            std::cout << "--------------------------------------------\n";
        }
        round++;
        hero1.restoreHealth();
        hero2.restoreHealth();
        if (scoreHero1 == maxScore) {
            std::cout << "--------------------------------------------\n\n";
            std::cout << hero1.getName() << " wins!\n";
            
        }
        else if (scoreHero2 == maxScore){
            std::cout << "--------------------------------------------\n\n";
            std::cout << hero2.getName() << " wins!\n";
            
        }
    }
    std::cout << "Tournament ended!\n";
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));
    srand(time(NULL));
    // Создание персонажей
    Hero* peasant1 = new Peasant("Peasant 1", new Sword(), new LightArmor(), 10, 100);
    Hero* peasant2 = new Peasant("Peasant 2", new Bow(), new MediumArmor(), 10, 100);
    Hero* peasant3 = new Peasant("Peasant 3", new Bow(), new MediumArmor(), 10, 100);
    Hero* veteran1 = new Veteran("Veteran 1", new Hammer(), new MediumArmor(), 60, 100);
    Hero* knight = new Knight("knight", new LongSword(), new HeavyArmor(), 60, 100);
    
    Hero* gladiator1 = new Gladiator("FirstGladiator", new Gladius(), new NoArmor(), 80, 100);
    Hero* gladiator2 = new Gladiator("SecondGladiator", new Gladius(), new NoArmor(), 80, 100);

    Hero* troll = new Troll("Troll 1", new Hammer(), new HeavyArmor(), 10, 200);
    Hero* orc = new Orc("Orc 1", new Sword(), new MediumArmor(), 30, 150);

    // Создание команд героев
    std::vector<Hero*> team1;
    team1.push_back(knight);
    team1.push_back(peasant2);
    team1.push_back(troll);

    std::vector<Hero*> team2;
    team2.push_back(gladiator1);
    team2.push_back(veteran1);
    team2.push_back(orc);

    teamBattle(team1, team2);

    //tournament(*peasant1, *peasant2);

    //gladiatorBattle(*gladiator1, *gladiator2);

    delete peasant1;
    delete peasant2;
    delete veteran1;
    delete gladiator1;
    delete gladiator2;
    delete troll;
    delete orc;

    return 0;
}