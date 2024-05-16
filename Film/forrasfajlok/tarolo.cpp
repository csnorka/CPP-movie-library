/**
 *  \file tarolo.cpp
 *  Tarolo osztály tagfüggvényeinek megvalósítása
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

#include "tarolo.h"
#include "film.h"
#include "csaladifilm.h"
#include "dokumentumfilm.h"

Tarolo::Tarolo() : fdb(0) {

    //File megnyitasa es ellenorzese
    std::ifstream myfile("filmek.txt");
    if (myfile.fail()) {
        throw std::runtime_error("filmek.txt fajllal problema!");
    }

    //Elso sor kiolvasasa es memoria terulet lefoglalasa
    size_t db;
    myfile >> db;
    if(db > 0)
        filmek = new Film*[db];

    //Fajbol olvasas
    std::string line, cim, leiras;
    int type, lejatsz, kiadev, korhatar;

    while (!myfile.fail() && db > 0) {
        std::getline(myfile, line, '-');
        type = std::stoi(line);

        std::getline(myfile, cim, '-');

        std::getline(myfile, line, '-');
        lejatsz = std::stoi(line);

        if(type == 0){
            std::getline(myfile, line, '\n');
            kiadev = std::stoi(line);
            filmek[fdb++] = new Film(std::string(cim), lejatsz, kiadev);
        }
        else if(type == 1){
            std::getline(myfile, line, '-');
            kiadev = std::stoi(line);
            std::getline(myfile, line, '\n');
            korhatar = std::stoi(line);
            filmek[fdb++] = new CsaladiFilm(std::string(cim), lejatsz, kiadev, korhatar);
        }
        else if(type == 2){
            std::getline(myfile, line, '-');
            kiadev = std::stoi(line);
            std::getline(myfile, leiras, '\n');
            filmek[fdb++] = new DokumentumFilm(std::string(cim), lejatsz, kiadev, std::string(leiras));
        }
    }
}


size_t Tarolo::getDb() const{
    return fdb;
}

void Tarolo::Hozzaad(Film* f){
    for(size_t i = 0; i < fdb; i++){
        if(f->getCim() == filmek[i]->getCim()){
            delete f;
            return;
        }
    }
    Film** temp = new Film*[fdb + 1];
    for(size_t i =  0; i < fdb; i++){
        temp[i] = filmek[i];
    }
    temp[fdb] = f;
    if(fdb > 0)
        delete[] filmek;
    filmek = temp;
    fdb++;
}

void Tarolo::Torol(std::string cim){
    for(std::size_t i = 0; i < fdb; i++)
    {
        if(filmek[i]->getCim() == cim)
        {
            Film** tmp;
            if(--fdb > 0){
                tmp = new Film*[fdb];
                size_t tdb = 0;
                for(size_t i = 0; i < fdb + 1; i++)
                {
                    if(filmek[i]->getCim() != cim)
                    {
                        tmp[tdb++] = filmek[i];
                    }
                }
            }
            delete filmek[i];
            delete[] filmek;
            if(fdb != 0)
                filmek = tmp;
            break;
        }
    }
}

void Tarolo::Kiir() const{
    for(size_t i = 0; i < fdb; i++){
        filmek[i]->show();
        std::cout << std::endl;
    }
}

void Tarolo::CimSzerintKiir(std::string cim){
    bool exits = false;
    for(size_t i = 0; i < fdb; i++){
        if(cim == filmek[i]->getCim())
            filmek[i]->show();
            std::cout << std::endl;
            exits = true;
    }
        if(!exits){
        std::cout << "Nincs ilyen cimu film!" << std::endl;
    }
}

void Tarolo::LejatszIdoSzerintKiir(int szam){
    bool exits = false;
    for(size_t i = 0; i < fdb; i++){
        if(szam == filmek[i]->getLejatsz_ido())
            filmek[i]->show();
            std::cout << std::endl;
            exits = true;
    }
    if(!exits){
        std::cout << "Nincs ilyen lejatszasi ideju film!" << std::endl;
    }
}

void Tarolo::KiadEvSzerintKiir(int szam){
    bool exits = false;
    for(size_t i = 0; i < fdb; i++){
        if(szam == filmek[i]->getKiad_ev())
            filmek[i]->show();
            std::cout << std::endl;
            exits = true;
    }
    if(!exits){
        std::cout << "Nincs ilyen kiadasi evu film!" << std::endl;
    }
}

bool Tarolo::CimCheck(std::string cim){
    for(size_t i = 0; i < fdb; i++){
        if(cim == filmek[i]->getCim())
            return true;
    }
    return false;
}

bool Tarolo::LejatszidoCheck(int szam){
    for(size_t i = 0; i < fdb; i++){
        if(szam == filmek[i]->getLejatsz_ido())
            return true;
    }
    return false;
}

bool Tarolo::KiadevCheck(int szam){
    for(size_t i = 0; i < fdb; i++){
        if(szam == filmek[i]->getKiad_ev())
            return true;
    }
    return false;
}

Tarolo::~Tarolo(){
    std::ofstream myfile("filmek.txt");

    myfile << fdb << std::endl;
    for(size_t i = 0; i < fdb; i++){
        myfile << filmek[i]->getType() << "-";
        filmek[i]->show(myfile);
        if(i != fdb-1)
            myfile << std::endl;
        delete filmek[i];
    }
    if(fdb > 0)
        delete[] filmek;
}
