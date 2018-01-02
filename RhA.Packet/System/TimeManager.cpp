#include "TimeManager.hpp"

RhA::CTimeManager::CTimeManager(){
    font.loadFromFile("media/main.ttf");

    text.setFont(font); //TODO: RhA::CLoaderResources::get().getFont(fontID);
    text.setCharacterSize(24);
}

void RhA::CTimeManager::update(){
    if(fpsClock.getElapsedTime().asSeconds() >= 1.0f){
        fps = frame; frame = 0;
        fpsClock.restart();

        text.setString("FPS: " + std::to_string(fps) + "\nDelta time: " + std::to_string(dt));
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


