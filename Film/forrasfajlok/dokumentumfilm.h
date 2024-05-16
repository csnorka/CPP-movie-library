#ifndef DOKUMENTUMFILM_H_INCLUDED
#define DOKUMENTUMFILM_H_INCLUDED

/**
 * \file dokumentumfilm.h
 *
 * A file egy sz�rmaztatott oszt�lyt tartalmaz,
 * aminek �se a Film oszt�ly.
 *
 */

#include <iostream>
#include <string>

#include "film.h"

///DokumentumFilm oszt�ly
class DokumentumFilm : public Film {
    static const int typeD = 2;
    std::string leiras;
public:

    ///DokumentumFilm konstruktor
    ///@param cim - film c�me
    ///@param ido - film lej�tsz�si ideje
    ///@param ev - film kiad�si �v�nek sz�ma
    ///@param leiras - a film korhat�r�t jel�li
    DokumentumFilm(std::string cim = "", int ido = 0, int ev = 0, std::string leiras = "");

    ///A DokumentumFilm oszt�lyhoz tartoz� le�r�st adja vissza
    ///@return string t�pus
    std::string getLeiras() const;

    ///A lesz�rmaztatott oszt�lyhoz tartoz� t�pust adja vissza
    ///@return int t�pus� adat
    int getType() const;

    ///Kiirato fuggveny
    ///Kiirja a leszarmaztatott osztalyhoz tartozo adatokat
    void show(std::ostream& os = std::cout);

    ///Dokumentumfilm destruktor
    ~DokumentumFilm();
};

#endif // DOKUMENTUMFILM_H_INCLUDED
