#ifndef MENUFUGGVENYEK_H_INCLUDED
#define MENUFUGGVENYEK_H_INCLUDED

#include <iostream>
#include <csignal>
#include <string>

#include "film.h"
#include "tarolo.h"
#include "csaladifilm.h"
#include "dokumentumfilm.h"

void menuPontok();
void filmFelvetel(Tarolo& t);
void filmTorol(Tarolo& t);
void filmekListazasa(Tarolo& t);
void filmKeres(Tarolo& t);

bool StringCheck(const std::string& cim);
bool LejatszCheck(int szam);
bool KiadasiEvCheck(int szam);
bool KorhatarCheck(int szam);

#endif // MENUFUGGVENYEK_H_INCLUDED
