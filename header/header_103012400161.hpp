#include "header_103012400419.hpp"
#include <iostream>
#include <string>
using namespace std;

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

addressMP createElemenMataPelajaran(infotypeMP x);
void insertFirstMataPelajaran(adrGuru &MataPelajaranPertama, addressMP p);
void insertLastMataPelajaran(adrGuru &MataPelajaranPertama, addressMP p);
void insertAfterMataPelajaran(adrGuru &MataPelajaranPertama, addressMP prec,addressMP p);
void delateFirstMataPelajaran(adrGuru &MataPelajaranPertama, addressMP p);
void delateLastMataPelajaran(adrGuru &MataPelajaranPertama, addressMP p);
void delateAfterMataPelajaran(adrGuru &MataPelajaranPertama, addressMP prec,addressMP p);
addressMP cariMataPelajaran(adrGuru MataPelajaranPertama,addressMP search);
void showMataPelajaran(adrGuru MataPelajaranPertama);


