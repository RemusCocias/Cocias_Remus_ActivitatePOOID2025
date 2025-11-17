#include <iostream>
#include <cstring>
using namespace std;

// ====== CLASA RESTAURANT ======
class Restaurant {
public:
    // atribute normale
    string nume;
    string adresa;
    int nrLocuri;

    // atribut static
    static int totalRestaurante;

    // atribut constant
    const int id;

    // pointer in HEAP
    char* tipBucatarie;

public:

    // Constructor 1 – fara parametri
    Restaurant() : id(++totalRestaurante) {
        nume = "Necunoscut";
        adresa = "Necunoscuta";
        nrLocuri = 0;

        const char* tip = "necunoscuta";
        tipBucatarie = new char[strlen(tip) + 1];
        strcpy_s(tipBucatarie, strlen(tip) + 1, tip);
    }

    // Constructor 2 – cu un parametru
    Restaurant(string n) : id(++totalRestaurante) {
        nume = n;
        adresa = "Necunoscuta";
        nrLocuri = 30;

        const char* tip = "internationala";
        tipBucatarie = new char[strlen(tip) + 1];
        strcpy_s(tipBucatarie, strlen(tip) + 1, tip);
    }

    // Constructor 3 – cu mai multi parametri
    Restaurant(string n, string a, int locuri, const char* tip)
        : id(++totalRestaurante) {

        nume = n;
        adresa = a;
        nrLocuri = locuri;

        tipBucatarie = new char[strlen(tip) + 1];
        strcpy_s(tipBucatarie, strlen(tip) + 1, tip);
    }

    // Destructor
    ~Restaurant() {
        delete[] tipBucatarie;
    }
};

int Restaurant::totalRestaurante = 0;


// ====== CLASA ANGAJAT ======
class Angajat {
public:
    string nume;
    string functie;
    double salariu;

    static int totalAngajati;

    const int id;

    int* aniExperienta;

public:
    // Constructor 1
    Angajat() : id(++totalAngajati) {
        nume = "Anonim";
        functie = "Necunoscuta";
        salariu = 0;

        aniExperienta = new int(0);
    }

    // Constructor 2
    Angajat(string n, string f) : id(++totalAngajati) {
        nume = n;
        functie = f;
        salariu = 3000;

        aniExperienta = new int(1);
    }

    // Constructor 3
    Angajat(string n, string f, double s, int ani) : id(++totalAngajati) {
        nume = n;
        functie = f;
        salariu = s;

        aniExperienta = new int(ani);
    }

    ~Angajat() {
        delete aniExperienta;
    }
};

int Angajat::totalAngajati = 0;


// ====== CLASA CLIENT ======
class Client {
public:
    string nume;
    int varsta;
    double buget;

    static int totalClienti;

    const int id;

    double* reducereFidelitate;

public:
    // Constructor 1
    Client() : id(++totalClienti) {
        nume = "Necunoscut";
        varsta = 0;
        buget = 0;

        reducereFidelitate = new double(0.0);
    }

    // Constructor 2
    Client(string n, int v) : id(++totalClienti) {
        nume = n;
        varsta = v;
        buget = 100;

        reducereFidelitate = new double(5.0);
    }

    // Constructor 3
    Client(string n, int v, double b, double reducere) : id(++totalClienti) {
        nume = n;
        varsta = v;
        buget = b;

        reducereFidelitate = new double(reducere);
    }

    ~Client() {
        delete reducereFidelitate;
    }
};

int Client::totalClienti = 0;


int main() {
    cout << "Proiect OOP - Commit 3 (constructori, heap, static, const, strcpy_s)" << endl;
    return 0;
}
