#ifndef GURU_H_INCLUDED
#define GURU_H_INCLUDED

#include "matpel.h"
#include <iostream>
#include <string>
using namespace std;

struct infotypeGuru {
    string GuruID;
    string nama;
    string bidang;
    int totalJamAjar;
};

typedef struct elmGuru *adrGuru;

struct elmGuru {
    infotypeGuru info;
    adrGuru prev;
    adrGuru next;
    adrMatpel child;
};

struct ListGuru {
    adrGuru first;
    adrGuru last;
};

void createListGuru(ListGuru &L);
adrGuru createElmGuru(infotypeGuru x);
void insertFirstGuru(ListGuru &L, adrGuru P);
void insertLastGuru(ListGuru &L, adrGuru P);
void deleteFirstGuru(ListGuru &L, adrGuru &P);
void deleteGuru(ListGuru &L, string NIP, adrGuru &P);
adrGuru findGuru(ListGuru L, string NIP);
void showAllData(ListGuru L);
void addMatpelToGuru(ListGuru &L, string NIP, infotypeMatpel dataMatpel);
void removeMatpelFromGuru(ListGuru &L, string NIP, string kodeMatpel);
void hitungTotalJam(ListGuru &L);

#endif // GURU_H_INCLUDED
