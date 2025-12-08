#include <iostream>
#include <string>
using namespace std;

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

struct ListMapel
{
    addressMP firstMP;
    addressMP lastMP;
};

typedef struct elmListMatPel *addressMP;
typedef struct Mata_Pelajaran infotypeMP;

void createListMataPlejaran(ListMapel &L);
addressMP createElemenMataPelajaran(infotypeMP x);
void insertFirstMataPelajaran(ListMapel &L, addressMP p);
void insertLastMataPelajaran(ListMapel &L, addressMP p);
void insertAfterMataPelajaran(ListMapel &L, addressMP prec,addressMP p);
void delateFirstMataPelajaran(ListMapel &L, addressMP p);
void delateLastMataPelajaran(ListMapel &L, addressMP p);
void delateAfterMataPelajaran(ListMapel &L, addressMP prec,addressMP p);
addressMP cariMataPelajaran(ListMapel &L, addressMP search);
void showMataPelajaran(ListMapel &L);


