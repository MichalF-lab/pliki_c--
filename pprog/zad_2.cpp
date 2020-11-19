#include <string.h>
#include <iostream>
#include <stdio.h>

#pragma warning(suppress : 4996)

using namespace std;

int ID = 0, ile_ksiazek = 0;

struct Adres
{
    string miasto;
    string ulica;
    int nr_domu;
    int nr_mieszkania;
    int kod;
} Poznan;


struct Osoba
{
    string imie;
    string nazwisko;
    Adres adres;
}klient1 = { "Kacper","Nowak",Poznan };

struct Autor
{
    string* imie;
    string nazwisko;
    int ID;
}Sapkowski;


struct Book
{
    string tytul;
    Autor autor;
    char* ISBN;
    string wydawnictwo;
    int rok_wydania;
    string seria_wydawnicza;
};

Book* tablica_ksiazek = new Book[1000];
Osoba* tablica_kilentow = new Osoba[1000];
Autor* tablica_autorow = new Autor[1000];
bool tablica_ksiazek_wypozyczonych[1000];

void wypozycz(Book ksiazka) {
    int ktory = 0;
    while (ktory < 1000) {
        if (ksiazka.ISBN == tablica_ksiazek->ISBN) {
            if (tablica_ksiazek_wypozyczonych[ktory] != true) {
                tablica_ksiazek_wypozyczonych[ktory] = true;
                cout << "Wypozyczono pomyslnie " << endl;
                return;
            }
            else {
                cout << "Ksiazka zostala juz wyporzyczona " << endl;
                return;
            }
        }
        tablica_ksiazek++;
        ktory++;
    }
}

void zwroc(Book ksiazka) {
    int ktory = 0;
    while (ktory < 1000) {
        if (ksiazka.ISBN == tablica_ksiazek->ISBN) {
            if (tablica_ksiazek_wypozyczonych[ktory] == true) {
                tablica_ksiazek_wypozyczonych[ktory] = false;
                cout << "Zwrocono pomyslnie " << endl;
                return;
            }
            else {
                cout << "Ksiazka nie zostala wypozyczona " << endl;
                return;
            }
        }
        tablica_ksiazek++;
        ktory++;
    }
}

void add_Book(Book nazwa) {
    *tablica_ksiazek = nazwa;
    tablica_ksiazek++;
    ile_ksiazek++;
}

int ID_autora(Autor nowy) {
    for (int i = 0; i < ile_ksiazek; i++) {
        if (tablica_ksiazek[i].autor.imie == nowy.imie) {
            if (tablica_ksiazek[i].autor.nazwisko == nowy.nazwisko) {
                return tablica_ksiazek[i].autor.ID;
            }
        }
    }
    ID++;
    return ID;
}

void create_Book() {
    string tytul;
    cout << "Podaj nazwe ksiazki ";
    cin >> tytul;
    int ile_imion;
    cout << endl << "Ile autor ma imion? ";
    cin >> ile_imion;
    string* imie = new string[ile_imion];
    for (int i = 0; i < ile_imion; i++) {
        cout << "Podaj jego " << i << " imie";
        cin >> *imie;
        imie++;
    }
    string nazwisko;
    cout << endl << "Podaj nazwiko autora ";
    cin >> nazwisko;
    char ISBN[13];
    cout << endl << "podaj ISBN ";
    for (int i = 0; i < 13; i++) {
        cin >> ISBN[i];
    }
    string wydawnictwo;
    cout << endl << "Podaj wydawnictwo ";
    cin >> wydawnictwo;
    int rok_wydania;
    cout << endl << "Podaj rok wydania ";
    cin >> rok_wydania;
    int seria;
    cout << endl << "Czy ksiązka ma seriw wydawniczą? (jeśli tak naciśnij 1) ";
    cin >> seria;
    string seria_wydawincza = "";
    if (seria == 1) {
        cout << endl << "Podaj serie wydawniczą ";
        cin >> seria_wydawincza;
    }
    Autor autor = { imie, nazwisko, ID };
    autor.ID = ID_autora(autor);
    Book ksiazka = { tytul, autor, ISBN, wydawnictwo, rok_wydania, seria_wydawincza };
    return add_Book(ksiazka);
}


void delete_book(Book ksiazka) {
    int i = 0;
    while (i < 1000)
    {
        if (tablica_ksiazek[i].tytul == ksiazka.tytul) {
            Book* tablica_ksiazek1 = new Book[1000];
            for (int j = 0; j < ile_ksiazek; j++) {
                if (i == j) j++;
                tablica_ksiazek1[i] = tablica_ksiazek[j];
            }
            for (int j = 0; j < ile_ksiazek - 1; j++) {
                tablica_ksiazek[i] = tablica_ksiazek1[i];
            }
            ile_ksiazek--;
            cout << "Pomyslnie usunieto ksiazke" << endl;
            return;
        }
        i++;
    }
}

void usuwanie_book() {
    string ISBN1;
    cout << "Podaj ISBN " << endl;
    cin >> ISBN1;
    char* ISBN = new char[13];
    strcpy(ISBN, ISBN1.c_str());
    for (int i = 0; i < ile_ksiazek; i++) {
        if (tablica_ksiazek[i].ISBN == ISBN1) return delete_book(tablica_ksiazek[i]);
    }
}

void add_person(Osoba person) {
    int i = 0;
    while (i < 1000)
    {
        if (tablica_kilentow[i].imie == "") {
            tablica_kilentow[i] = person;
            return;
        }
        i++;
    }

}

void add_klient() {
    string miasto;
    string ulica;
    int nr_domu;
    int nr_mieszkania;
    int kod;
    string imie;
    string nazwisko;
    cout << "Podaj miasto, ulice nr_domu, kod pocztowy" << endl;
    cin >> miasto >> ulica >> nr_domu >> kod;
    cout << "Czy klient ma nr_mieszkania? (jeśli tak nacisnij 1)<<endl";
    int sprawdz;
    cin >> sprawdz;
    if (sprawdz == 1) {
        cout << "Podaj nr mieszkania" << endl;
        cin >> nr_mieszkania;
    }
    Adres klienta = { miasto, ulica,nr_domu,nr_mieszkania,kod };
    cout << "Podaj imie i nazwisko klienta" << endl;
    cin >> imie >> nazwisko;
    Osoba klient = { imie, nazwisko, klienta };
    return add_person(klient);
}





int main(void) {
    for (int i = 0; i < 1000; i++) tablica_ksiazek_wypozyczonych[i] = false;
    // ustalam ze niewypozyczone ksiazki maja wartośc false
    char isbn[13] = { '1','1','1','1','1','1','1','1','1','1','1','1','1' };
    char* isbn1 = isbn;
    Book Wiedzmin = { "wiedzmin",Sapkowski,isbn1,"Nowa era",2000,"wiedzmin" };
    wypozycz(Wiedzmin);
    zwroc(Wiedzmin);
    add_Book(Wiedzmin);
    create_Book();
    delete_book(Wiedzmin);
    usuwanie_book();
    add_klient();
    add_person(klient1);
    return 0;
}