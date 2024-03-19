#pragma once
#include <functional>
#include "/home/saszombie/raylib-cpp/include/raylib-cpp.hpp"


namespace sas
{
 class Animation
 {
    private:
        bool isFinished = false;
        float currentStep = 0;
        float smoothness; //Lower number = smoother 
        raylib::Vector2 startPos, endPos; // TODO: Add support for multi images animations: std::vector<IMGS> 

        std::function<bool(raylib::Vector2& position, const raylib::Vector2& endPos, float smoothness, float step)> drawFunction;

    public:
        Animation() = default;
        Animation(float nSmoothness, raylib::Vector2 nStartPos, raylib::Vector2 nEndPos);
        void addCustomAnimation(std::function<bool(raylib::Vector2& position, const raylib::Vector2& endPos, float smoothness, float step)> func);

        void setParam(const raylib::Vector2 &start, const raylib::Vector2& end, float nSmoothness);
        void draw() noexcept;
        void print() const noexcept;

        bool getFinishStatus() const noexcept; 


        ~Animation() = default;
 };
 
} // namespace sas

