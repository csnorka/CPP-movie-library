/**
 *  \file film.cpp
 *  Film osztály tagfüggvényeinek megvalósítása
 */
#include <iostream>
#include <algorithm>
#include "film.h"

Film::Film(std::string cimm, int ido, int ev)
    :cim(cimm), lejatsz_ido(ido), kiad_ev(ev) {
        remove(cim.begin(), cim.end(), '-');
}

//Film::Film() {}

std::string Film::getCim()const{
    return cim;
}

int Film::getLejatsz_ido()const{
    return lejatsz_ido;
}

int Film::getKiad_ev()const{
    return kiad_ev;
}

int Film::getType() const{
    return type;
}

void Film::show(std::ostream& os){
    os << getCim() << "-" << getLejatsz_ido() << "-" << getKiad_ev();
}

Film::~Film() {}
