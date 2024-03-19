#include "../headers/Mage.hpp"

static constexpr size_t bonusRange = 20;
static constexpr size_t bonusHealth = 50;

sas::Mage::Mage(size_t nHp, size_t nSpeed, const Weapon& nWeapon, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite)
    : Character(nHp, nSpeed, nPosition, nSprite)
{
    this->equipWeapon(nWeapon);   
    this->hp = maxHP; 
}


sas::Mage::Mage(size_t nHp, size_t nSpeed, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite)
    : Character(nHp, nSpeed, nPosition, nSprite)
{
    this->hp = maxHP;
}

void sas::Mage::equipWeapon(const Weapon &newWeap) noexcept
{
    this->equipedWeapon = newWeap;
    if(this->equipedWeapon.getType() == WeaponType::Magic)
    {
        this->equipedWeapon.addRange(bonusRange);
        this->maxHP = this->maxHP + bonusHealth;
    }
}

void sas::Mage::useSkill() noexcept
{
   this->equipedWeapon.addRange(bonusRange); 
}

