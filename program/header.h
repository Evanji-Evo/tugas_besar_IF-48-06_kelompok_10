#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
#include <limits>
using namespace std;

typedef struct elmGuru *adrGuru;
typedef struct elmListMatPel *addressMP;
typedef struct Mata_Pelajaran infotypeMP;

//mapel = mata pelajaran
struct Mata_Pelajaran
{   
    string bidang_studi_mapel;
    string kode_mapel;
    string tingkat_mapel;
    string kelas_mapel;
};

struct elmListMatPel
{   
    infotypeMP infoMP;
    addressMP nextMP;
    addressMP prevMP;
};

struct infotypeGuru {
    string NIP;
    string nama;
    string bidang;
    int totalJamAjar;
};


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

addressMP createElemenMataPelajaran(infotypeMP x);
void insertFirstMataPelajaran(adrGuru &MataPelajaranPertama, addressMP p);
void insertLastMataPelajaran(adrGuru &MataPelajaranPertama, addressMP p);
void insertAfterMataPelajaran(adrGuru &MataPelajaranPertama, addressMP prec,addressMP p);
void delateFirstMataPelajaran(adrGuru &MataPelajaranPertama, addressMP p);
void delateLastMataPelajaran(adrGuru &MataPelajaranPertama, addressMP p);
void delateAfterMataPelajaran(adrGuru &MataPelajaranPertama, addressMP prec,addressMP p);
addressMP cariMataPelajaran(adrGuru MataPelajaranPertama,addressMP search);
void showMataPelajaran(adrGuru MataPelajaranPertama);

void menu_primitif();
void menu_unik();
void menu_parents();
void menu_child();
void menu_insert_child();
void menu_delate_child();
void menu_lainnya_child();


#endif // HEADER_H_INCLUDED
