#include "Ship3.h"

Ship3::Ship3()
{

}

//attack in cross shape, selected coordinate as the center
vector<int> Ship3::specialAbility(int i, int j){
    vector<int> affected;
    for(int x=-1;x<2;x++){
        affected.push_back(j+x);
        affected.push_back(i);
    }
    affected.push_back(i-1);
    affected.push_back(j);
    affected.push_back(i+1);
    affected.push_back(j);
    return affected;
}
