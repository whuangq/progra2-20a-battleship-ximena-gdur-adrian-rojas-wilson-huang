#include "cell.h"
#include "ship.h"
Cell::Cell()
{
    
}
bool attacked=false;
Ship* ship_ptr;

bool isEmpty(){
    if(ship_ptr!=nullptr) return false;
    return true;
}

int attack(){
   if(attacked==false){
        if(!isEmpty()){
            ship_ptr->loseLife();
        }
    attacked=true;
   }
 return 0;
}


