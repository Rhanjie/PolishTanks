#include "Status.hpp"

void RhA::CStats::setStatus(eStats typeOfStats, int value){
    switch(typeOfStats){
        case HEALTH:
         health += value;
         if(health > maxHealth)
          health = maxHealth;
        break;

        case MAXHEALTH:
         maxHealth += value;
         health += value;
        break;

        case MONEY:
         money += value;
        break;
    }
}


int RhA::CStats::getStatus(eStats typeOfStats){
    switch(typeOfStats){
        case HEALTH:
          return health;
        break;

        case MAXHEALTH:
         return maxHealth;
        break;

        case MONEY:
         return money;
        break;
    }
}
