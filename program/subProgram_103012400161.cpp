#include "header_103012400161.hpp"
#include "header_103012400419.hpp"

void createListMataPlejaran(ListMapel &L){
    L.firstMP = nullptr;
    L.lastMP = nullptr;
}

addressMP createElemenMataPelajaran(infotypeMP x){
    addressMP p = new elmListMatPel;

    p->infoMP = x;
    p->nextMP = nullptr;
    p->prevMP = nullptr;

    return p;

}

void insertFirstMataPelajaran(ListMapel &L, addressMP p){
    if (L.firstMP == nullptr && L.lastMP == nullptr){
        L.firstMP = p;
        L.lastMP = p;
    }else{
        p->nextMP = L.firstMP;
        L.firstMP->prevMP = p;
        L.firstMP = p;
    }
}

void insertLastMataPelajaran(ListMapel &L, addressMP p){
    if (L.firstMP == nullptr && L.lastMP == nullptr){
        L.firstMP = p;
        L.lastMP = p;
    }else{
        p->prevMP = L.lastMP;
        L.lastMP->nextMP = p;
        L.lastMP = p;
    }
}

void insertAfterMataPelajaran(ListMapel &L, addressMP prec,addressMP p){
    addressMP q = prec->nextMP;

    if (prec == nullptr){
        L.firstMP = p;
        L.lastMP = p;
    }else{
        p->nextMP = q;
        p->prevMP = prec;
        q->prevMP = p;
        prec->nextMP = p;
    }
}

void delateFirstMataPelajaran(ListMapel &L, addressMP p){
    if (L.firstMP == nullptr && L.lastMP == nullptr){
        p = nullptr;
    }else if (L.firstMP == L.lastMP)
    {
        p = L.firstMP;
        L.firstMP = nullptr;
        L.lastMP = nullptr;
    }else{
        p = L.firstMP;
        L.firstMP = p->nextMP;
        L.firstMP->prevMP = nullptr;
    }
}

void delateLastMataPelajaran(ListMapel &L, addressMP p){
     if (L.firstMP == nullptr && L.lastMP == nullptr){
        p = nullptr;
    }else if (L.firstMP == L.lastMP)
    {
        p = L.lastMP;
        L.firstMP = nullptr;
        L.lastMP = nullptr;
    }else{
        p = L.lastMP;
        L.lastMP = p->prevMP;
        L.lastMP->nextMP = nullptr;
    }
}

void delateAfterMataPelajaran(ListMapel &L, addressMP prec,addressMP p){
    addressMP q = prec->nextMP;

    if (prec == nullptr){
        p = nullptr;
    }else{
        p = q;
        prec->nextMP = p->nextMP;
        p->nextMP->prevMP = prec;
        p->nextMP = nullptr;
        p->prevMP = nullptr;
    }
}

addressMP cariMataPelajaran(ListMapel &L, addressMP search){
    addressMP p = L.firstMP;

    while(p != nullptr && p != search){
        p = p->nextMP;
    }

    return p;
}

void showMataPelajaran(ListMapel &L){
    addressMP p = L.firstMP;
    int i = 1;

    while(p != nullptr){
        cout << i << ". " << p->infoMP.bidang_studi_mapel << " (" << p->infoMP.kode_mapel <<" )\n";
        cout << "   " << "Kelas: " << p->infoMP.kelas_mapel << " Tingkat: " << p->infoMP.tingkat_mapel << "\n\n";
        p = p->nextMP;
        i++;
    }
}