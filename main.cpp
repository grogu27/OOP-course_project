#include "hero.hpp"
#include "battle.hpp"

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
    //team1.push_back(troll);

    std::vector<Hero*> team2;
    team2.push_back(gladiator1);
    team2.push_back(veteran1);
    //team2.push_back(orc);

    //teamBattle(team1, team2);

    //tournament(*peasant1, *peasant2);

    gladiatorBattle(*gladiator1, *gladiator2);

    delete peasant1;
    delete peasant2;
    delete veteran1;
    delete gladiator1;
    delete gladiator2;
    delete troll;
    delete orc;

    return 0;
}