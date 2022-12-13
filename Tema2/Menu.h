#ifndef TEMA2_MENU_H
#define TEMA2_MENU_H

#include <iostream>

#include "haine.h"

class Menu {
    static int option;


    //use shared_ptr
    static std::vector<Haine*> haine;
    //    static std::vector<std::shared_ptr<Haine>> haine_ptr;




public:
    Menu();
    ~Menu();

    static void print();
    static void run();

    static void add_haine(Haine *h);
    static void print_haine();

    static void add_pantaloni();
    static void add_incaltaminte();
    static void print_pantaloni();
    static void print_incaltaminte();

    static void delete_haine();
    static void delete_pantaloni();
    static void delete_incaltaminte();

    static void update_haine();
    static void update_pantaloni();
    static void update_incaltaminte();

    static void search_haine();
    static void search_pantaloni();
    static void search_incaltaminte();


};

#endif //TEMA2_MENU_H
