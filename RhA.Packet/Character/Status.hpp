#ifndef STATUS_HPP_INCLUDED
#define STATUS_HPP_INCLUDED

#include "System/LibrariesIncluding.hpp"

namespace RhA{
    class CStats: public sf::Drawable{
        public:
         enum eStats{HEALTH, MAXHEALTH, MONEY};

         void setStatus(eStats typeOfStats, int value);
         int getStatus(eStats typeofStats);


        protected:
         int health = 200;
         int maxHealth = 200;

         int money;

    };
}



#endif // STATUS_HPP_INCLUDED
