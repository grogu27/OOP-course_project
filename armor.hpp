#ifndef ARMOR_H
#define ARMOR_H

class Armor {
public:
    virtual int reduceDamage(int damage) const = 0;
};

class LightArmor : public Armor {
public:
    int reduceDamage(int damage) const override;
};

class MediumArmor : public Armor {
public:
    int reduceDamage(int damage) const override;
};

class HeavyArmor : public Armor {
public:
    int reduceDamage(int damage) const override;
};

class NoArmor : public Armor {
public:
    int reduceDamage(int damage) const override;
};

#endif // ARMOR_H
