#include "pantaloni.h"

pantaloni::pantaloni() {
    this->lungime = " ";
}

pantaloni::~pantaloni() {
    this->lungime = " ";
}

void pantaloni::set_lungime(std::string lungime) {
    this->lungime = lungime;
}

std::string pantaloni::get_lungime() const {
    return lungime;
}

void pantaloni::print() {
    std::cout << "culoare: " << this->get_culoare() << std::endl;
    std::cout << "marime: " << this->get_marime() << std::endl;
    std::cout << "pret: " << this->get_pret() << std::endl;
    std::cout << "lungime: " << this->get_lungime() << std::endl;
}


