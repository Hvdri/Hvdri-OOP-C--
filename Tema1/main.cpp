#include <iostream>
#include <string>
#include <strings.h>
#include <bits/stdc++.h>

using namespace std;

class masina{

private:
    char *marca = nullptr;
    char *combustibil = nullptr;
    char *an = nullptr;

public:
    masina(){

        marca = new char[8];
        strcpy(marca, "Default");

        combustibil = new char[8];
        strcpy(combustibil, "Default");

        an = new char[8];
        strcpy(an, "Default");
    }

    masina(char *marca_, char *combustibil_, char *an_){

        marca = new char[strlen(marca_)];
        strcpy(marca, marca_);

        combustibil = new char[strlen(combustibil_)];
        strcpy(combustibil, combustibil_);

        an = new char[strlen(an_)];
        strcpy(an, an_);
    }

    masina(const masina &masinaObject){

        marca = new char[strlen(masinaObject.marca) + 1];
        strcpy(marca, masinaObject.marca);

        combustibil = new char[strlen(masinaObject.combustibil) + 1];
        strcpy(combustibil, masinaObject.combustibil);

        an = new char[strlen(masinaObject.an) + 1];
        strcpy(an, masinaObject.an);
    }

/////////////////////////////////AFISARE///////////////////////////////////

    void afisare() const{

        cout << marca << '\n' << combustibil << '\n' << an << '\n' << '\n';
    }

///////////////////////////////////GET/////////////////////////////////////

    char *getMarca() const {
        return marca;
    }

    char *getCombustibil() const {
        return combustibil;
    }

    char *getAn() const {
        return an;
    }

///////////////////////////////////SET/////////////////////////////////////

    void setMarca(char *marca_){

        delete[] marca;
        marca = new char[strlen(marca_) + 1];
        strcpy(marca, marca_);
    }

    void setCombustibil(char *combustibil_){

        delete[] combustibil;
        combustibil = new char[strlen(combustibil_) + 1];
        strcpy(combustibil, combustibil_);
    }

    void setAn(char *an_){

        delete[] an;
        an = new char[strlen(an_) + 1];
        strcpy(an, an_);
    }

///////////////////////////////OPERATORI///////////////////////////////////

    masina &operator+=(const masina &rhs){

        return *this;
    }

    masina &operator=(const masina &masinaAssign){

        delete[] marca;
        marca = new char[strlen(masinaAssign.marca) + 1];
        strcpy(marca, masinaAssign.marca);

        delete[] combustibil;
        combustibil = new char[strlen(masinaAssign.combustibil) + 1];
        strcpy(combustibil, masinaAssign.combustibil);

        delete[] an;
        an = new char[strlen(masinaAssign.an) + 1];
        strcpy(an, masinaAssign.an);

        return *this;
    }

    bool operator==(masina &b) const{

        if (strcmp(marca, b.marca) ==0 || strcmp(combustibil, b.combustibil) ==0 || strcmp(an, b.an) == 0)
            return true;
        return false;
    }

    bool operator!=(masina &b) const{

        if (!(strcmp(marca, b.marca) || strcmp(combustibil, b.combustibil) || an == b.an))
            return false;
        return true;
    }

    friend istream &operator>>(istream &is, masina &m){

        cout << "Introduceti datele masinii:\n\n";
        char tmp[500];
        cout << "Marca:";
        is >> tmp;
        delete[] m.marca;
        m.marca = new char[strlen(tmp) + 1];
        strcpy(m.marca, tmp);

        is.getline(tmp, 256, '\n'); //clear

        cout << "Combustibilul:";
        is.getline(tmp, 256, '\n');
        delete[] m.combustibil;
        m.combustibil = new char[strlen(tmp) + 1];
        strcpy(m.combustibil, tmp);

        cout << "Anul de fabricatie:";
        is.getline(tmp, 256, '\n');
        delete[] m.an;
        m.an = new char[strlen(tmp) + 1];
        strcpy(m.an, tmp);

        return is;
    }

    friend ostream &operator<<(ostream &os, const masina &m){

        os << "Marca: " << m.marca << '\n'
           << "Combustibil: " << m.combustibil << '\n'
           << "An de Fabricatie: "<< m.an << '\n' << '\n';

        return os;
    }

///////////////////////////////////////////////////////////////////////////

    ~masina(){

        delete[] marca;
        delete[] combustibil;
        delete[] an;
    }
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

    masina Bemve;

    string marca, combustibil, an;

    masina masini[30]; int n = 0;

    int valid = 1; int expression = 0;
    do {
        cout << "----------------------------\n";
        cout << "Optiuni:\n"
             << "1.) Afisati Toate Masinile:\n"
             << "2.) Adaugati o Masina\n"
             << "3.) Cautati o Masina in functie Marca/ An/ Combustibil\n"
             << "4.) Exit\n\n";

        cin >> expression;
        if (expression >= 1 && expression <= 4) {
            if(expression == 1) {
                for(int i = 0 ; i < n ; i++)
                    cout << "\n--Masina " << i+1 << ".): \n" << masini[i] << "\n";
            }
            if(expression == 2) {
                cin >> masini[n++];
                // masini[n++] += input;
            }
            if(expression == 3) {
                int valid2 = 1; int expression2 = 0;
                do {
                    cout << "----------------------------\n";
                    cout << "Dupa ce doriti sa cautati?\n";
                    cout << "1.) Marca \n"
                         << "2.) Combustibil \n"
                         << "3.) An \n"
                         << "4.) Exit (Meniu Anterior)\n\n";

                    cin >> expression2;
                    if (expression2 >= 1 && expression2 <= 4) {

                        int gasit = 0;
                        if (expression2 == 1) {
                            cout << "Inserati Marca: ";
                            char cautare[10]; cin >> cautare;

                            for(int i = 0 ; i < n ; i++){
                                if(strcmp(masini[i].getMarca(), cautare) == 0) {
                                    cout << "--Masina " << i + 1 << ".): \n" << masini[i] << "\n";
                                    gasit = 1;
                                }else
                                if(gasit == 0)
                                    cout << "Nu s-a gasit masina cautata. Incercati din nou!\n";
                            }
                        }

                        if (expression2 == 2){
                            cout << "Inserati Combustibilul: ";
                            char cautare[10]; cin >> cautare;

                            for(int i = 0 ; i < n ; i++){
                                if(strcmp(masini[i].getCombustibil(), cautare) == 0){
                                    cout << "--Masina " << i+1 << ".): \n" << masini[i] << "\n";
                                    gasit = 1;
                                }else
                                if(gasit == 0)
                                    cout << "Nu s-a gasit masina cautata. Incercati din nou!\n";
                            }
                        }
                        if (expression2 == 3){
                            cout << "Inserati Anul de Fabricatie: ";
                            char cautare[10]; cin >> cautare;

                            for(int i = 0 ; i < n ; i++){
                                if(strcmp(masini[i].getAn(), cautare) == 0){
                                    cout << "--Masina " << i+1 << ".): \n" << masini[i] << "\n";
                                    gasit = 1;
                                }else
                                if(gasit == 0)
                                    cout << "Nu s-a gasit masina cautata. Incercati din nou!\n";
                            }
                        }
                        if (expression2 == 4){
                            valid2 = 0;
                        }

                    }else{
                        cout << "Trebuie sa alegeti una dintre optiuni, Incercati din nou!\n";
                    }

                }while(valid2);

            }
            if(expression == 4)
                valid = 0;
        }else{
            cout << "Trebuie sa alegeti una dintre optiuni, Incercati din nou!\n";
        }
    }while(valid);

    return 0;
}

//TO DO: +=