#ifndef STATUS_HPP_INCLUDED
#define STATUS_HPP_INCLUDED

#include "../System/LibrariesIncluding.hpp"

namespace RhA{
    enum eStats{HEALTH, MAXHEALTH, MONEY};

    class CPerson{
        public:
         void setStatus(eStats statsType, int value);
         int getStatus(eStats statsType);

         virtual inline sf::Vector2f getPosition() = 0;
         virtual inline sf::FloatRect getCollisionBox() = 0;

        protected:
         int health = 200;
         int maxHealth = 200;

         int money = 0;
    };
}

#endif // STATUS_HPP_INCLUDED
