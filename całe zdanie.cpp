#include <string>
#include <iostream>

using namespace std;

struct Adres
{
    string miasto;
    string ulica;
    int nr_domu;
    int nr_mieszkania;
    int kod;
};


struct Osoba
{
    string* imie;
    int ile_imion;
    string nazwisko;
    Adres adres;
    int ID_klienta;
};

struct Autor
{
    string* imie;
    int ile_imion;
    string nazwisko;
    int ID_autora;
};


struct Book
{
    string tytul;
    Autor autor;
    string ISBN;
    string wydawnictwo;
    int rok_wydania;
    string seria_wydawnicza;
    // jako ze moze byc pare takich samych ksiazek nalezy dodac klucz glówny
    int ID_ksiazek;
};


int f_ID_autora (Autor nowy, Autor * tablica_autorow,int ile_autorow, int & ID_autora){
    for(int i=0; i<ile_autorow;i++){
        if (tablica_autorow[i].imie == nowy.imie){
            if (tablica_autorow[i].nazwisko == nowy.nazwisko) return tablica_autorow[i].ID_autora;
        }
    }
    ID_autora++;
    return ID_autora;   
}


Autor create_autor(string* imie,int ile_imion,string nazwisko,int & ID_autora,  Autor * tablica_autorow, int ile_autorow){
    Autor autor = { imie,ile_imion, nazwisko, ID_autora };
    autor.ID_autora = f_ID_autora (autor, tablica_autorow, ile_autorow, ID_autora);
    return autor;
}

void add_autor(string* imie,int ile_imion,string nazwisko,int & ID_autora,  Autor * tablica_autorow, int & ile_autorow){
    Autor autor = create_autor(imie, ile_imion, nazwisko, ID_autora, tablica_autorow, ile_autorow);
    Autor* tablica_autorow_pom = new Autor[ile_autorow];
    for(int i=0;i<ile_autorow;i++) tablica_autorow_pom[i]=tablica_autorow[i];
    tablica_autorow_pom[ile_autorow] = autor;
    ile_autorow++;
    delete [] tablica_autorow;
    Autor* tablica_autorow = tablica_autorow_pom;
}





Book create_book(string tytul, Autor autor, string ISBN, string wydawnictwo, int rok_wydania, string seria_wydawnicza, int & Id_ksiazek){
    Book ksiazka = {tytul, autor, ISBN, wydawnictwo, rok_wydania, seria_wydawnicza, Id_ksiazek};
    Id_ksiazek++;
    return ksiazka;
}

void add_book(string tytul, Autor autor, string ISBN, string wydawnictwo, int rok_wydania, string seria_wydawnicza,Book ksiazka, Book* tablica_ksiazek,int & ile_ksiazek,int & Id_ksiazek, bool* tablica_ksiazek_wypozyczonych) {
    Book ksiazka = create_book(tytul, autor, ISBN, wydawnictwo,rok_wydania,seria_wydawnicza, Id_ksiazek);
    Book* tablica_ksiazek_pom = new Book [ile_ksiazek];
    bool* tablica_ksiazek_wypozyczonych_pom = new bool [ile_ksiazek];
    for(int i=0;i<ile_ksiazek;i++) {
        tablica_ksiazek_pom[i]=tablica_ksiazek[i];
        tablica_ksiazek_wypozyczonych_pom[i] = tablica_ksiazek_wypozyczonych[i];
    }
    tablica_ksiazek_pom[ile_ksiazek] = ksiazka;
    tablica_ksiazek_wypozyczonych_pom[ile_ksiazek] = false;
    ile_ksiazek++;
    delete [] tablica_ksiazek;
    delete [] tablica_ksiazek_wypozyczonych;
    Book* tablica_ksiazek = tablica_ksiazek_pom;
    bool* tablica_ksiazek_wypozyczonych = tablica_ksiazek_wypozyczonych_pom;
}

void delete_book(Book ksiazka, Book *tablica_ksiazek, int & ile_ksiazek, bool* tablica_ksiazek_wypozyczonych) {
    for (int i=0; i<ile_ksiazek;i++){
        if (tablica_ksiazek[i].ID_ksiazek == ksiazka.ID_ksiazek) {
            Book* tablica_ksiazek_pom = new Book[ile_ksiazek-1];
            bool* tablica_ksiazek_wypozyczonych_pom = new bool[ile_ksiazek-1];
            for (int j=0;j<ile_ksiazek;j++){
                if (i==j) {
                    tablica_ksiazek_pom ++;
                    tablica_ksiazek_wypozyczonych_pom ++;
                }
                *tablica_ksiazek_pom = tablica_ksiazek[j];
                *tablica_ksiazek_wypozyczonych_pom = tablica_ksiazek_wypozyczonych[j];
                tablica_ksiazek_pom++;
                tablica_ksiazek_wypozyczonych_pom++;
            }
            delete [] tablica_ksiazek;
            delete [] tablica_ksiazek_wypozyczonych;
            Book* tablica_ksiazek = tablica_ksiazek_pom;
            bool* tablica_ksiazek_wypozyczonych = tablica_ksiazek_wypozyczonych_pom;
            ile_ksiazek--;
            cout << "Pomyslnie usunieto ksiazke" << endl;
            return;
        }
    }
    cout<<"Nie znaleziono takiej ksiazki " << endl;
}

Osoba create_person(string * imie, int ile_imion, string nazwisko, Adres adres, int & ID_klienta){
    Osoba klient = {imie, ile_imion, nazwisko, adres, ID_klienta};
    ID_klienta++;
    return klient;
}

void add_person(string * imie, int ile_imion, string nazwisko, Adres adres, int & ID_klienta, int & ile_klientow, Osoba* tablica_kilentow){
    
    Osoba* tablica_klientow_pom = new Osoba [ile_klientow];
    for(int i=0;i<ile_klientow;i++) tablica_klientow_pom[i]=tablica_kilentow[i];
    tablica_klientow_pom[ile_klientow] = create_person(imie,ile_imion,nazwisko,adres, ID_klienta);
    ile_klientow++;
    delete [] tablica_kilentow;
    Osoba* tablica_klientow = tablica_klientow_pom;
}



Book *find_by_autor(Book* tablica_ksiazek, int ile_ksiazek, Autor autor)
{
    int pom1=0;
    for(int i=0; i<=ile_ksiazek;i++){
        if (tablica_ksiazek[i].autor.ID_autora == autor.ID_autora)  pom1++;
    }
    Book *print = new Book [pom1];
    int pom2=0;
    for(int i=0; i<=ile_ksiazek;i++){
        if (tablica_ksiazek[i].autor.ID_autora == autor.ID_autora){
            print[pom2] = tablica_ksiazek [i];
            pom2++;
        }
    }
    return print;
}

Book find_by_title(string title, int ile_ksiazek, Book* tablica_ksiazek){
    for(int i=0; i<=ile_ksiazek;i++){
        if (tablica_ksiazek[i].tytul == title) return tablica_ksiazek[i];
    }
}

Book *find_by_print(string wydawnictwo, int ile_ksiazek, Book* tablica_ksiazek){
    int pom=0;
    for(int i=0; i<=ile_ksiazek;i++){
        if (tablica_ksiazek[i].seria_wydawnicza == wydawnictwo)  pom++;
    }
    if (pom == 0) cout<<"Nie znalezlismy zadnych pasujacych wynikow "<<  endl;
    else
    {
        Book *print = new Book [pom];
        for(int i=0; i<=ile_ksiazek;i++){
            if (tablica_ksiazek[i].seria_wydawnicza == wydawnictwo){
                *print = tablica_ksiazek[i];
                print++;
            }
        }
        return print;
    }
}






void wypozycz(Book ksiazka, Book *tablica_ksiazek, bool* tablica_ksiazek_wypozyczonych, int ile_ksiazek) {
    for (int i=0; i<ile_ksiazek;i++){
        if (ksiazka.ID_ksiazek == tablica_ksiazek[i].ID_ksiazek) {
            if (tablica_ksiazek_wypozyczonych[i] != true) {
                tablica_ksiazek_wypozyczonych[i] = true;
                cout << "Wypozyczono pomyslnie " << endl;
                return;
            }
            else {
                cout << "Ksiazka zostala juz wyporzyczona " << endl;
                return;
            }
        }
    }
    cout<<"Nie znalezlismy takiej ksiazki "<<  endl;
}

void zwroc(Book ksiazka, Book *tablica_ksiazek, bool* tablica_ksiazek_wypozyczonych, int ile_ksiazek) {
    for (int i=0; i<ile_ksiazek;i++){
        if (ksiazka.ID_ksiazek == tablica_ksiazek[i].ID_ksiazek) {
            if (tablica_ksiazek_wypozyczonych[i] == true) {
                tablica_ksiazek_wypozyczonych[i] = false;
                cout << "Zwrocono pomyslnie " << endl;
                return;
            }
            else {
                cout << "Ksiazka nie zostala wypozyczona " << endl;
                return;
            }
        }
    }
    cout<<"Nie znalezlismy takiej ksiazki "<<  endl;
}



int main(void){
    int ID_autora = 0, ile_autorow=0, Id_ksiazek=0, ile_ksiazek = 0, Id_klienta = 0, ile_klientow=0;
    Book* tablica_ksiazek = new Book[ile_ksiazek];
    Osoba* tablica_kilentow = new Osoba[ile_klientow];
    Autor* tablica_autorow = new Autor[ile_autorow];
    bool* tablica_ksiazek_wypozyczonych = new bool[ile_ksiazek];
    


}