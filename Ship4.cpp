#include "Ship4.h"

Ship4::Ship4()
{

}
//attack a 3x3 perimeter around the selected coordinate
vector<int> Ship4::specialAbility(int i, int j){
    vector<int> affected;
    for(int x=-1;x<2;x++){
        for(int y=-1;y<2;y++){
            if(x!=0 && y!=0){
                affected.push_back(i+x);
                affected.push_back(j+y);
            }
        }
    }
    return affected;
}
