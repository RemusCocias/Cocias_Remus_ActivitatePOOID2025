#include <iostream>
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

    // pointer (heap)
    char* tipBucatarie;  // va fi alocat cu new in commitul urmator

public:
    // constructorii vor fi adaugati in commitul 3
};

// initializare atribut static
int Restaurant::totalRestaurante = 0;


// ====== CLASA ANGAJAT ======
class Angajat {
public:
    // atribute normale
    string nume;
    string functie;
    double salariu;

    // atribut static
    static int totalAngajati;

    // atribut constant
    const int id;

    // pointer (heap)
    int* aniExperienta;

public:
    // constructorii vor fi adaugati in commitul 3
};

// initializare static
int Angajat::totalAngajati = 0;


// ====== CLASA CLIENT ======
class Client {
public:
    // atribute normale
    string nume;
    int varsta;
    double buget;

    // atribut static
    static int totalClienti;

    // atribut constant
    const int id;

    // pointer (heap)
    double* reducereFidelitate;

public:
    // constructorii vor fi adaugati in commitul 3
};

// initializare static
int Client::totalClienti = 0;


int main() {
    cout << "Proiect OOP - commitul 2 (atribute adaugate)." << endl;
    return 0;
}
