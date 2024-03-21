#include <iostream>
#include <cstdio>
using namespace std;

class Weapon
{
    public:
        Weapon(): nom(""), degats(0){}

        Weapon(string n, float d)
        {
            nom = n;
            degats = d;
        }
    
    private:
        string nom;
        float degats;

    public:
        string GetName()
        {
            return nom;
        }

        float GetDamage()
        {
            return degats;
        }
};

class RPCharacter
{

    public:
        RPCharacter(string name) : level(3), xp(0), hp(100), weaponCount(0), currentWeapon(0), is_dead(false)
        {
            nom = name;
        }

        void apply_damage(int damage)
        {
            hp -= damage;
            
            if(hp <= 0)
            {
                if(hp < 0)
                    hp = 0;

                is_dead = true;
            }
        }

        Weapon get_weapon()
        {
            if(weaponCount == 0)
            {
                float damage = level / 2;
                if(damage < 1)
                    damage = 1;
                
                return Weapon("disarmed", damage);
            }
            return weapons[currentWeapon];
        }

        Weapon get_weapon(int index)
        {
            if(index >= weaponCount)
            {
                if(weaponCount > 0)
                    return weapons[weaponCount - 1];
                else
                    return Weapon("disarmed", level / 2);
            }
            
            return weapons[index];
        }

        void attack(RPCharacter target)
        {
            target.apply_damage(get_weapon().GetDamage());
            xp += get_weapon().GetDamage();
        }

        void store_weapon(Weapon weapon)
        {
            if(weaponCount < 10)
            {
                weapons[weaponCount] = weapon;
                weaponCount++;
            }
            else
            {
                weapons[9] = weapon;
            }
        }

        void switch_weapon(int index)
        {
            if(index > 9)
                index = 9;
            else if(index < 0)
                index = 0;

            if(index >= weaponCount)
            {
                currentWeapon = weaponCount - 1;
            }
            
            else
            {
                currentWeapon = index;
            }
        }

        void drink_potion(int healpoints)
        {
            hp += healpoints;
        }

    string nom;
    int level;
    int xp;
    float hp;
    Weapon weapons[10];
    int weaponCount;
    int currentWeapon;
    bool is_dead;

};

int main()
{
    RPCharacter player1("Samurai");
    RPCharacter player2("Knight");

    Weapon katana("Katana", 50);
    Weapon excalibur("Excalibur", 40);

    player1.store_weapon(katana);
    player2.store_weapon(excalibur);

    player1.attack(player2);
    player2.attack(player1);
    player1.attack(player2);
}