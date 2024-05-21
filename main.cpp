#include <iostream>
#include <vector>
#include <string>
#include "Pracownik.h"
#include "Samochod.h"
#include "Wypozyczenie.h"
#include "Klient.h"

int main() {
    //staly pracownik
    Pracownik* pracownik = new Pracownik("Jan", "Kowalski", 123);

    //staly klient do testow
    Klient* klient=new Klient("Klient", "Testowy", "123", 1000);

    //staly samochod ktory zawsze bedzie w katalogu
    Samochod* samochod=new Samochod("Subaru", "Lesnik", 2014, "SUV", true, true, 20, 100);

    //katalog samochodow
    std::vector<Samochod*> listaSamochodow;
    listaSamochodow.push_back(samochod);
    Katalog_samochodowy* katalogSamochodowy=new Katalog_samochodowy(listaSamochodow);


    // TESTY DLA KLASY PRACOWNIK -----------------------------------------------------------

    //test dla funkcji wystawRozliczenieWypozyczenia
    Wypozyczenie wypozyczenie(klient, samochod, 5);
    pracownik->wystawRozliczenieWypozyczenia(wypozyczenie);

    //test dla funkcji wystawRozliczenieRezerwacji
    Rezerwacja rezerwacja(klient, samochod, 3);
    pracownik->wystawRozliczenieRezerwacji(rezerwacja);

    //test dla funkcji dodajSamochod
    Samochod* tempSamochod=new Samochod("Toyota", "Prius", 2000, "Osobowe", true, true, 5, 40);
    pracownik->dodajSamochod(tempSamochod, katalogSamochodowy);

    //test dla funkcji zmienStanPojazdu
    pracownik->zmienStanPojazdu(samochod, false);
    std::cout<<samochod->getStan();

    // KONIEC TESTOW DLA KLASY PRACOWNIK ---------------------------------------------------

    // TESTY DLA KLASY KATALOG_SAMOCHODOWY -------------------------------------------------

    //test wypisania katalogu
    katalogSamochodowy->returnListaSamochodow();
    //dodatkowy test z podanym filtrem
    katalogSamochodowy->returnListaSamochodowPoFiltrach("Dostepne");

    // KONIEC TESTOW DLA KLASY KATALOG_SAMOCHODOWY -----------------------------------------

    // TESTY DLA KLASY KLIENT --------------------------------------------------------------

    Samochod* testWybranySamochod=klient->przegladajSamochody(katalogSamochodowy);
    Rezerwacja* testRezerwacja=klient->rezerwujSamochod(klient, testWybranySamochod, 3);
    klient->poprosORozliczenieRezerwacji(pracownik, testRezerwacja);

    // KONIEC TESTOW DLA KLASY KLIENT ------------------------------------------------------

    return 0;
}
