#pragma once
#include "Character.hpp"

namespace sas
{

    class Pugilist : public Character
    {
    private:
        
    public:
        
        Pugilist(size_t nHp, size_t nSpeed, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite);
        Pugilist(size_t nHp, size_t nSpeed, const Weapon& nWeapon, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite);


        void equipWeapon(const Weapon &newWeap) noexcept override;
        void useSkill() noexcept override;

        ~Pugilist() = default;
    };
 
} // namespace sas
