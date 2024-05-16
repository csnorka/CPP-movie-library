#ifndef DOKUMENTUMFILM_H_INCLUDED
#define DOKUMENTUMFILM_H_INCLUDED

/**
 * \file dokumentumfilm.h
 *
 * A file egy származtatott osztályt tartalmaz,
 * aminek õse a Film osztály.
 *
 */

#include <iostream>
#include <string>

#include "film.h"

///DokumentumFilm osztály
class DokumentumFilm : public Film {
    static const int typeD = 2;
    std::string leiras;
public:

    ///DokumentumFilm konstruktor
    ///@param cim - film címe
    ///@param ido - film lejátszási ideje
    ///@param ev - film kiadási évének száma
    ///@param leiras - a film korhatárát jelöli
    DokumentumFilm(std::string cim = "", int ido = 0, int ev = 0, std::string leiras = "");

    ///A DokumentumFilm osztályhoz tartozó leírást adja vissza
    ///@return string típus
    std::string getLeiras() const;

    ///A leszármaztatott osztályhoz tartozó típust adja vissza
    ///@return int típusú adat
    int getType() const;

    ///Kiirato fuggveny
    ///Kiirja a leszarmaztatott osztalyhoz tartozo adatokat
    void show(std::ostream& os = std::cout);

    ///Dokumentumfilm destruktor
    ~DokumentumFilm();
};

#endif // DOKUMENTUMFILM_H_INCLUDED
