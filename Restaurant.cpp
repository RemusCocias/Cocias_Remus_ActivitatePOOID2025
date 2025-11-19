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

    // metoda de afisare
    void afisare() const {
        cout << "Restaurant ID: " << id << "\n";
        cout << "  Nume: " << nume << "\n";
        cout << "  Adresa: " << adresa << "\n";
        cout << "  Numar locuri: " << nrLocuri << "\n";
        cout << "  Tip bucatarie: " << (tipBucatarie ? tipBucatarie : "N/A") << "\n";
        cout << "-----------------------------\n";
    }

    // functie statica - calculeaza media locurilor
    static double mediaLocuri(const Restaurant& r1,
        const Restaurant& r2,
        const Restaurant& r3) {
        return (r1.nrLocuri + r2.nrLocuri + r3.nrLocuri) / 3.0;
    }

    // functie statica simpla - intoarce totalul de restaurante
    static int getTotalRestaurante() {
        return totalRestaurante;
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

    void afisare() const {
        cout << "Angajat ID: " << id << "\n";
        cout << "  Nume: " << nume << "\n";
        cout << "  Functie: " << functie << "\n";
        cout << "  Salariu: " << salariu << "\n";
        cout << "  Ani experienta: " << (aniExperienta ? *aniExperienta : -1) << "\n";
        cout << "-----------------------------\n";
    }

    // functie statica - salariul mediu al 3 angajati
    static double salariuMediu(const Angajat& a1,
        const Angajat& a2,
        const Angajat& a3) {
        return (a1.salariu + a2.salariu + a3.salariu) / 3.0;
    }

    static int getTotalAngajati() {
        return totalAngajati;
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

    void afisare() const {
        cout << "Client ID: " << id << "\n";
        cout << "  Nume: " << nume << "\n";
        cout << "  Varsta: " << varsta << "\n";
        cout << "  Buget: " << buget << "\n";
        cout << "  Reducere fidelitate: " << (reducereFidelitate ? *reducereFidelitate : 0.0) << "%\n";
        cout << "-----------------------------\n";
    }

    // functie statica - buget total al 3 clienti
    static double bugetTotal(const Client& c1,
        const Client& c2,
        const Client& c3) {
        return c1.buget + c2.buget + c3.buget;
    }

    static int getTotalClienti() {
        return totalClienti;
    }
};

int Client::totalClienti = 0;


// ====== FUNCTIA MAIN - testam TOTI constructorii ======
int main() {
    // --- Restaurante ---
    Restaurant r1;  // constructor fara parametri
    Restaurant r2("RAC Bistro");  // constructor cu un parametru
    Restaurant r3("La Remus", "Bucuresti, Str. Exemplu 10", 80, "mediteraneana"); // toti parametrii

    cout << "=== Restaurante ===\n";
    r1.afisare();
    r2.afisare();
    r3.afisare();

    cout << "Media locurilor celor 3 restaurante: "
        << Restaurant::mediaLocuri(r1, r2, r3) << "\n";
    cout << "Total restaurante create: "
        << Restaurant::getTotalRestaurante() << "\n\n";


    // --- Angajati ---
    Angajat a1;  // fara parametri
    Angajat a2("Andrei", "Ospatar"); // 2 parametri
    Angajat a3("Maria", "Manager", 6500, 5); // mai multi parametri

    cout << "=== Angajati ===\n";
    a1.afisare();
    a2.afisare();
    a3.afisare();

    cout << "Salariu mediu al celor 3 angajati: "
        << Angajat::salariuMediu(a1, a2, a3) << "\n";
    cout << "Total angajati creati: "
        << Angajat::getTotalAngajati() << "\n\n";


    // --- Clienti ---
    Client c1; // fara parametri
    Client c2("Cosmin", 25); // 2 parametri
    Client c3("Ioana", 30, 350.0, 10.0); // mai multi parametri

    cout << "=== Clienti ===\n";
    c1.afisare();
    c2.afisare();
    c3.afisare();

    cout << "Bugetul total al celor 3 clienti: "
        << Client::bugetTotal(c1, c2, c3) << "\n";
    cout << "Total clienti creati: "
        << Client::getTotalClienti() << "\n\n";

    return 0;
}
