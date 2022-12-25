#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// Clasa baza pentru haine
class Haina {
public:
    Haina(std::string marime, std::string culoare, std::string material, float pret)
            : marime_(marime), culoare_(culoare), material_(material), pret_(pret) {}

    virtual std::string tipHaina() const = 0; // functie virtuala pura

    std::string marime() const { return marime_; }
    std::string culoare() const { return culoare_; }
    std::string material() const { return material_; }
    float pret() const { return pret_; }

    // Suprascriem cc/op= pentru a permite atribuirea unei haine existente unei alte haine
    Haina& operator=(const Haina& altaHaina) {
        if (this != &altaHaina) {
            marime_ = altaHaina.marime_;
            culoare_ = altaHaina.culoare_;
            material_ = altaHaina.material_;
            pret_ = altaHaina.pret_;
        }
        return *this;
    }

    // Rescriem operatorul << pentru a permite afisarea unei haine in stream
    friend std::ostream& operator<<(std::ostream& stream, const Haina& haina) {
        stream << haina.tipHaina() << " de marime " << haina.marime()
               << ", culoare " << haina.culoare() << " si material " << haina.material()
               << " (pret " << haina.pret() << " lei)";
        return stream;
    }

private:
    std::string marime_;
    std::string culoare_;
    std::string material_;
    float pret_;
};

// Clase derivate pentru fiecare tip de haina
class Camasa : public Haina {
public:
    using Haina::Haina; // mostenim constructorul din clasa baza

    std::string tipHaina() const override { return "camasa"; }
};

class Pantaloni : public Haina {
public:
    using Haina::Haina; // mostenim constructorul din clasa baza

    std::string tipHaina() const override { return "pantaloni"; }
};

class Rochie : public Haina {
public:
    using Haina::Haina; // mostenim constructorul din clasa baza

    std::string tipHaina() const override { return "rochie"; }
};

// Clasa de exceptii personalizate
class ExceptieHainaIndisponibila : public std::exception {
public:
    const char* what() const noexcept override {
        return "Haina nu este disponibila in stoc.";
    }
};

class ExceptieFonduriInsuficiente : public std::exception {
public:
    const char* what() const noexcept override {
        return "Fonduri insuficiente pentru a plati hainele din cos.";
    }
};

// Clasa Magazin
class Magazin {
public:
    // Adauga o haina in magazin
    void adaugaHaina(std::unique_ptr<Haina> haina) {
        haine_.push_back(std::move(haina));
    }

    // Afiseaza toate hainele din magazin
    void afiseazaHaine() const {
        std::cout << "Haine disponibile in magazin:\n";
        for (const auto &haina: haine_) {
            std::cout << " - " << haina->tipHaina()
                      << " de marime " << haina->marime()
                      << ", culoare " << haina->culoare()
                      << " si material " << haina->material()
                      << ", pret " << haina->pret()
                      << " lei\n";
        }
    }

    // Adauga o haina in cosul de cumparaturi
    const std::vector<std::unique_ptr<Haina>>& haine() const { return haine_; }

private:
    std::vector<std::unique_ptr<Haina>> haine_;
};

// Functie care afiseaza meniul principal
void afiseazaMeniu() {
    std::cout << "\n1. Afiseaza hainele disponibile\n";
    std::cout << "2. Adauga haina in cos\n";
    std::cout << "3. Afiseaza cosul de cumparaturi\n";
    std::cout << "4. Finalizeaza tranzactia\n";
    std::cout << "5. Iesire\n";
}

int main() {
    Magazin magazin;

    // Adaugam cateva haine in magazin
    magazin.adaugaHaina(std::make_unique<Camasa>("S", "rosu", "bumbac", 49.99f));
    magazin.adaugaHaina(std::make_unique<Camasa>("M", "albastru", "piele", 49.99f));
    magazin.adaugaHaina(std::make_unique<Camasa>("L", "alb", "matase", 49.99f));

    magazin.adaugaHaina(std::make_unique<Pantaloni>("L", "negru", "bumbac", 199.99f));
    magazin.adaugaHaina(std::make_unique<Pantaloni>("M", "negru", "piele", 199.99f));
    magazin.adaugaHaina(std::make_unique<Pantaloni>("L", "negru", "piele", 199.99f));

    magazin.adaugaHaina(std::make_unique<Rochie>("S", "rosu", "bumbac", 99.99f));
    magazin.adaugaHaina(std::make_unique<Rochie>("S", "alb", "matase", 99.99f));
    magazin.adaugaHaina(std::make_unique<Rochie>("M", "negru", "matase", 99.99f));

    // Cosul de cumparaturi al clientului
    std::vector<Haina*> cos;
    float sumaTotala = 0.0f;

    bool iesire = false;
    while (!iesire) {
        afiseazaMeniu();

        int optiune;
        std::cout << "Introduceti optiunea dorita:\n";
        std::cin >> optiune;

        switch (optiune) {

            case 1: {
                // Afisam hainele disponibile in magazin
                magazin.afiseazaHaine();
                break;
            }
            case 2: {
                // Adaugam haina in cos
                std::cout << "Introduceti marimea hainei:\n";
                std::string marime;
                std::cin >> marime;

                std::cout << "Introduceti culoarea hainei:\n";
                std::string culoare;
                std::cin >> culoare;

                std::cout << "Introduceti materialul hainei:\n";
                std::string material;
                std::cin >> material;

                bool hainaGasita = false;
                for (const auto& haina : magazin.haine()) {
                    if (haina->marime() == marime && haina->culoare() == culoare && haina->material() == material) {
                        cos.push_back(haina.get());
                        hainaGasita = true;
                        sumaTotala += haina->pret();
                        break;
                    }
                }

                if (!hainaGasita) {
                    throw ExceptieHainaIndisponibila();
                }

                break;
            }

            case 3: {
                // Afisam cosul de cumparaturi
                std::cout << "Cosul de cumparaturi:\n";
                for (const auto& haina : cos) {
                    std::cout << " - " << haina->tipHaina() << " de marime " << haina->marime()
                              << ", culoare " << haina->culoare() << " si material " << haina->material()
                              << " (pret " << haina->pret() << " lei)\n";
                }
                std::cout << "Suma totala: " << sumaTotala << " lei\n";
                break;
            }

            case 4: {
                // Finalizam tranzactia
                std::cout << "Introduceti suma disponibila: ";
                float sumaDisponibila;
                std::cin >> sumaDisponibila;

                if (sumaDisponibila < sumaTotala) {
                    throw ExceptieFonduriInsuficiente();
                }

                // Golim cosul de cumparaturi
                cos.clear();
                sumaTotala = 0.0f;
                std::cout << "Tranzactia a fost finalizata cu succes.\n";
                break;
            }

            case 5: {
                iesire = true;
                break;
            }

            default: {
                std::cout << "Optiune invalida.\n";
                break;
            }
        }
    }

    return 0;
}