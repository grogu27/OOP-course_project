#include "armor.hpp"

int LightArmor::reduceDamage(int damage) const {
    return damage - 15;
}

int MediumArmor::reduceDamage(int damage) const {
    return damage - 20;
}

int HeavyArmor::reduceDamage(int damage) const {
    return damage - 30;
}

int NoArmor::reduceDamage(int damage) const {
    return damage;
}

