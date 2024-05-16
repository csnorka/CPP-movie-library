#ifndef CSALADIFILM_H_INCLUDED
#define CSALADIFILM_H_INCLUDED

/**
 * \file csaladifilm.h
 *
 * A file egy sz�rmaztatott oszt�lyt tartalmaz,
 * aminek �se a Film oszt�ly.
 *
 */

#include <iostream>
#include <string>

#include "film.h"

///CsaladiFilm oszt�ly
class CsaladiFilm : public Film {
    static const int typeCs = 1;
    int korhatar;
public:

    ///CsaladiFilm konstruktor
    ///@param cim - film c�me
    ///@param ido - film lej�tsz�si ideje
    ///@param ev - film kiad�si �v�nek sz�ma
    ///@param korhatar - a film korhat�r�t jel�li
    CsaladiFilm(std::string cim = "", int ido = 0, int ev = 0, int korhatar = 0);

    ///Visszaadja a lesz�rmaztatott oszt�ly plusz adattagj�t, a korhat�rt
    ///@return int t�pus� adat
    int getKorhatar() const;


    ///Visszaadja a Csal�diFilm oszt�lyhoz tartoz� t�pust
    ///@return int t�pus� adat
    int getType() const;

    ///Kiirato fuggveny
    ///Kiirja a leszarmaztatott osztalyhoz tartozo adatokat
    void show(std::ostream& os = std::cout);

    ///CsaladiFilm destruktor
    ~CsaladiFilm();
};

#endif // CSALADIFILM_H_INCLUDED
