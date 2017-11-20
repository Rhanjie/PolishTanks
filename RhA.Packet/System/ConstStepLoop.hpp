#ifndef CONSTSTEPLOOP_HPP_INCLUDED
#define CONSTSTEPLOOP_HPP_INCLUDED

#include "LibrariesIncluding.hpp"

namespace RhA{
    class CConstLoop{
        public:
         void setFps(float fps);

         bool isGoodTime();

        private:
         sf::Clock clock;
         sf::Time time, timeOfUpdating=sf::Time::Zero;

         sf::Time constStep; //FPS
    };
}

#endif // CONSTSTEPLOOP_HPP_INCLUDED
