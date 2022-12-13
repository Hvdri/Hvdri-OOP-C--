#include "haine.h"



Haine::Haine() {
    this->culoare = " ";
    this->marime = " ";
    this->pret = " ";
}

Haine::~Haine() {
    this->culoare = " ";
    this->marime = " ";
    this->pret = " ";
}

void Haine::set_culoare(std::string culoare) {
    this->culoare = culoare;
}

void Haine::set_marime(std::string marime) {
    this->marime = marime;
}

void Haine::set_pret(std::string pret) {
    this->pret = pret;
}

std::string Haine::get_culoare() const {
    return culoare;
}

std::string Haine::get_marime() const {
    return marime;
}

std::string Haine::get_pret() const {
    return pret;
}

void Haine::add_haine(Haine *h) {
    Haine::haine.push_back(h);
}

//virtual
void Haine::review() {
    std::cout << "culoare: " << this->get_culoare() << std::endl;
    std::cout << "marime: " << this->get_marime() << std::endl;
    std::cout << "pret: " << this->get_pret() << std::endl;
}

void Haine::print() {
    std::cout << "culoare: " << this->get_culoare() << std::endl;
    std::cout << "marime: " << this->get_marime() << std::endl;
    std::cout << "pret: " << this->get_pret() << std::endl;
}



//Haine &Haine::operator=(const Haine &h) {
//    this->culoare = h.culoare;
//    this->marime = h.marime;
//    this->pret = h.pret;
//    return *this;
//}



//friend function

std::ostream &operator<<(std::ostream &os, const Haine &h)  {
    os << "culoare: " << h.culoare << std::endl;
    os << "marime: " << h.marime << std::endl;
    os << "pret: " << h.pret << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Haine &h) {
    is >> h.culoare;
    is >> h.marime;
    is >> h.pret;
    return is;
}







