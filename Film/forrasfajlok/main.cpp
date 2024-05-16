#include <iostream>
#include <csignal>
#include <string>

#include "film.h"
#include "tarolo.h"
#include "csaladifilm.h"
#include "dokumentumfilm.h"
#include "menuFuggvenyek.h"
#include "filmtar_teszt.h"
#include "memtrace.h"

int main()
{
    ///Main menü
    menuPontok();
    int bekert = 0;


    try{
        Tarolo t;


        while(std::cin >> bekert){
            switch(bekert){
            case 1:{
                filmFelvetel(t);
                menuPontok();
                break;
            }
            case 2:{
                filmTorol(t);
                menuPontok();
                break;
            }
            case 3:{
                filmekListazasa(t);
                menuPontok();
                break;
            }
            case 4:{
                filmKeres(t);
                menuPontok();
                break;
            }
            case 5:{
                TEST1();
                TEST2();
                menuPontok();
                break;
            }
            case 6:
                return 0;
                break;
            default:{
                std::cout << std::endl;
                std::cout << "Nem letezik ilyen szam! Valassz uj szamot.";
                menuPontok();
                break;
            }
            }
        }
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
