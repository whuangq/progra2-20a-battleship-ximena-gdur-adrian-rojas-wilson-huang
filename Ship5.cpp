#include "Ship5.h"

Ship5::Ship5()
{

}
//attacks in a 5 length cross
vector<int> Ship5::specialAbility(int i, int j){
    vector<int> affected;
    for(int x=-2;x<3;x++){
            if(x!=0){
                affected.push_back(i+x);
                affected.push_back(j);
                affected.push_back(j+x);
                affected.push_back(i);
            }
            affected.push_back(i);
            affected.push_back(j);
        }
    return affected;
    }
