#include <iostream>
#include <cstring>
using namespace std;

// ====== CLASA RESTAURANT ======
class Restaurant {
private:
    string nume;
    string adresa;
    int nrLocuri;
    char* tipBucatarie;
    const int id;
    static int totalRestaurante;

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

    // Constructor de copiere (deep copy)
    Restaurant(const Restaurant& other) : id(++totalRestaurante) {
        nume = other.nume;
        adresa = other.adresa;
        nrLocuri = other.nrLocuri;

        if (other.tipBucatarie != nullptr) {
            tipBucatarie = new char[strlen(other.tipBucatarie) + 1];
            strcpy_s(tipBucatarie, strlen(other.tipBucatarie) + 1, other.tipBucatarie);
        }
        else {
            tipBucatarie = nullptr;
        }
    }

    // Destructor
    ~Restaurant() {
        delete[] tipBucatarie;
    }

    // ===== GETTERI =====
    string getNume() const { return nume; }
    string getAdresa() const { return adresa; }
    int getNrLocuri() const { return nrLocuri; }
    const char* getTipBucatarie() const { return tipBucatarie; }
    int getId() const { return id; }

    static int getTotalRestaurante() { return totalRestaurante; }

    // ===== SETTERI =====
    void setNume(const string& n) {
        if (!n.empty()) {
            nume = n;
        }
    }

    void setAdresa(const string& a) {
        if (!a.empty()) {
            adresa = a;
        }
    }

    void setNrLocuri(int nr) {
        if (nr > 0) {
            nrLocuri = nr;
        }
    }

    void setTipBucatarie(const char* tip) {
        if (tip != nullptr && strlen(tip) > 0) {
            if (tipBucatarie != nullptr) {
                delete[] tipBucatarie;
            }
            tipBucatarie = new char[strlen(tip) + 1];
            strcpy_s(tipBucatarie, strlen(tip) + 1, tip);
        }
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

    // functie globala friend
    friend void comparaRestaurante(const Restaurant& r1, const Restaurant& r2);
};

int Restaurant::totalRestaurante = 0;


// ====== CLASA ANGAJAT ======
class Angajat {
private:
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

    // Constructor de copiere (deep copy)
    Angajat(const Angajat& other) : id(++totalAngajati) {
        nume = other.nume;
        functie = other.functie;
        salariu = other.salariu;

        if (other.aniExperienta != nullptr) {
            aniExperienta = new int(*other.aniExperienta);
        }
        else {
            aniExperienta = nullptr;
        }
    }

    // Destructor
    ~Angajat() {
        delete aniExperienta;
    }

    // ===== GETTERI =====
    string getNume() const { return nume; }
    string getFunctie() const { return functie; }
    double getSalariu() const { return salariu; }
    int getAniExperienta() const { return aniExperienta ? *aniExperienta : 0; }
    int getId() const { return id; }
    static int getTotalAngajati() { return totalAngajati; }

    // ===== SETTERI =====
    void setNume(const string& n) {
        if (!n.empty()) nume = n;
    }

    void setFunctie(const string& f) {
        if (!f.empty()) functie = f;
    }

    void setSalariu(double s) {
        if (s > 0) salariu = s;
    }

    void setAniExperienta(int ani) {
        if (ani >= 0) {
            if (aniExperienta) delete aniExperienta;
            aniExperienta = new int(ani);
        }
    }

    // ===== AFISARE =====
    void afisare() const {
        cout << "Angajat ID: " << id << "\n";
        cout << "  Nume: " << nume << "\n";
        cout << "  Functie: " << functie << "\n";
        cout << "  Salariu: " << salariu << "\n";
        cout << "  Ani experienta: " << getAniExperienta() << "\n";
        cout << "-----------------------------\n";
    }

    // functie statica - salariu mediu al 3 angajati
    static double salariuMediu(const Angajat& a1,
        const Angajat& a2,
        const Angajat& a3) {
        return (a1.salariu + a2.salariu + a3.salariu) / 3.0;
    }

    // functie globala friend
    friend double diferentaSalarii(const Angajat& a1, const Angajat& a2);
};

int Angajat::totalAngajati = 0;



// ====== CLASA CLIENT ======
class Client {
private:
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

    // Constructor de copiere (deep copy)
    Client(const Client& other) : id(++totalClienti) {
        nume = other.nume;
        varsta = other.varsta;
        buget = other.buget;

        if (other.reducereFidelitate != nullptr) {
            reducereFidelitate = new double(*other.reducereFidelitate);
        }
        else {
            reducereFidelitate = nullptr;
        }
    }

    // Destructor
    ~Client() {
        delete reducereFidelitate;
    }

    // ===== GETTERI =====
    string getNume() const { return nume; }
    int getVarsta() const { return varsta; }
    double getBuget() const { return buget; }
    double getReducereFidelitate() const { return reducereFidelitate ? *reducereFidelitate : 0; }
    int getId() const { return id; }

    static int getTotalClienti() { return totalClienti; }

    // ===== SETTERI =====
    void setNume(const string& n) {
        if (!n.empty()) nume = n;
    }

    void setVarsta(int v) {
        if (v > 0) varsta = v;
    }

    void setBuget(double b) {
        if (b >= 0) buget = b;
    }

    void setReducereFidelitate(double reducere) {
        if (reducere >= 0) {
            if (reducereFidelitate != nullptr)
                delete reducereFidelitate;
            reducereFidelitate = new double(reducere);
        }
    }

    // ===== AFISARE =====
    void afisare() const {
        cout << "Client ID: " << id << "\n";
        cout << "  Nume: " << nume << "\n";
        cout << "  Varsta: " << varsta << "\n";
        cout << "  Buget: " << buget << "\n";
        cout << "  Reducere fidelitate: " << getReducereFidelitate() << "%\n";
        cout << "-----------------------------\n";
    }

    // functie statica - buget total al 3 clienti
    static double bugetTotal(const Client& c1,
        const Client& c2,
        const Client& c3) {
        return c1.buget + c2.buget + c3.buget;
    }
};

int Client::totalClienti = 0;


// ====== FUNCTIE GLOBALA FRIEND – RESTAURANT ======
void comparaRestaurante(const Restaurant& r1, const Restaurant& r2) {
    cout << "\n=== Compara restaurante ===\n";
    cout << "Restaurant " << r1.getNume() << " are " << r1.getNrLocuri() << " locuri.\n";
    cout << "Restaurant " << r2.getNume() << " are " << r2.getNrLocuri() << " locuri.\n";

    if (r1.nrLocuri > r2.nrLocuri)
        cout << "Primul restaurant este mai mare.\n";
    else if (r1.nrLocuri < r2.nrLocuri)
        cout << "Al doilea restaurant este mai mare.\n";
    else
        cout << "Cele doua restaurante au acelasi numar de locuri.\n";
}


// ====== FUNCTIE GLOBALA FRIEND – ANGAJAT ======
double diferentaSalarii(const Angajat& a1, const Angajat& a2) {
    cout << "\n=== Comparare salarii ===\n";
    cout << "Salariu " << a1.getNume() << ": " << a1.getSalariu() << "\n";
    cout << "Salariu " << a2.getNume() << ": " << a2.getSalariu() << "\n";
    return a1.salariu - a2.salariu; // acces direct la atribut privat datorita friend
}



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
    cout << "Total restaurante create (inainte de copie): "
        << Restaurant::getTotalRestaurante() << "\n\n";

    // testam copy constructor pentru Restaurant
    Restaurant rCopy = r3; // copy constructor
    cout << "Restaurant copiat (rCopy din r3):\n";
    rCopy.afisare();
    cout << "Nume restaurant copiat (getter): " << rCopy.getNume() << "\n\n";


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
    cout << "Total angajati creati (inainte de copie): "
        << Angajat::getTotalAngajati() << "\n\n";

    // testam copy constructor pentru Angajat
    Angajat aCopy = a3;
    cout << "Angajat copiat (aCopy din a3):\n";
    aCopy.afisare();
    cout << "Salariul angajatului copiat (getter): "
        << aCopy.getSalariu() << "\n\n";


    // --- Clienti ---
    Client c1; 
    Client c2("Cosmin", 25); 
    Client c3("Ioana", 30, 350.0, 10.0); 

    cout << "=== Clienti ===\n";
    c1.afisare();
    c2.afisare();
    c3.afisare();

    cout << "Bugetul total al celor 3 clienti: "
        << Client::bugetTotal(c1, c2, c3) << "\n";
    cout << "Total clienti creati (inainte de copie): "
        << Client::getTotalClienti() << "\n\n";

    // testam copy constructor pentru Client
    Client cCopy = c3;
    cout << "Client copiat (cCopy din c3):\n";
    cCopy.afisare();
    cout << "Bugetul clientului copiat (getter): "
        << cCopy.getBuget() << "\n\n";

    // Testam functiile friend 
    comparaRestaurante(r1, r3);

    double dif = diferentaSalarii(a3, a2);
    cout << "Diferenta de salarii intre a3 si a2 este: " << dif << "\n";

    cout << "\n=== Final testare copy constructors si functii friend ===\n";

    return 0;
}


