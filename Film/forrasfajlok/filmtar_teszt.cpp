/**
 *  \file filmtar_teszt.cpp
 *
 *  Tesztprogram az osztályok mûködésének ellenõrzésére.
 */

#include <iostream>
#include <csignal>
#include <string>

#include "filmtar_teszt.h"
#include "gtest_lite.h"
#include "memtrace.h"

void TEST1(){
    GTINIT(std::cin);

    TEST(Konstruktor, Film){
        Film f("Geek Charming", 94, 2011);
        EXPECT_EQ(std::string("Geek Charming"), f.getCim());
        EXPECT_EQ(94, f.getLejatsz_ido());
        EXPECT_EQ(2011, f.getKiad_ev());
        EXPECT_EQ(0, f.getType());
    }END

    TEST(Konstruktor, CsaladiFilm){
        CsaladiFilm cs("Encanto", 99, 2021, 6);
        EXPECT_EQ(std::string("Encanto"), cs.getCim());
        EXPECT_EQ(99, cs.getLejatsz_ido());
        EXPECT_EQ(2021, cs.getKiad_ev());
        EXPECT_EQ(6, cs.getKorhatar());
        EXPECT_EQ(1, cs.getType());
    }END

    TEST(Konstruktor, DokumentumFilm){
        DokumentumFilm d("Miss Americana", 85, 2020, "Taylor Swift");
        EXPECT_EQ(std::string("Miss Americana"), d.getCim());
        EXPECT_EQ(85, d.getLejatsz_ido());
        EXPECT_EQ(2020, d.getKiad_ev());
        EXPECT_EQ(std::string("Taylor Swift"), d.getLeiras());
        EXPECT_EQ(2, d.getType());
    }END

    GTEND(std::cerr);
}

void TEST2(){
    GTINIT(std::cin);

    TEST(Filmek hozzaadasa, Tarolo){
            Tarolo t;
            t.Hozzaad(new Film("Geek Charming", 94, 2011));
            t.Hozzaad(new CsaladiFilm("Encanto", 99, 2021, 6));
            t.Hozzaad(new DokumentumFilm("Miss Americana", 85, 2020, "Taylor Swift"));

            EXPECT_TRUE(t.CimCheck("Geek Charming"));
            EXPECT_TRUE(t.CimCheck("Encanto"));
            EXPECT_TRUE(t.CimCheck("Miss Americana"));

            EXPECT_FALSE(t.LejatszidoCheck(60));
            EXPECT_TRUE(t.LejatszidoCheck(94));
            EXPECT_TRUE(t.LejatszidoCheck(99));
            EXPECT_TRUE(t.LejatszidoCheck(85));

            EXPECT_TRUE(t.KiadevCheck(2011));
            EXPECT_TRUE(t.KiadevCheck(2021));
            EXPECT_TRUE(t.KiadevCheck(2020));
            EXPECT_FALSE(t.KiadevCheck(2000));
    }END

    TEST(Filmek torlese, Tarolo){
            Tarolo t;
            t.Hozzaad(new Film("Geek Charming", 94, 2011));
            t.Hozzaad(new CsaladiFilm("Encanto", 99, 2021, 6));
            t.Hozzaad(new DokumentumFilm("Miss Americana", 85, 2020, "Taylor Swift"));

            t.Torol("Encanto");
            EXPECT_FALSE(t.CimCheck("Encanto"));
            EXPECT_FALSE(t.LejatszidoCheck(99));
            EXPECT_FALSE(t.KiadevCheck(2021));

            t.Hozzaad(new CsaladiFilm("Encanto", 99, 2021, 6));
            EXPECT_TRUE(t.CimCheck("Encanto"));
            EXPECT_TRUE(t.LejatszidoCheck(99));
            EXPECT_TRUE(t.KiadevCheck(2021));

            t.Torol("Encanto");

            t.Torol("Geek Charming");
            EXPECT_FALSE(t.CimCheck("Geek Charming"));
            EXPECT_FALSE(t.LejatszidoCheck(94));
            EXPECT_FALSE(t.KiadevCheck(2011));

            t.Torol("Miss Americana");
            EXPECT_FALSE(t.CimCheck("Miss Americana"));
            EXPECT_FALSE(t.LejatszidoCheck(85));
            EXPECT_FALSE(t.KiadevCheck(2020));
    }END

    GTEND(std::cerr);
}
