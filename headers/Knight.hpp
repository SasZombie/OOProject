#pragma once
#include "Character.hpp"

namespace sas
{

    class Knight : public Character
    {
    private:
        
    public:
        
        Knight(size_t nHp, size_t nSpeed, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite);
        Knight(size_t nHp, size_t nSpeed, const Weapon& nWeapon, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite);


        void equipWeapon(const Weapon &newWeap) noexcept override;
        void useSkill() noexcept override;

        ~Knight() = default;
    };
 
} // namespace sas

