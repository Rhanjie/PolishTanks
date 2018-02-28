#include "Person.hpp"

void RhA::CPerson::setStatus(eStats statsType, int value){
    switch(statsType){
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

int RhA::CPerson::getStatus(eStats statsType){
    switch(statsType){
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
