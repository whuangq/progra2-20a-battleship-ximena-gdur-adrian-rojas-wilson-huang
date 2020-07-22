#include "ship.h"

Ship::Ship(){
    alive=true;
}



void Ship::loseLife(){
    lives--;
    if(lives==0){
        alive=false;
    }
}

void Ship::specialAbility(){

}
