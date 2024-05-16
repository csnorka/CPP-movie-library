#ifndef TAROLO_H_INCLUDED
#define TAROLO_H_INCLUDED

/**
 * \file tarolo.h
 *
 * A file egy tároló osztály valósít meg,
 * amely Film osztályú objektumokat tárol.

 */

#include <string>
#include <iostream>

#include "film.h"
#include "csaladifilm.h"
#include "dokumentumfilm.h"

///Tarolo osztály
class Tarolo {
    Film **filmek;
    size_t fdb;
public:

    ///Tarolo konstruktor
    ///Beolvassa az adatokat a txt fájlból
    ///Ami a txt fájlban megtalálható adat, azokat eltárolja a tárolóban
    Tarolo();

    ///A tároló osztály éppen tárolt elemeinek számát adja vissza
    ///@return size_t típusú adat
    size_t getDb() const;

    ///A paraméterként kapott objektumot beleteszi a tároló tömbjébe
    void Hozzaad(Film* f);

    ///A paraméterként kapott objektumot megkeresi a tömbben és felszabadítja a helyet
    void Torol(std::string cim);

    ///Kiirja a tárolóban található adatokat
    void Kiir() const;

    ///Kiiro fuggveny
    ///Cim szerint listaz
    void CimSzerintKiir(std::string cim);

    ///Kiiro fuggveny
    ///Lejatszasi ido szerint listaz
    void LejatszIdoSzerintKiir(int szam);

    ///Kiiro fuggveny
    ///Kiadasi ev szerint listaz
    void KiadEvSzerintKiir(int szam);

    ///Ellenorzi, hogy a paraméterként kapott cim benne van-e a filmek tárolójában
    ///@return true ha tartalmazza a címet
    bool CimCheck(std::string cim);

    ///Ellenorzi, hogy a paraméterként kapott lejátszási ido
    ///benne van-e a filmek tárolójában
    ///@return true ha tartalmazza a kapott lejatszasi idot
    bool LejatszidoCheck(int szam);

    ///Ellenorzi, hogy a paraméterként kapott kiadási évet
    ///tartalmazza-e a tárolo
    ///@return true ha tartalmazza az évet
    bool KiadevCheck(int szam);

    ///Tároló osztály destruktora
    ///Felszabadítja a tárolóban eltárolt objektumokat
    ~Tarolo();
};

#endif // TAROLO_H_INCLUDED
