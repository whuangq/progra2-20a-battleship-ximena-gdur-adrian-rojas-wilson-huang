#ifndef SHIP3_H
#define SHIP3_H


class Ship3 : public Ship
{
public:
    Ship3();
    int lives=3;
     vector<int> specialAbility() const override;
};

#endif // SHIP3_H
