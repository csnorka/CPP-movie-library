/**
 *  \file csaladifilm.cpp
 *  CsaladiFilm osztály tagfüggvényeinek megvalósítása
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "csaladifilm.h"

CsaladiFilm::CsaladiFilm(std::string cimm, int ido, int ev, int korhatarm)
    :Film(cimm, ido, ev), korhatar(korhatarm) {}

int CsaladiFilm::getKorhatar() const{
    return korhatar;
}

int CsaladiFilm::getType() const{
    return typeCs;
}

void CsaladiFilm::show(std::ostream& os){
    os << getCim() << "-" << getLejatsz_ido() << "-" << getKiad_ev() << "-" << getKorhatar();
}

CsaladiFilm::~CsaladiFilm() {}
