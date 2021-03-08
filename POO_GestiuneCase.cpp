#include <iostream>
#include <bits/stdc++.h>  ///all in one library

using namespace std;

using tip_locuinta = string;      ///un fel de alias petru cand vom face set-ul de locuinta si tip

const string tip_casa = "CASA";              ///string folosit ulterior la dynamic_cast
const string tip_apartament = "APARTAMENT";  ///string folosit ulterior la dynamic_cast

/// CLASA LOCUINTA ------ CLASA BAZA
class Locuinta
{
protected:
    string nume_client;
    double suprafata_utila;
    double discount;
    double pret_metru_patrat;
    int id;

public:

    Locuinta(const int);
    Locuinta(const int, const string, const double, const double, const double);
    Locuinta(Locuinta&);
    virtual ~Locuinta();

    ///setters
    void set_id (const int _id)
    {
        id = _id;
    }
    void set_nume (const string _nume_client)
    {
        nume_client = _nume_client;
    }
    void set_suprafata (const double _suprafata_utila)
    {
        suprafata_utila = _suprafata_utila;
    }
    void set_discount (const double _discount)
    {
        discount = _discount;
    }
    void set_pret (const double _pret_metru_patrat)
    {
        pret_metru_patrat = _pret_metru_patrat;
    }

    /// getters
    int get_id () const
    {
        return id;
    }
    string get_nume () const
    {
        return nume_client;
    }
    double get_suprafata () const
    {
        return suprafata_utila;
    }
    double get_discount () const
    {
        return discount;
    }
    double get_pret () const
    {
        return pret_metru_patrat;
    }

    virtual void citire(istream& in);
    virtual void afisare(ostream &out);
    //friend istream& operator >> (istream&, Locuinta&);
    // friend ostream& operator << (ostream&, Locuinta&);
    Locuinta& operator = (const Locuinta&);
    virtual double chirie() = 0;     ///metoda care calculeaza chiria
};

/// constructor de initializare teoretic fara parametrii, practic are unul
Locuinta :: Locuinta(const int _id)
{
    id = _id;
    nume_client = "";
    suprafata_utila = 0;
    discount = 0;
    pret_metru_patrat = 0;
}

/// constructor de initializare cu parametrii
Locuinta :: Locuinta(const int _id, const string _nume_client, const double _suprafata_utila, const double _discount, const double _pret_metru_patrat)
{
    id = _id;
    nume_client = _nume_client;
    suprafata_utila = _suprafata_utila;
    discount = _discount;
    pret_metru_patrat = _pret_metru_patrat;
}

/// constructor de copiere
Locuinta :: Locuinta (Locuinta& l)
{
    this->id = l.id;
    this->nume_client = l.nume_client;
    this->suprafata_utila = l.suprafata_utila;
    this->discount = l.discount;
    this->pret_metru_patrat = l.pret_metru_patrat;
}

/// deconstructor
Locuinta :: ~Locuinta()
{

}

/// metoda pentru citire
void Locuinta :: citire(istream& in)
{
    int _id;
    string _nume_client;
    double _suprafata_utila;
    double _discount;
    double _pret_metru_patrat;

    // cout<<"ID: ";
    // in>>_id;
    cout<<"Nume client: ";

    getline(in, _nume_client);
    getline(in, _nume_client);

    cout<<"Suprafata utila: ";
    in>>_suprafata_utila;
    cout<<"Discount oferit (0-10%): ";
    in>>_discount;
    cout<<"Pret/m^2: ";
    in>>_pret_metru_patrat;

    id = _id;
    nume_client = _nume_client;
    suprafata_utila = _suprafata_utila;
    discount = _discount;
    pret_metru_patrat = _pret_metru_patrat;
}

/// metoda pentru afisare
void Locuinta :: afisare(ostream &out)
{
    out<<"ID: ";
    out<<id<<"\n";
    out<<"Nume client: ";
    out<<nume_client<<"\n";
    out<<"Suprafata utila: ";
    out<<suprafata_utila<<"\n";
    out<<"Discount oferit: ";
    out<<discount<<"\n";
    out<<"Pret/m^2: ";
    out<<pret_metru_patrat<<"\n";
}

/// supraincarcare operator de atribuire
Locuinta& Locuinta :: operator = (const Locuinta &l)
{
    nume_client = l.nume_client;
    suprafata_utila = l.suprafata_utila;
    discount = l.discount;
    pret_metru_patrat = l.pret_metru_patrat;
    id = l.id;

    return *this;
}

/// supraincarcare >>
istream& operator >> (istream& in, Locuinta& l)
{
    l.citire(in);
    return in;
}

/// supraincarcare <<
ostream& operator << (ostream& out, Locuinta& l)
{
    l.afisare(out);
    return out;
}


///=============================================================================================
///CLASA APARTAMENT ----------- CLASA DERIVATA
class Apartament : public Locuinta
{
private:
    int etaj;

public:
    Apartament(const int);
    Apartament(const int, const string, const double, const double, const double, const int);
    Apartament(Apartament&);
    ~Apartament();

    /// setters
    void set_id (const int _id)
    {
        id = _id;
    }
    void set_nume (const string _nume_client)
    {
        nume_client = _nume_client;
    }
    void set_suprafata (const double _suprafata_utila)
    {
        suprafata_utila = _suprafata_utila;
    }
    void set_discount (const double _discount)
    {
        discount = _discount;
    }
    void set_pret (const double _pret_metru_patrat)
    {
        pret_metru_patrat = _pret_metru_patrat;
    }
    void set_etaj (const int _etaj)
    {
        etaj = _etaj;
    }

    /// getters
    int get_id () const
    {
        return id;
    }
    string get_nume () const
    {
        return nume_client;
    }
    double get_suprafata () const
    {
        return suprafata_utila;
    }
    double get_discount () const
    {
        return discount;
    }
    double get_pret () const
    {
        return pret_metru_patrat;
    }
    int get_etaj () const
    {
        return etaj;
    }

    void citire(istream& in);
    void afisare(ostream &out);
    friend istream& operator >> (istream&, Apartament&);
    friend ostream& operator << (ostream&, Apartament&);
    Apartament& operator = (const Apartament&);

    double chirie()      ///metoda care calculeaza chiria unui apartament
    {
        double pret = 1.0 * pret_metru_patrat * (100 - discount) / 100 * suprafata_utila;
        return pret;
    }
};


///constructor de initializare
Apartament :: Apartament(const int _id) : Locuinta(_id)  ///apelam constructorul din casa baza si mai adaugam ce avem pentru clasa derivata
{
    etaj = 0;
}

///constructor de initializare cu parametrii
Apartament :: Apartament(const int _id, const string _nume_client, const double _suprafata_utila,
                         const double _discount, const double _pret_metru_patrat, const int _etaj)
    : Locuinta(_id, _nume_client, _suprafata_utila, _discount, _pret_metru_patrat)
{
    etaj = _etaj;
}

///deconstructor
Apartament :: ~Apartament()
{

}

/// metoda pentru citire
void Apartament :: citire(istream& in)
{
    Locuinta :: citire(in);

    int _etaj;
    cout<<"Etaj: ";
    in>>_etaj;
    etaj = _etaj;
}

/// metoda pentru afisare
void Apartament :: afisare(ostream &out)
{
    Locuinta :: afisare(out);

    out<<"Etaj: ";
    out<<etaj<<"\n";
}

/// supraincarcare operator de atribuire
Apartament& Apartament :: operator = (const Apartament &a)
{
    id = a.id;
    nume_client = a.nume_client;
    suprafata_utila = a.suprafata_utila;
    discount = a.discount;
    pret_metru_patrat = a.pret_metru_patrat;
    etaj = a.etaj;

    return *this;
}

/// supraincarcare >>
istream& operator >> (istream& in, Apartament& a)
{
    a.citire(in);
    return in;
}

/// supraincarcare <<
ostream& operator << (ostream& out, Apartament& a)
{
    a.afisare(out);
    return out;
}


///==================================================================================================

///CLASA CASA -------- CLASA DERIVATA
class Casa : public Locuinta
{
private:
    double suprafata_curte;
    int etaje;
    double pret_metru_patrat_curte;
    vector <int> suprafata_utila_etaj; ///pentru a aloca dinamic numarul de etaje
public:

    static unordered_map <int, int> chirii_case;  ///pentru a stoca direct casa cu chiria ei
    Casa(const int);
    Casa(const int, const string, const double, const double, const double,
         const int, const double, const double, const vector <int>);
    ~Casa();

    /// setters
    void set_id (const int _id)
    {
        id = _id;
    }
    void set_nume (const string _nume_client)
    {
        nume_client = _nume_client;
    }
    void set_suprafata (const double _suprafata_utila)
    {
        suprafata_utila = _suprafata_utila;
    }
    void set_discount (const double _discount)
    {
        discount = _discount;
    }
    void set_pret (const double _pret_metru_patrat)
    {
        pret_metru_patrat = _pret_metru_patrat;
    }
    void set_suprafata_curte (const double _suprafata_curte)
    {
        suprafata_curte = _suprafata_curte;
    }
    void set_etaje (const int _etaje)
    {
        etaje = _etaje;
    }
    void set_pret_curte (const double _pret_metru_patrat_curte)
    {
        pret_metru_patrat_curte = _pret_metru_patrat_curte;
    }
    void set_suprafata_etaj (const vector <int> _suprafata_utila_etaj)
    {
        suprafata_utila_etaj = _suprafata_utila_etaj;
    }

    /// getters
    int get_id () const
    {
        return id;
    }
    string get_nume () const
    {
        return nume_client;
    }
    double get_suprafata () const
    {
        return suprafata_utila;
    }
    double get_discount () const
    {
        return discount;
    }
    double get_pret () const
    {
        return pret_metru_patrat;
    };
    double get_suprafata_curte () const
    {
        return suprafata_curte;
    }
    int get_etaje () const
    {
        return etaje;
    }
    double get_pret_curte () const
    {
        return pret_metru_patrat_curte;
    }
    vector <int> get_suprafata_etaj ()
    {
        return suprafata_utila_etaj;
    }

    void citire(istream& in);
    void afisare(ostream &out);
    friend istream& operator >> (istream&, Casa&);
    friend ostream& operator << (ostream&, Casa&);
    Casa& operator = (const Casa&);

    static int nr_case()
    {
        return chirii_case.size();
    }

    static int chirie_totala()   ///metoda care aduna chiriile tuturor caselor din vector
    {
        int sum = 0;
        for(auto it:chirii_case)   ///it - iterator; parcurge automat map-ul chirii_case de la inceput pana la sfarsit
            sum+=it.second;        ///in it.second este stocata chiria casei, in it.first avem id-ul casei respective
        return sum;
    }

    double chirie()    ///metoda care calculeaza chiria unei case
    {
        double pret = 1.0 * pret_metru_patrat * (100 - discount) / 100 * suprafata_utila;
        pret += pret_metru_patrat_curte * suprafata_curte;
        return pret;
    }
};
///constructor
Casa :: Casa(const int _id) : Locuinta(_id)
{
    suprafata_curte = 0;
    etaje = 0;
    pret_metru_patrat_curte = 0;

    chirii_case[id] = 0;
}

///constructor de initializare cu parametrii
Casa :: Casa(const int _id, const string _nume_client, const double _suprafata_utila, const double _discount, const double _pret_metru_patrat,
             const int _etaje, const double _suprafata_curte, const double _pret_metru_patrat_curte, const vector <int> _suprafata_utila_etaj)
    : Locuinta(_id, _nume_client, _suprafata_utila, _discount, _pret_metru_patrat)
{
    etaje = _etaje;
    suprafata_utila_etaj.assign(_suprafata_utila_etaj.begin(), _suprafata_utila_etaj.end());

    chirii_case[id] = chirie();
}

///deconstructor
Casa :: ~Casa() {}

/// metoda pentru citire
void Casa :: citire(istream& in)
{
    Locuinta :: citire(in);
    double _suprafata_curte;
    int _etaje;
    double _pret_metru_patrat_curte;
    int suprafata;
    cout<<"Suprafata curte: ";
    in>>_suprafata_curte;
    cout<<"Etaje: ";
    in>>_etaje;
    cout<<"Pret/m^2 curte: ";
    in>>_pret_metru_patrat_curte;

    for(int i = 0; i <= _etaje; i++)
    {
        cout<<"Suprafata utila etaj "<<i<<": ";
        in>>suprafata;
        suprafata_utila_etaj.push_back(suprafata);
    }

    etaje = _etaje;
    suprafata_curte = _suprafata_curte;
    etaje = _etaje;
    pret_metru_patrat_curte = _pret_metru_patrat_curte;

    chirii_case[id] = chirie();

}

/// metoda pentru afisare
void Casa :: afisare(ostream &out)
{
    Locuinta :: afisare(out);

    out<<"Suprafata carte: ";
    out<<suprafata_curte<<"\n";
    out<<"Nr etaje: ";
    out<<etaje<<"\n";
    out<<"Pret/m^2 curte: ";
    out<<pret_metru_patrat_curte<<"\n";
    for(int i = 0; i < suprafata_utila_etaj.size(); i++)
    {
        out<<"Suprafata utila etaj "<<i<<": ";
        out<<suprafata_utila_etaj[i]<<" \n";
    }

    out<<"\n";
}

/// supraincarcare operator de atribuire
Casa& Casa :: operator = (const Casa &c)
{
    id = c.id;
    nume_client = c.nume_client;
    suprafata_utila = c.suprafata_utila;
    discount = c.discount;
    pret_metru_patrat = c.pret_metru_patrat;
    suprafata_curte = c.suprafata_curte;
    etaje = c.etaje;
    pret_metru_patrat_curte = c.pret_metru_patrat_curte;
    suprafata_utila_etaj = c.suprafata_utila_etaj;
    return *this;
}

/// supraincarcare >>
istream& operator >> (istream& in, Casa& c)
{
    c.citire(in);
    return in;
}

/// supraincarcare <<
ostream& operator << (ostream& out, Casa& c)
{
    c.afisare(out);
    return out;
}

int get_type(Locuinta* x) ///verifica daca x este un obiect de tip Casa (returneaza 0) sau  Apartament(returneaza 1) - Downcasting/Upcasting
{
    if(dynamic_cast<Apartament*> (x))
        return 1;
    else if (dynamic_cast<Casa*> (x))  return 0;
}

///TEMPLATE GESTIUNE
template <typename T> class Gestiune
{
private:
    set <pair <Locuinta*, tip_locuinta> > locuinte;
public:

    Gestiune& operator += (const T& x)  ///supraincarcare operator +=
    {
        if(dynamic_cast<Casa*> (x))
            locuinte.insert(make_pair(x,tip_casa));   ///creem perechea unica de locuinta* cu string-ul "CASA"
        else if(dynamic_cast<Apartament*> (x))
            locuinte.insert(make_pair(x,tip_apartament));  ///creem perechea unica de locuinta* cu string-ul "APARTAMENT"
        else
            throw invalid_argument("Elementul introdus nu este o Casa* sau un Apartament*");
        return *this;
    }

    int nr_case()     ///metoda care numara doar casele
    {
        int nr = 0;
        for(auto it:locuinte)      ///it - iterator; parcurge automat set-ul locuinte de la inceput pana la sfarsit
            if(it.second == tip_casa)
                ++nr;
        return nr;
    }

    int nr_apartamente()   ///metoda care numara doar apartamentele
    {
        int nr = 0;
        for(auto it:locuinte)    ///it - iterator; parcurge automat set-ul locuinte de la inceput pana la sfarsit
            if(it.second == tip_apartament)
                ++nr;
        return nr;
    }
};

///initializarea variabilelor
unordered_map <int, int> Casa :: chirii_case;

///output meniu principal
void menu_output()
{
    cout<<"\n OPREA ANA-MARIA-RUXANDRA \n";
    cout<<"\n Aplicatie de gestiune a unei agentii imobiliare utilizand poo \n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Adaugati o locuinta noua";
    cout<<"\n";
    cout<<"2. Vizualizati o locuinta";
    cout<<"\n";
    cout<<"3. Calculator";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}

///output meniu secundar
void menu_output2 ()
{
    cout<<"\n1. Calculati chiria unui apartament\n";
    cout<<"2. Calculati chria unei case\n";
    cout<<"3. Nr total de apartamente\n";
    cout<<"4. Nr total de case\n";
    cout<<"5. Incasari totale case\n";
}

///meniu secundar
void menu2(Locuinta* loc[], int& nr, Gestiune <Locuinta*> g)
{
    int option;
    option = 0;

    menu_output2();
    cout<<"\nIntroduceti numarul actiunii: ";
    cin>>option;
    cout<<"\n";

    if (option == 1)
    {
        int x;
        for(int i = 0; i<nr; i++)
        {
            if(get_type(loc[i]) == 1)
                cout<<"\nApartamentul "<<i;
        }

        cout<<"\nAlegeti apartamentul: ";
        cin>>x;
        cout<<loc[x]->chirie();
    }

    if (option == 2)
    {
        int x;
        for(int i = 0; i<nr; i++)
        {
            if(get_type(loc[i]) == 0)
                cout<<"\nCasa "<<i;
        }

        cout<<"\nAlegeti casa: ";
        cin>>x;
        cout<<loc[x]->chirie();
    }

    if (option == 3)
    {
        cout<<"Sunt inregistrate "<<g.nr_apartamente()<<" apartamente\n";
    }

    if (option == 4)
    {
        cout<<"Sunt inregistrate "<<g.nr_case()<<" case\n";
    }

    if (option == 5)
    {
        cout<<"Total provenit din chirii case: "<<Casa :: chirie_totala();
    }
}

///meniu principal
void menu()
{
    int option;
    option = 0;

    Locuinta* loc [10];
    Gestiune <Locuinta*> g;
    int nr = 0;

    do
    {
        menu_output();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;

        if (option==1)
        {
            int n;                                  ///liniile 706-734 citirea si memorarea a n obiecte
            cout<<"\nNr locuinte de adaugat:  ";
            cin>>n;
            while(n)
            {
                string s;
                cout<<"\nIntroduceti tipul locuintei (APARTAMENT / CASA): ";
                cin>>s;
                if(s == "APARTAMENT")
                {
                    Locuinta* x = new Apartament(nr);
                    cin>>(*x);
                    x->set_id(nr);
                    g += x;
                    loc[nr++] = x;
                }
                else if (s == "CASA")

                {
                    Locuinta* x = new Casa(nr);
                    cin>>(*x);
                    x->set_id(nr);
                    g += x;
                    loc[nr++] = x;
                }
                n--;
            }
        }
        if (option==2)
        {

            for (int i = 0; i < nr; i++)
            {
                if(get_type(loc[i]) == 1)
                    cout<<"\nApartamentul "<<i;
                else
                    cout<<"\nCasa "<<i;
            }
            cout<<"\nCe locuinta doriti sa vizualizati?\n";
            cout<<"R: ";
            int x;
            cin>>x;

            if(get_type(loc[x]) == 1)
                cout<<"\n===============Apartamentul "<<x<<"===============\n"<<*loc[x];
            else
                cout<<"\n===============Casa "<<x<<"===============\n"<<*loc[x];


        }
        if (option==3)
        {
            menu2(loc, nr, g);
        }

        if (option<0||option>3)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}

int main()
{
    menu();
}
