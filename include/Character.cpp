#include "../headers/Character.hpp"

sas::Character::Character(size_t nHp, size_t nSpeed, const Weapon& nWeapon, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite)
    : hp(nHp), speed(nSpeed), equipedWeapon(nWeapon), position(nPosition), sprite(nSprite)
{
}


sas::Character::Character(size_t nHp, size_t nSpeed, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite)
    : hp(nHp), speed(nSpeed), position(nPosition), sprite(nSprite)
{
}

void sas::Character::move(float deltaT, const Vector2 &newPos) noexcept
{
    this->position = newPos;
    this->position.Scale(deltaT); 
    if(this->position.x < 0)
        this->position.x = 0;
    if(this->position.x > 1850)
        this->position.x = 1850; 
}
void sas::Character::addWeapon(const Weapon& newWeap) noexcept
{
    if(this->inventory.size() < 3)
    {
        this->inventory[this->inventory.size() - 1] = newWeap;
    }
    else
    {
        this->inventory[2] = this->inventory[1];
        this->inventory[1] = this->inventory[0];
        this->inventory[0] = newWeap;
    }
}


std::optional<sas::Animation> sas::Character::attack(Character &enemy) noexcept 
{
    float range = this->equipedWeapon.getRange();
    Vector2 pos = this->getPosition(), enemPos = enemy.getPosition();
    if (CheckCollisionPointCircle(pos, enemPos, range))
        enemy.takeDamage(this->getDamage());

    if(enemPos.x > pos.x)
        this->animation.setParam(pos, {pos.x + range, pos.y - range}, 10);
    else
        this->animation.setParam(pos, {pos.x - range, pos.y + range}, -10);

    if(hasAnimation)
        return this->animation;
    return std::nullopt;
}


void sas::Character::moveLeft(float deltaT) noexcept
{
    Vector2 newPos = this->position - Vector2{static_cast<float>(speed), 0.f};
    move(deltaT, newPos);         
}

void sas::Character::moveRight(float deltaT) noexcept
{
    Vector2 newPos = this->position + Vector2{static_cast<float>(speed), 0.f};
    move(deltaT, newPos);         
}

void sas::Character::takeDamage(size_t damage) noexcept
{
    this->hp = this->hp - damage;
}
void sas::Character::addAnimation(const Animation &newAnimation) noexcept
{
    this->hasAnimation = true;
    this->animation = newAnimation;
}
size_t sas::Character::getDamage() const noexcept
{
    return this->equipedWeapon.getDamage();
}

size_t sas::Character::getHealth() const noexcept
{
    return this->hp;
}

size_t sas::Character::getMaxHealth() const noexcept
{
    return this->maxHP;
}

size_t sas::Character::getSpeed() const noexcept
{
    return this->speed;
}

const raylib::Vector2 &sas::Character::getPosition() noexcept
{
    return this->position;
}

const raylib::Texture2D& sas::Character::getSprite() const noexcept
{
    return this->sprite;
}

