#include "ConstStepLoop.hpp"

void RhA::CConstLoop::setFps(float fps){
    constStep=sf::seconds(1.0f/fps);
}

bool RhA::CConstLoop::isGoodTime(){
    bool isGood;

    time=clock.restart();
    timeOfUpdating+=time;

    if(isGood=(timeOfUpdating>constStep))
     timeOfUpdating-=constStep;

    return isGood;
}
