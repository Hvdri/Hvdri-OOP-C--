//
// Created by horia on 13/12/2022.
//

#ifndef TEMA2_HAINE_H
#define TEMA2_HAINE_H

#include <string>
#include <iostream>
#include <vector>



#endif //TEMA2_HAINE_H


class Haine {
protected:
    std::string culoare;
    std::string marime;
    std::string pret;
    static std::vector<Haine*> haine;

public:
    Haine();
    ~Haine();

    Haine(const std::string &culoare, const std::string &marime, const std::string &pret);


    void set_culoare(std::string culoare);
    void set_marime(std::string marime);
    void set_pret(std::string pret);

    std::string get_culoare() const;
    std::string get_marime() const;
    std::string get_pret () const;

    virtual void review() = 0;

    void print();

    static void add_haine(Haine *h);

    friend std::ostream &operator<<(std::ostream &os, const Haine &haine);
    friend std::istream &operator>>(std::istream &is, Haine &haine);

};
