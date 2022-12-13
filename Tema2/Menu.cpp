#include "Menu.h"

int Menu::option = 0;

Menu::Menu() {
    this->option = 0;
}

Menu::~Menu() {
    this->option = 0;
}



std::vector<Haine*> Menu::haine;

void Menu::print(){

    std::cout << "Tema 2 - POO - Marinescu Horia-Andrei\n"
              << "Magazin de Haine\n"
              << "Primul Magazin contine doar bluze si pantaloni\n"
              << "Al doilea Magazin contine si bijuterii\n"
              << "Al treilea Magazin contine si incaltaminte\n";
}

void Menu::run(){

    //Trebuie sa fac un meniu care sa imi permita sa adaug produse in cosul de cumparaturi
    //Trebuie sa imi permita sa afisez cosul de cumparaturi si sa il golesc si pretul total

  char option;

  do{
        std::cout << "Ce doriti sa cumparati?\n"
                  << "1.) Haine\n"
                  << "2.) Pantaloni\n"
                  << "3.) Incaltaminte\n"
                  << "4.) Vezi cosul de cumparaturi\n"
                  << "5.) Iesire\n";

        std::cin >> option;
        switch(option) {
            case '1':{
                // adaug haine in cos
                std::string culoare, marime, pret;
                std::cout << "Culoare: ";
                std::cin >> culoare;
                std::cout << "Marime: ";
                std::cin >> marime;
                std::cout << "Pret: ";
                std::cin >> pret;

//                Haine *h = new Haine(culoare, marime, pret);
//                Menu::add_haine(h);


                break;
            }
            case '2': {
                //adauga pantaloni in cos
                std::string culoare, marime, pret;
                std::cout << "Culoare: ";
                std::cin >> culoare;
                std::cout << "Marime: ";
                std::cin >> marime;


                break;
            }
            case '3':
                //adauga incaltaminte in cos
                break;

            case '4':
                //afiseaza cosul de cumparaturi
                break;

            case '5':
                //iesire
                break;


        }
        if (option != '1' && option != '2' && option != '3' && option != '4' && option != '5')
            std::cout << "Optiune invalida. Incercati din nou!\n";

  }while(option != '5');

  }
