#include "header_103012400161.hpp"
#include <iostream>
#include <string>
using namespace std;

struct infotypeGuru {
    string NIP;
    string nama;
    string bidang;
    int totalJamAjar;
};

typedef struct elmGuru *adrGuru;

struct elmGuru {
    infotypeGuru info;
    adrGuru prev;
    adrGuru next;
    addressMP MataPelajaranPertama;
};

struct ListGuru {
    adrGuru first;
    adrGuru last;
};

void createListGuru(ListGuru &L);
adrGuru createElmGuru(infotypeGuru x);
void insertFirstGuru(ListGuru &L, adrGuru P);
void insertLastGuru(ListGuru &L, adrGuru P);
void insertSortedGuru(ListGuru &L, adrGuru P);  // insert berdasarkan NIP
void deleteFirstGuru(ListGuru &L, adrGuru &P);
void deleteLastGuru(ListGuru &L, adrGuru &P);
void deleteGuru(ListGuru &L, string NIP, adrGuru &P);
adrGuru findGuru(ListGuru L, string NIP);
void showAllGuru(ListGuru L);
void showAllData(ListGuru L);  // show guru beserta mata pelajarannya
int countGuru(ListGuru L);

// Fungsi Relasi antara Guru dan Mata Pelajaran
void addMatpelToGuru(ListGuru &L, string NIP, infotypeMP dataMatpel);
void removeMatpelFromGuru(ListGuru &L, string NIP, string kodeMatpel);
void hitungTotalJam(ListGuru &L);  // hitung total jam mengajar semua guru

// Fungsi Komputasi dan Pencarian
adrGuru findGuruWithMostMatpel(ListGuru L);  // komputasi 1: guru dgn mapel terbanyak
adrGuru findGuruWithMostJam(ListGuru L);     // komputasi 2: guru dgn jam terbanyak
void showAllMatpelUnique(ListGuru L);        // show semua mapel unik
void showGuruByBidang(ListGuru L, string bidang);  // pencarian berdasarkan bidang
addressMP findMatpelByKode(ListGuru L, string kodeMapel); 
