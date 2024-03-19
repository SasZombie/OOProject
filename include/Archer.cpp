#include "../headers/Archer.hpp"

#include <iostream>
static constexpr size_t bonusRange = 10;
static constexpr size_t bonusDamage = 10;

sas::Archer::Archer(size_t nHp, size_t nSpeed, const Weapon& nWeapon, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite)
    : Character(nHp, nSpeed, nPosition, nSprite)
{
    this->equipWeapon(nWeapon);
    this->hp = maxHP;

   
}


sas::Archer::Archer(size_t nHp, size_t nSpeed, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite)
    : Character(nHp, nSpeed, nPosition, nSprite)
{
    this->hp = maxHP;
}

void sas::Archer::equipWeapon(const Weapon &newWeap) noexcept
{
    this->equipedWeapon = newWeap;

    this->equipedWeapon.addDamage(bonusDamage);

    if(equipedWeapon.getType() == WeaponType::Ranged)
    {
        equipedWeapon.addDamage(bonusDamage);
        equipedWeapon.addRange(bonusRange);
    }
}

void sas::Archer::useSkill() noexcept
{
    this->equipedWeapon.addDamage(bonusDamage);
}
