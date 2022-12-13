#include "incaltaminte.h"

incaltaminte::incaltaminte() {
    this->tip = " ";
    this->talpa = " ";
}

incaltaminte::~incaltaminte() {
    this->tip = " ";
    this->talpa = " ";
}

void incaltaminte::set_tip(std::string tip) {
    this->tip = tip;
}

void incaltaminte::set_talpa(std::string talpa) {
    this->talpa = talpa;
}

std::string incaltaminte::get_tip() const {
    return tip;
}

std::string incaltaminte::get_talpa() const {
    return talpa;
}

void incaltaminte::print() {
    std::cout << "culoare: " << this->get_culoare() << std::endl;
    std::cout << "marime: " << this->get_marime() << std::endl;
    std::cout << "pret: " << this->get_pret() << std::endl;
    std::cout << "tip: " << this->get_tip() << std::endl;
    std::cout << "talpa: " << this->get_talpa() << std::endl;
}





