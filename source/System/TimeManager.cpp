#include "TimeManager.hpp"

RhA::CTimeManager::CTimeManager(){
    font.loadFromFile("media/main.ttf");

    ///TODO: Font Manager
    text.setFont(font);
    text.setCharacterSize(20);
}

void RhA::CTimeManager::update(sf::Vector2u windowSize){
    if(fpsClock.getElapsedTime().asSeconds() >= 1.0f){
        fps = frame; frame = 0;
        fpsClock.restart();

        text.setPosition(1, windowSize.y - 50);
        text.setString(RhA::toString(fps) + "\n" + RhA::toString(dt)); //rip std::to_string
    }

    frame++;
}

void RhA::CTimeManager::restart(){
    dt = (deltaClock.restart()).asSeconds();

    //std::cout << "[FPS] " << (int) 1000000.0f / dt.asMicroseconds() << std::endl; //alternative fps counter
}

void RhA::CTimeManager::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(text);
}
