#ifndef GAMEMANAGER_HPP_INCLUDED
#define GAMEMANAGER_HPP_INCLUDED

#include "LibrariesIncluding.hpp"
 #include "TimeManager.hpp"
 #include "LoaderTextures.hpp"
 #include "../Character/Person.hpp"
 #include "../Character/Player.hpp"
 #include "../Terrain/Terrain.hpp"
 #include "../Effects/Particles/ParticleEmitter.hpp"
 #include "../Effects/Particles/ParticlesManager.hpp"
 #include "../Effects/Particles/FogEmitter.hpp"
 #include "../Interface/HUD.hpp"


namespace RhA{
    class CGameManager{
        enum eGameplayType{MENU, GAME, CLOSE};

        public:
         CGameManager(std::string title, sf::Vector2i windowSize, sf::ContextSettings& settings);

         eGameplayType gameplayType;

         void run();
        private:
         sf::RenderWindow window;
         sf::Event event;
         sf::View camera;

         RhA::CTimeManager timeManager;

         void bodyMenu();
         void bodyGameplay();
    };

}

#endif // GAMEMANAGER_HPP_INCLUDED
