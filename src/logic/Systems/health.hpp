#pragma once 

class Health {
public:
    Health();
    ~Health();

    void takeDamage(int damage);
    void heal(int amount);

    int getHealthPoints() const;
    void setHealthPoints(int hp);

private:
    int healthPoints;

};