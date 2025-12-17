#include "header.h"

addressMP createElemenMataPelajaran(infotypeMP x) {
    addressMP p = new elmListMatPel;
    p->infoMP = x;
    p->nextMP = NULL;
    p->prevMP = NULL;
    return p;
}

void insertFirstMataPelajaran(addressMP &MataPelajaranPertama, addressMP p) {
    if (MataPelajaranPertama == NULL) {
        MataPelajaranPertama = p;
    } else {
        p->nextMP = MataPelajaranPertama;
        MataPelajaranPertama->prevMP = p;
        MataPelajaranPertama = p;
    }
}

void insertLastMataPelajaran(addressMP &MataPelajaranPertama, addressMP p) {
    if (MataPelajaranPertama == NULL) {
        MataPelajaranPertama = p;
    } else {
        addressMP last = MataPelajaranPertama;
        while (last->nextMP != NULL) {
            last = last->nextMP;
        }
        last->nextMP = p;
        p->prevMP = last;
    }
}

void insertAfterMataPelajaran(addressMP &MataPelajaranPertama, addressMP prec, addressMP p) {
    if (prec != NULL) {
        p->nextMP = prec->nextMP;
        p->prevMP = prec;
        if (prec->nextMP != NULL) {
            prec->nextMP->prevMP = p;
        }
        prec->nextMP = p;
    }
}

void deleteFirstMataPelajaran(addressMP &MataPelajaranPertama, addressMP &p) {
    p = MataPelajaranPertama;
    if (MataPelajaranPertama != NULL) {
        if (MataPelajaranPertama->nextMP == NULL) {
            MataPelajaranPertama = NULL;
        } else {
            MataPelajaranPertama = MataPelajaranPertama->nextMP;
            MataPelajaranPertama->prevMP = NULL;
            p->nextMP = NULL;
        }
    }
}

void deleteLastMataPelajaran(addressMP &MataPelajaranPertama, addressMP &p) {
    p = MataPelajaranPertama;
    if (MataPelajaranPertama != NULL) {
        if (MataPelajaranPertama->nextMP == NULL) {
            MataPelajaranPertama = NULL;
        } else {
            addressMP last = MataPelajaranPertama;
            while (last->nextMP != NULL) {
                last = last->nextMP;
            }
            p = last;
            last->prevMP->nextMP = NULL;
            p->prevMP = NULL;
        }
    }
}

void deleteAfterMataPelajaran(addressMP &MataPelajaranPertama, addressMP prec, addressMP &p) {
    if (prec != NULL && prec->nextMP != NULL) {
        p = prec->nextMP;
        prec->nextMP = p->nextMP;
        if (p->nextMP != NULL) {
            p->nextMP->prevMP = prec;
        }
        p->nextMP = NULL;
        p->prevMP = NULL;
    } else {
        p = NULL;
    }
}

addressMP cariMataPelajaran(addressMP MataPelajaranPertama, string kode_mapel) {
    addressMP p = MataPelajaranPertama;
    while (p != NULL) {
        if (p->infoMP.kode_mapel == kode_mapel) {
            return p;
        }
        p = p->nextMP;
    }
    return NULL;
}

void showMataPelajaran(addressMP MataPelajaranPertama) {
    if (MataPelajaranPertama == NULL) {
        cout << "   (Belum ada mata pelajaran)" << endl;
    } else {
        addressMP p = MataPelajaranPertama;
        int i = 1;
        while (p != NULL) {
            cout << "   " << i << ". [" << p->infoMP.kode_mapel << "] "
                 << p->infoMP.bidang_studi_mapel << " - Kelas " << p->infoMP.kelas_mapel
                 << " (" << p->infoMP.jumlah_jam << " jam)" << endl;
            p = p->nextMP;
            i++;
        }
    }
}

void showGuruWIthTheSameMapel(ListGuru L){
    adrGuru p_now = L.first;

    cout << "\n=== Guru Dengan Mapel Yang Sama ===" << endl;
    while (p_now->next != nullptr) {
        addressMP pMP_now = p_now->MataPelajaranPertama;
        while(pMP_now != nullptr){
            adrGuru p_chek = p_now->next;
            while(p_chek != nullptr){
                addressMP pMP_chek = p_chek->MataPelajaranPertama;
                while(pMP_chek != nullptr){
                    if (pMP_now->infoMP.bidang_studi_mapel == pMP_chek->infoMP.bidang_studi_mapel) {
                        cout << "Mapel  : " << pMP_now->infoMP.bidang_studi_mapel << endl;
                        cout << "Guru 1 : " << p_now->info.nama  << endl;
                        cout << "Guru 2 : " << p_chek->info.nama << endl;
                        cout << "===================================" << endl;
                    }
                    pMP_chek = pMP_chek->nextMP;
                }
                p_chek = p_chek->next;
            }
            pMP_now = pMP_now->nextMP;
        }
        p_now = p_now->next;
    }
}
