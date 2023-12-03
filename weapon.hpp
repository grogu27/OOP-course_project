#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    virtual int getDamage() const = 0;
};

class Sword : public Weapon {
public:
    int getDamage() const override;
};

class LongSword : public Weapon {
public:
    int getDamage() const override;
};

class Bow : public Weapon {
public:
    int getDamage() const override;
};

class Hammer : public Weapon {
public:
    int getDamage() const override;
};

class Firearm : public Weapon {
public:
    int getDamage() const override; 
};

class Gladius : public Weapon {
public:
    int getDamage() const override;

};

#endif // WEAPON_H
