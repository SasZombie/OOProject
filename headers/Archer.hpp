#pragma once
#include "Character.hpp"

namespace sas
{

    class Archer : public Character
    {
    private:
        
    public:
        
        Archer(size_t nHp, size_t nSpeed, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite);
        Archer(size_t nHp, size_t nSpeed, const Weapon& nWeapon, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite);


        void equipWeapon(const Weapon &newWeap) noexcept override;
        void useSkill() noexcept override;

        ~Archer() = default;
    };
 
} // namespace sas
