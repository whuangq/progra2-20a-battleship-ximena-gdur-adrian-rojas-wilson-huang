#ifndef SHIP2_H
#define SHIP2_H


class Ship2 : public Ship
{
public:
    Ship2();
    int lives=2;
     vector<int> specialAbility() const override;
};

#endif // SHIP2_H
