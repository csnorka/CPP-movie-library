#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

/**
 * \file film.h
 *
 * A file az õsosztályt tartalmazza.
 *
 */
#include <iostream>
#include <string>

///Film osztály
class Film{
    static const int type = 0;
    std::string cim;
    int lejatsz_ido;
    int kiad_ev;
public:

    ///Film konstruktor
    ///@param cim - film címe
    ///@param ido - film lejátszási ideje
    ///@param ev - film kiadási évének száma
    Film(std::string cim = "", int ido = 0, int ev = 0);

    ///Visszaadja a film címét
    ///@return string típusú adat
    std::string getCim() const;

    ///Visszaadja a film lejátszási idejét (percben)
    ///@return int típusú adat
    int getLejatsz_ido() const;

    ///Visszaadja a film kiadási évét (csak évszám)
    ///@return int típusú adat
    int getKiad_ev() const;

    ///Visszaadja a film típusát
    ///@return int típusú adat
    virtual int getType() const;

    ///Kiirato fuggveny
    ///Kiirja az ososztalyhoz tartozo adatokat
    virtual void show(std::ostream& os = std::cout);

    ///Virtual Film destruktor
    virtual ~Film();
};

#endif // FILM_H_INCLUDED
