#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

// --- DEFINISI TIPE DATA ---
typedef struct elmGuru *adrGuru;
typedef struct elmListMatPel *addressMP;
typedef struct Mata_Pelajaran infotypeMP;

struct Mata_Pelajaran {
    string bidang_studi_mapel;
    string kode_mapel;
    string tingkat_mapel;
    string kelas_mapel;
    int jumlah_jam;
};

struct elmListMatPel {
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
    addressMP MataPelajaranPertama; // Pointer ke Child (Mata Pelajaran)
};

struct ListGuru {
    adrGuru first;
    adrGuru last;
};

// --- PRIMITIF GURU (PARENT) ---
void createListGuru(ListGuru &L);
adrGuru createElmGuru(infotypeGuru x);
void insertFirstGuru(ListGuru &L, adrGuru P);
void insertLastGuru(ListGuru &L, adrGuru P);
void insertSortedGuru(ListGuru &L, adrGuru P);
void deleteFirstGuru(ListGuru &L, adrGuru &P);
void deleteLastGuru(ListGuru &L, adrGuru &P);
void deleteGuru(ListGuru &L, string NIP, adrGuru &P);
adrGuru findGuru(ListGuru L, string NIP);
void showAllGuru(ListGuru L);
void showAllData(ListGuru L);
int countGuru(ListGuru L);
void hitungTotalJam(ListGuru &L);

// --- KOMPUTASI ---
adrGuru findGuruWithMostMatpel(ListGuru L);
adrGuru findGuruWithMostJam(ListGuru L);
void showGuruByBidang(ListGuru L, string bidang);
void showAllMatpelUnique(ListGuru L);
addressMP findMatpelByKode(ListGuru L, string kodeMapel);

// --- PRIMITIF MATA PELAJARAN (CHILD) ---
// Fungsi ini yang akan diakses langsung di menu
addressMP createElemenMataPelajaran(infotypeMP x);

// Perhatikan: Parameter pertama adalah addressMP& (Pointer ke Mapel), bukan adrGuru
void insertFirstMataPelajaran(addressMP &MataPelajaranPertama, addressMP p);
void insertLastMataPelajaran(addressMP &MataPelajaranPertama, addressMP p);
void insertAfterMataPelajaran(addressMP &MataPelajaranPertama, addressMP prec, addressMP p);

void deleteFirstMataPelajaran(addressMP &MataPelajaranPertama, addressMP &p);
void deleteLastMataPelajaran(addressMP &MataPelajaranPertama, addressMP &p);
void deleteAfterMataPelajaran(addressMP &MataPelajaranPertama, addressMP prec, addressMP &p);

// Search menggunakan string kode agar bisa dipakai di menu
addressMP cariMataPelajaran(addressMP MataPelajaranPertama, string kode_mapel);
void showMataPelajaran(addressMP MataPelajaranPertama);

#endif // HEADER_H_INCLUDED
