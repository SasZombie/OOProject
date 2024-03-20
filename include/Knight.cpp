#include "../headers/Knight.hpp"

static constexpr size_t bonusHealth = 100;
static constexpr size_t bonusDamage = 10;

sas::Knight::Knight(size_t nHp, size_t nSpeed, const Weapon& nWeapon, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite)
    : Character(nHp + bonusHealth, nSpeed, nPosition, nSprite)
{
    this->equipWeapon(nWeapon);
    this->hp = maxHP;
}


sas::Knight::Knight(size_t nHp, size_t nSpeed, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite)
    : Character(nHp + bonusHealth, nSpeed, nPosition, nSprite)
{
    this->hp = maxHP;
}

void sas::Knight::equipWeapon(const Weapon &newWeap) noexcept
{
    this->equipedWeapon = newWeap;


    if(this->equipedWeapon.getType() == WeaponType::Melee)
    {
        this->equipedWeapon.addDamage(bonusDamage);
        this->maxHP = this->maxHP + bonusHealth;
    }
    addWeapon(newWeap);
}

void sas::Knight::useSkill() noexcept
{
    if(this->hp < this->maxHP)
        this->hp = this->hp + bonusHealth;

    if(this->hp > this->maxHP)
        this->hp = maxHP;
}
