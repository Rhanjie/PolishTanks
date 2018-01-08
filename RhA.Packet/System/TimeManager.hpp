#ifndef CONSTSTEPLOOP_HPP_INCLUDED
#define CONSTSTEPLOOP_HPP_INCLUDED

#include "LibrariesIncluding.hpp"

namespace RhA{
    class CTimeManager: public sf::Drawable{
        public:
         CTimeManager();

         void update(sf::Vector2u windowSize);
         void restart();

         inline float getDeltaTime(){return dt;}

        private:
         virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

         sf::Clock deltaClock, fpsClock;
         unsigned int frame = 0, fps = 0;
         float dt = 0;

         sf::Font font;
         sf::Text text;
    };
}

#endif // CONSTSTEPLOOP_HPP_INCLUDED
