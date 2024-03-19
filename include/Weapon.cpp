#include "../headers/Weapon.hpp"

void sas::Weapon::addDamage(size_t dmgToAdd) noexcept
{
    this->damage = this->damage + dmgToAdd;
}

void sas::Weapon::addRange(size_t rangeToAdd) noexcept
{
    this->range = this->range + rangeToAdd;
}

sas::WeaponType sas::Weapon::getType() const noexcept
{
    return this->type;
}
size_t sas::Weapon::getDamage() const noexcept
{
    return this->damage;
}

size_t sas::Weapon::getRange() const noexcept
{
    return this->range;
}