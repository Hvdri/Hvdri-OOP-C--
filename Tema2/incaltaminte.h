#ifndef TEMA2_INCALTAMINTE_H
#define TEMA2_INCALTAMINTE_H

#include "haine.h"

class incaltaminte : public Haine {
    std::string tip;
    std::string talpa;

public:
    incaltaminte();
    ~incaltaminte();

    void set_tip(std::string tip);
    void set_talpa(std::string talpa);

    std::string get_tip() const;
    std::string get_talpa() const;



    void print();
};


#endif //TEMA2_INCALTAMINTE_H
