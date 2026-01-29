#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap kuro("Kuro");

    kuro.attack("Shiro");
    kuro.takeDamage(1);
    kuro.beRepaired(1);
    kuro.beRepaired(1);
    for (int i = 0; i < 10; i++)
        kuro.attack("Shiro");
    for (int i = 0; i < 11; i++)
        kuro.takeDamage(1);
}
