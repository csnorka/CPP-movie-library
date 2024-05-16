#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

/**
 * \file film.h
 *
 * A file az �soszt�lyt tartalmazza.
 *
 */
#include <iostream>
#include <string>

///Film oszt�ly
class Film{
    static const int type = 0;
    std::string cim;
    int lejatsz_ido;
    int kiad_ev;
public:

    ///Film konstruktor
    ///@param cim - film c�me
    ///@param ido - film lej�tsz�si ideje
    ///@param ev - film kiad�si �v�nek sz�ma
    Film(std::string cim = "", int ido = 0, int ev = 0);

    ///Visszaadja a film c�m�t
    ///@return string t�pus� adat
    std::string getCim() const;

    ///Visszaadja a film lej�tsz�si idej�t (percben)
    ///@return int t�pus� adat
    int getLejatsz_ido() const;

    ///Visszaadja a film kiad�si �v�t (csak �vsz�m)
    ///@return int t�pus� adat
    int getKiad_ev() const;

    ///Visszaadja a film t�pus�t
    ///@return int t�pus� adat
    virtual int getType() const;

    ///Kiirato fuggveny
    ///Kiirja az ososztalyhoz tartozo adatokat
    virtual void show(std::ostream& os = std::cout);

    ///Virtual Film destruktor
    virtual ~Film();
};

#endif // FILM_H_INCLUDED
