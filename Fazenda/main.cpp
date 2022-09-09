#include <iostream>

#include "Farm.hpp"

int main()
{
    srand(time(NULL));

    Farm farm ("city", "state", "Cornvile", 50);

    for (int i = 0; i < 50; i++)
    {
    farm.Add_toFarmRDM (Type_Animal (rand() % 4));
    }
 
    farm.feed(1);
    
    farm.print();
    farm.print_archive();

    return 0;
}
