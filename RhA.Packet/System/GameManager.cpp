#include "GameManager.hpp"

 #define FPS 60

RhA::CGameManager::CGameManager(std::string title, sf::Vector2i windowSize, sf::ContextSettings& settings){
    std::cout << "[O] Initialization...\n";

    window.create(sf::VideoMode(windowSize.x, windowSize.y), title, sf::Style::Titlebar, settings);
    //window.setFramerateLimit(60);

    camera.setSize((sf::Vector2f) window.getSize());

    std::cout << "\n[O] Loading resources...\n";
    if(!RhA::CLoaderResources::get().isLoaded()){
        std::cout << "[!] Resources can't be loaded!\n";

        gameplayType = CLOSE; return;
    } else std::cout << "[O] Loaded without errors!\n\n";

    std::cout << "[O] Game created.\n";

    gameplayType = MENU;
}


void RhA::CGameManager::run(){
    while(window.isOpen()){
        switch(gameplayType){
            case MENU:
             bodyMenu(); break;

            case GAME:
             bodyGameplay(); break;

            default:
             window.close(); return;
        }
    }
}
