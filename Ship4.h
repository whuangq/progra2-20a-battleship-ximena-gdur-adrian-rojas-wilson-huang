#ifndef SHIP4_H
#define SHIP4_H


class Ship4 : public Ship
{
public:
    Ship4();
    int lives=4;
    vector<int> specialAbility() const override;
};

#endif // SHIP4_H
