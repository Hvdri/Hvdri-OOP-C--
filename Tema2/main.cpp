#include <bits/stdc++.h>
#include "Menu.h"

int main()
{
    try {
        Menu::print();
        try{
            Menu::run();
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


    return 0;
}