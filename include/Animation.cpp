#include "../headers/Animation.hpp"
#include <iostream>



sas::Animation::Animation(float nSmoothness, raylib::Vector2 nStartPos, raylib::Vector2 nEndPos)
    : smoothness(nSmoothness), startPos(nStartPos), endPos(nEndPos)
{
}

void sas::Animation::addCustomAnimation(std::function<bool(raylib::Vector2 &position, const raylib::Vector2 &endPos, float smoothness, float step)> func)
{
    this->drawFunction = func;
}
void sas::Animation::setParam(const raylib::Vector2 &start, const raylib::Vector2 &end, float nSmoothness)
{
    this->startPos = start;
    this->endPos = end;
    this->smoothness = nSmoothness;
}
void sas::Animation::draw() noexcept
{
    if(!this->isFinished)
    {
        this->isFinished = drawFunction(startPos, endPos, smoothness, currentStep); 
    }
}

void sas::Animation::print() const noexcept
{
    std::cout << "Smoothness = " << this->smoothness << " StartPos = " << this->startPos.x << ' ' << this->startPos.y << " End Pos = " << this->endPos.x << ' ' << this->endPos.y << " Step = " << this->currentStep << '\n'; 
}
bool sas::Animation::getFinishStatus() const noexcept
{
    return this->isFinished;
}