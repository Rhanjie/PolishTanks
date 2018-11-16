#include "GameManager.hpp"

/**
 * @Title: Polish Tanks
 * @Version: v0.2
 * @Author: Marcin (RhAnjiE) Dyla
 */

int main(){
    srand(time_t(NULL));

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    //...

    RhA::CGameManager game("Polish Tanks v0.2", sf::Vector2i(1024, 768), settings);

    game.run();
    return 0;
}
