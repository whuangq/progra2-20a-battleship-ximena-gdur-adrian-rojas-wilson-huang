#ifndef SHIP1_H
#define SHIP1_H


class Ship1
{
public:
    Ship1();
    int lives=1;
    vector<int> specialAbility() const override;
};

#endif // SHIP1_H
