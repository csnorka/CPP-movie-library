#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include "menuFuggvenyek.h"

bool StringCheck(const std::string& cim){
    if(cim != "") return true;
    else{
        std::cout << "Nem sikerult beolvasni!" << std::endl;
        return false;
    }
}

bool LejatszCheck(int szam){
    if(szam > 0 && szam <= 500) return true;
    else{
        std::cout << "Lejatszasi ido ervenytelen!" << std::endl;
        return false;
    }
}

bool KiadasiEvCheck(int szam){
    if(szam > 0 && szam <= 2023) return true;
    else{
        std::cout << "Kiadasi ev ervenytelen!" << std::endl;
        return false;
    }
}

bool KorhatarCheck(int szam){
    if(szam > 0 && szam <= 21) return true;
    else{
        std::cout << "Korhatar ervenytelen!" << std::endl;
        return false;
    }
}

void menuPontok(){
    std::cout << std::endl;
    std::cout << "1. Uj film felvetele" << std::endl;
    std::cout << "2. Film torlese" << std::endl;
    std::cout << "3. Filmek listazasa" << std::endl;
    std::cout << "4. Film keresese" << std::endl;
    std::cout << "5. Teszt" << std::endl;
    std::cout << "6. Kilepes" << std::endl;
    std::cout << "Valasztott menupont: ";
}

void filmFelvetel(Tarolo& t){
    std::cout << std::endl;
    std::cout << "1. Csaladi film felvetele" << std::endl;
    std::cout << "2. Dokumentum film felvetele" << std::endl;
    std::cout << "3. Egyeb" << std::endl;
    std::cout << "4. Vissza" << std::endl;

    std::cout << "Valasztott menupont: ";
    int szam = 0;
    std::cin >> szam;

    std::string cim = "", leiras = "";
    int lejatsz = 0, kiadev = 0, korhatar = 0;

    switch(szam){
    case 1:{
        std::cout << "Film cime (irj egy .-ot a vegere a beolvasashoz)(max 100 karakter): ";
        std::cin.ignore();
        std::getline(std::cin, cim, '.');
        std::cout << "Film lejatszasi ideje: ";
        std::cin >> lejatsz;
        std::cout << "Film kiadasi eve: ";
        std::cin >> kiadev;
        std::cout << "Film korhatara: ";
        std::cin >> korhatar;
        if(!StringCheck(cim)) {cim = ""; }
        if(!LejatszCheck(lejatsz)) { lejatsz = 0;}
        if(!KiadasiEvCheck(kiadev)) { kiadev = 0;}
        if(!KorhatarCheck(korhatar)) { korhatar = 0;}
        if(!(cim == "" && lejatsz == 0 && kiadev ==0 && korhatar == 0)){
            t.Hozzaad(new CsaladiFilm(std::string(cim), lejatsz, kiadev, korhatar));
            if(t.CimCheck(cim)){
                std::cout << "Sikeres film hozzaadas!" << std::endl;
            }
            else std::cout << "Sikertelen film hozzaadas!" << std::endl;
        }
        else std::cout << "Sikertelen film hozzaadas!" << std::endl;
        break;
    }
    case 2:{
        std::cout << "Film cime (irj egy .-ot a vegere a beolvasashoz)(max 100 karakter): ";
        std::cin.ignore();
        std::getline(std::cin, cim, '.');
        std::cout << "Film lejatszasi ideje: ";
        std::cin >> lejatsz;
        std::cout << "Film kiadasi eve: ";
        std::cin >> kiadev;
        std::cout << "Film leirasa (irj egy .-ot a vegere a beolvasashoz)(max 100 karakter): ";
        std::cin.ignore();
        std::getline(std::cin, leiras, '.');
        if(!StringCheck(cim)) {cim = ""; }
        if(!LejatszCheck(lejatsz)) { lejatsz = 0;}
        if(!KiadasiEvCheck(kiadev)) { kiadev = 0;}
        if(!StringCheck(leiras)) { leiras = "";}
        if(cim != "" && lejatsz != 0 && kiadev !=0 && leiras != ""){
            t.Hozzaad(new DokumentumFilm(std::string(cim), lejatsz, kiadev, std::string(leiras)));
            if(t.CimCheck(cim)){
                std::cout << "Sikeres film hozzaadas!" << std::endl;
            }
            else std::cout << "Sikertelen film hozzaadas!" << std::endl;
        }
        else std::cout << "Sikertelen film hozzaadas!" << std::endl;
        break;
    }
    case 3:{
        std::cout << "Film cime (irj egy .-ot a vegere a beolvasashoz)(max 100 karakter): ";
        std::getline(std::cin, cim, '.');
        std::cout << "Film lejatszasi ideje: ";
        std::cin >> lejatsz;
        std::cout << "Film kiadasi eve: ";
        std::cin >> kiadev;
        if(!StringCheck(cim)) {cim = ""; }
        if(!LejatszCheck(lejatsz)) { lejatsz = 0;}
        if(!KiadasiEvCheck(kiadev)) { kiadev = 0;}
        if(cim != "" && lejatsz != 0 && kiadev != 0){
            t.Hozzaad(new Film(std::string(cim), lejatsz, kiadev));
            if(t.CimCheck(cim)){
                std::cout << "Sikeres film hozzaadas!" << std::endl;
            }
            else std::cout << "Sikertelen film hozzaadas!" << std::endl;
        }
        else std::cout << "Sikertelen film hozzaadas!" << std::endl;
        break;
    }
    case 4:{
        return;
    }
    default:{
        std::cout << "Helytelen szam!" << std::endl;
        break;
    }
    }
}

void filmTorol(Tarolo& t){
    // cim
    std::string cim;
    std::cout << "Film cime (irj egy .-ot a vegere a beolvasashoz): ";
    std::cin.ignore();
    std::getline(std::cin, cim, '.');

    // cim szerint torol
    t.Torol(cim);
}

void filmekListazasa(Tarolo& t){
    // cim szerint

    // lejatszasi ido szerint
    // kiadev szerint
    std::cout << std::endl;
    std::cout << "1. Filmek listazasa" << std::endl;
    std::cout << "2. Lejatszasi ido szerinti listazas" << std::endl;
    std::cout << "3. Kiadasi ev szerinti listazas" << std::endl;
    std::cout << "4. Vissza" << std::endl;

    std::cout << "Valasztott menupont: ";
    int szam, perc, ev;
    std::cin >> szam;

    switch(szam){
    case 1:{
        t.Kiir();
        break;
    }
    case 2:{
        std::cout << "Irj egy lejatszasi idot (perc): ";
        std::cin >> perc;
        t.LejatszIdoSzerintKiir(perc);
        break;
    }
    case 3:{
        std::cout << "Irj egy kiadasi evet: ";
        std::cin >> ev;
        t.KiadEvSzerintKiir(ev);
        break;
    }
    case 4:{
        return;
    }
    default:{
        std::cout << "Helytelen szam!" << std::endl;
        break;
    }
    }
}

void filmKeres(Tarolo& t){
    // cim
    std::string cim;
    std::cout << "Film cime (irj egy .-ot a vegere a beolvasashoz): ";
    std::cin.ignore();
    std::getline(std::cin, cim, '.');
    // cim szerint keres
    t.CimSzerintKiir(cim);
}
