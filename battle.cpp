#include "battle.hpp"

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
        std::cout << gladiator1.getName() << " - Health: " << gladiator1.getHealth() << "    Weapon: " << gladiator1.getWeaponName() << "    Armor: " << gladiator1.getArmorName();
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