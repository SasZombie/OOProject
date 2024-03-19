#pragma once
#include <string>
#include "/home/saszombie/raylib-cpp/include/raylib-cpp.hpp"

namespace sas
{
    enum class WeaponType {
        Ranged,
        Melee,
        Magic
    };

    template<typename T>
    concept CharArrayOrString = std::is_same_v<T, char[]> ||
                                std::is_same_v<T, char*> ||
                                std::convertible_to<T, std::string> ||
                                std::is_same_v<T, std::string>;


    class Weapon
    {
    private:
        WeaponType type;
        size_t damage;
        size_t range;
        std::string name;
        raylib::Image sprite;

    public:
        
        Weapon() = default;

        template<typename T>
        requires CharArrayOrString<T>
        Weapon(WeaponType nType, size_t nDamage, size_t nRage, const T& nName, const raylib::Image& nSprite)
            : type(nType), damage(nDamage), range(nRage), name(nName), sprite(nSprite)
        {
        }
        void addDamage(size_t dmgToAdd) noexcept;
        void addRange(size_t rangeToAdd) noexcept;
        
        WeaponType getType() const noexcept;

        size_t getRange() const noexcept;
        size_t getDamage() const noexcept;
        
        
        ~Weapon() = default;

    };


}