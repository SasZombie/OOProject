#pragma once
#include <optional>

#include "Weapon.hpp"
#include "Animation.hpp"

namespace sas
{

   class Character
   {
    protected:
        
        bool hasAnimation = false;
        int maxHP = 100;
        
        int hp;
        size_t speed;
        Weapon equipedWeapon;
        std::array<Weapon, 3> inventory;
    private:
        raylib::Vector2 position;
        raylib::Texture2D& sprite;
        short currentWeapon = 0;
    protected:

        Animation animation;
        
        void addWeapon(const Weapon& newWeap) noexcept;
        virtual void move(float deltaT, const Vector2 &newPos) noexcept;

    public:
        Character(size_t nHp, size_t nSpeed, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite);
        Character(size_t nHp, size_t nSpeed, const Weapon& nWeapon, const raylib::Vector2& nPosition, raylib::Texture2D& nSprite);

        void changeWeapon() noexcept;
        void moveLeft(float deltaT) noexcept;
        void moveRight(float deltaT) noexcept;
        void takeDamage(size_t damage) noexcept;
        void addAnimation(const Animation& newAnimation) noexcept;
        std::optional<Animation> attack(Character &enemy) noexcept;
        
        size_t getSpeed() const noexcept;
        size_t getDamage() const noexcept;
        int getHealth() const noexcept;
        size_t getMaxHealth() const noexcept;

        const raylib::Vector2& getPosition() noexcept;
        const raylib::Texture2D& getSprite() const noexcept;



        // virtual void loadAnimation(const Animation& newAnimation);
        virtual void equipWeapon(const Weapon& newWeapon) noexcept = 0;
        virtual void useSkill() noexcept = 0;
        virtual ~Character() = default;
   };
   
   
} // namespace sas
