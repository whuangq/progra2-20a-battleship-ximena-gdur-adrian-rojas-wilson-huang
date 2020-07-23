#include "Ship2.h"

Ship2::Ship2()
{

}
//attack in a 3 length horizontal line
vector<int> Ship2::specialAbility(int i, int j){
    vector<int> affected;
    for(int x=-1;x<2;x++){
        affected.push_back(j+x);
        affected.push_back(i);
    }
    return affected;
}
