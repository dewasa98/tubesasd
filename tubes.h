#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct elmgedung *adrgedung;
typedef struct elmkamar *adrkamar;
typedef struct elmlantai *adrlantai;
typedef struct elmmahasiswa *adrmahasiswa;

struct infogedung
{
    string nama;
};

struct infolantai
{
    int nomorlantai;

};

struct infokamar
{
    int nomorkamar;
    int jumlahpenghuni;
    string status;
};

struct infomahasiswa
{
    string namamhs;
    string nim;
    string jurusan;
};

struct elmmahasiswa
{
    infomahasiswa info;
    adrmahasiswa next;
    adrmahasiswa prev;
};

struct listmahasiswa
{
    adrmahasiswa first;
    adrmahasiswa last;
};

struct elmkamar
{
    infokamar info;
    adrkamar next;
    adrkamar prev;
    listmahasiswa mahasiswa;
};

struct listkamar
{
    adrkamar first;
    adrkamar last;
};

struct elmlantai
{
    infolantai info;
    adrlantai next;
    adrlantai prev;
    listkamar kamar;
};

struct listlantai
{
    adrlantai first;
    adrlantai last;
};

struct elmgedung
{
    infogedung info;
    adrgedung next;
    adrgedung prev;
    listlantai lantai;
};

struct listgedung
{
    adrgedung first;
    adrgedung last;
};

void createlistgedung(listgedung &lg);
void createlistlantai(listlantai &ll);
void createlistkamar(listkamar &lk);
void createlistmahasiswa(listmahasiswa &lm);
adrgedung alokasigedung(infogedung x);
adrlantai alokasilantai(infolantai x);
adrkamar alokasikamar(infokamar x);
adrmahasiswa alokasimahasiswa(infomahasiswa x);
bool gedung_empty(listgedung &l);
bool lantai_empty(listlantai &l);
bool kamar_empty(listkamar &l);
bool mahasiswa_empty(listmahasiswa &l);
void inputgedung(listgedung &l, adrgedung p);
void inputlantai(listlantai &l, adrlantai p);
void inputkamar(listkamar &l, adrkamar p);
void inputmahasiswa(listmahasiswa &l, adrmahasiswa p);
adrgedung find_gedung(listgedung l, infogedung x);
adrlantai find_lantai(listlantai l, infolantai x);
adrkamar find_kamar(listkamar l, infokamar x);
adrmahasiswa find_mahasiswa(listmahasiswa l, infomahasiswa x);
void deletegedung(listgedung &l, string x);
void deletelantai(listlantai &l, int x);
void deletekamar(listkamar &l, int x);
void deletemahasiswa(listmahasiswa &l, string x);
void editgedung(listgedung &l, adrgedung p);
void editlantai(listlantai &l, adrlantai p);
void editkamar(listkamar &l, adrkamar p);
void editmahasiswa(listmahasiswa &l, adrmahasiswa p);
adrmahasiswa searchmahsiswa(string x, listgedung l);
void viewall(listgedung h, listlantai i, listkamar j, listmahasiswa k);
void viewkmrksg(listgedung h, listlantai i, listkamar j, listmahasiswa k);
void viewkmrpnh(listgedung h, listlantai i, listkamar j, listmahasiswa k);
void viewkmrisi(listgedung h, listlantai i, listkamar j, listmahasiswa k);
void pindahmhs(adrmahasiswa s,listgedung h, listlantai i, listkamar j, listmahasiswa k);
int menuView (listgedung h, listlantai i, listkamar j, listmahasiswa k);
#endif // TUBES_H_INCLUDED
