#ifndef TAROLO_H_INCLUDED
#define TAROLO_H_INCLUDED

/**
 * \file tarolo.h
 *
 * A file egy t�rol� oszt�ly val�s�t meg,
 * amely Film oszt�ly� objektumokat t�rol.

 */

#include <string>
#include <iostream>

#include "film.h"
#include "csaladifilm.h"
#include "dokumentumfilm.h"

///Tarolo oszt�ly
class Tarolo {
    Film **filmek;
    size_t fdb;
public:

    ///Tarolo konstruktor
    ///Beolvassa az adatokat a txt f�jlb�l
    ///Ami a txt f�jlban megtal�lhat� adat, azokat elt�rolja a t�rol�ban
    Tarolo();

    ///A t�rol� oszt�ly �ppen t�rolt elemeinek sz�m�t adja vissza
    ///@return size_t t�pus� adat
    size_t getDb() const;

    ///A param�terk�nt kapott objektumot beleteszi a t�rol� t�mbj�be
    void Hozzaad(Film* f);

    ///A param�terk�nt kapott objektumot megkeresi a t�mbben �s felszabad�tja a helyet
    void Torol(std::string cim);

    ///Kiirja a t�rol�ban tal�lhat� adatokat
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

    ///Ellenorzi, hogy a param�terk�nt kapott cim benne van-e a filmek t�rol�j�ban
    ///@return true ha tartalmazza a c�met
    bool CimCheck(std::string cim);

    ///Ellenorzi, hogy a param�terk�nt kapott lej�tsz�si ido
    ///benne van-e a filmek t�rol�j�ban
    ///@return true ha tartalmazza a kapott lejatszasi idot
    bool LejatszidoCheck(int szam);

    ///Ellenorzi, hogy a param�terk�nt kapott kiad�si �vet
    ///tartalmazza-e a t�rolo
    ///@return true ha tartalmazza az �vet
    bool KiadevCheck(int szam);

    ///T�rol� oszt�ly destruktora
    ///Felszabad�tja a t�rol�ban elt�rolt objektumokat
    ~Tarolo();
};

#endif // TAROLO_H_INCLUDED
