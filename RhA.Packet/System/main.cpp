#include "GameManager.hpp"

int main(){
    srand(time_t(NULL));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    RhA::CGameManager game("Polish Tanks by RhAnjiE", sf::Vector2i(1024, 768), settings);

    game.run();
    return 0;
}
