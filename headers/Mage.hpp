#pragma once
#include "Character.hpp"

namespace sas
{

    class Mage : public Character
    {
    private:
        size_t mana = 0;
    public:
        
        Mage(size_t nHp, size_t nSpeed, const Weapon& nWeapon, const raylib::Vector2& nPosition, raylib::Texture2D& nSpri);
        Mage(size_t nHp, size_t nSpeed, const raylib::Vector2 &nPosition, raylib::Texture2D& nSprite);


        void equipWeapon(const Weapon &newWeap) noexcept override;    
        void useSkill() noexcept override;

        ~Mage() = default;
    };
 
} // namespace sas
