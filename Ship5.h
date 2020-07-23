#ifndef SHIP5_H
#define SHIP5_H


class Ship5
{
public:
    Ship5();
    int lives=5;
    vector<int> specialAbility() const override;
};

#endif // SHIP5_H
