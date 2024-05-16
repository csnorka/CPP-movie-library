#ifndef CSALADIFILM_H_INCLUDED
#define CSALADIFILM_H_INCLUDED

/**
 * \file csaladifilm.h
 *
 * A file egy származtatott osztályt tartalmaz,
 * aminek õse a Film osztály.
 *
 */

#include <iostream>
#include <string>

#include "film.h"

///CsaladiFilm osztály
class CsaladiFilm : public Film {
    static const int typeCs = 1;
    int korhatar;
public:

    ///CsaladiFilm konstruktor
    ///@param cim - film címe
    ///@param ido - film lejátszási ideje
    ///@param ev - film kiadási évének száma
    ///@param korhatar - a film korhatárát jelöli
    CsaladiFilm(std::string cim = "", int ido = 0, int ev = 0, int korhatar = 0);

    ///Visszaadja a leszármaztatott osztály plusz adattagját, a korhatárt
    ///@return int típusú adat
    int getKorhatar() const;


    ///Visszaadja a CsaládiFilm osztályhoz tartozó típust
    ///@return int típusú adat
    int getType() const;

    ///Kiirato fuggveny
    ///Kiirja a leszarmaztatott osztalyhoz tartozo adatokat
    void show(std::ostream& os = std::cout);

    ///CsaladiFilm destruktor
    ~CsaladiFilm();
};

#endif // CSALADIFILM_H_INCLUDED
