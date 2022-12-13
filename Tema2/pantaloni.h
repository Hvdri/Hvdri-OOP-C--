#ifndef TEMA2_PANTALONI_H
#define TEMA2_PANTALONI_H

#include "haine.h"

class pantaloni : public Haine {

    std::string lungime;
public:
    pantaloni();
    ~pantaloni();

    void set_lungime(std::string lungime);

    std::string get_lungime() const;

    void print();


};


#endif //TEMA2_PANTALONI_H
