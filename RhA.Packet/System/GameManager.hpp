#ifndef GAMEMANAGER_HPP_INCLUDED
#define GAMEMANAGER_HPP_INCLUDED

#include "LibrariesIncluding.hpp"
 #include "ConstStepLoop.hpp"
 #include "LoaderTextures.hpp"
 #include "Character/Status.hpp"
 #include "Character/Player.hpp"
 #include "Terrain/Terrain.hpp"


namespace RhA{
    class CGameManager{
        enum eGameplayType{MENU, GAME, END};

        public:
         CGameManager(std::string title, sf::Vector2i windowSize, sf::ContextSettings& settings);

         eGameplayType gameplayType;

         void run();
        private:
         sf::RenderWindow window;
         sf::Event event;
         sf::View camera;

         RhA::CConstLoop constLoop;

         void bodyMenu();
         void bodyGameplay();
    };

}

#endif // GAMEMANAGER_HPP_INCLUDED
