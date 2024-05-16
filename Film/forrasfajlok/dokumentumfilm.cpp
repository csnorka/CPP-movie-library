/**
 *  \file dokumentumfilm.cpp
 *  DokumentumFilm osztály tagfüggvényeinek megvalósítása
 */

#include <iostream>
#include <algorithm>

#include "dokumentumfilm.h"

DokumentumFilm::DokumentumFilm(std::string cimm, int ido, int ev, std::string leirasm)
    :Film(cimm, ido, ev), leiras(leirasm) {
}

std::string DokumentumFilm::getLeiras() const{
    return leiras;
}

int DokumentumFilm::getType() const{
    return typeD;
}

void DokumentumFilm::show(std::ostream& os){
    os << this->getCim() << "-" << this->getLejatsz_ido() << "-" << this->getKiad_ev() << "-" << getLeiras();
}

DokumentumFilm::~DokumentumFilm() {}
