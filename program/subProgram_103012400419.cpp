#include "header.h"

// Inisialisasi list guru
void createListGuru(ListGuru &L) {
    L.first = NULL;
    L.last = NULL;
}

// Membuat elemen guru baru
adrGuru createElmGuru(infotypeGuru x) {
    adrGuru p = new elmGuru;
    p->info = x;
    p->prev = NULL;
    p->next = NULL;
    // PERBAIKAN: Gunakan MataPelajaranPertama
    p->MataPelajaranPertama = NULL;
    return p;
}

// Insert First (DLL)
void insertFirstGuru(ListGuru &L, adrGuru P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

// Insert Last (DLL)
void insertLastGuru(ListGuru &L, adrGuru P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

// Insert Sorted berdasarkan NIP (ascending)
void insertSortedGuru(ListGuru &L, adrGuru P) {
    if (L.first == NULL || L.first->info.NIP > P->info.NIP) {
        insertFirstGuru(L, P);
    } else if (L.last->info.NIP < P->info.NIP) {
        insertLastGuru(L, P);
    } else {
        adrGuru temp = L.first;
        while (temp->next != NULL && temp->next->info.NIP < P->info.NIP) {
            temp = temp->next;
        }
        P->next = temp->next;
        P->prev = temp;
        temp->next->prev = P;
        temp->next = P;
    }
}

// Delete First (DLL)
void deleteFirstGuru(ListGuru &L, adrGuru &P) {
    if (L.first != NULL) {
        P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = L.first->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    }
}

// Delete Last (DLL)
void deleteLastGuru(ListGuru &L, adrGuru &P) {
    if (L.first != NULL) {
        P = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = L.last->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}

// Delete guru berdasarkan NIP
void deleteGuru(ListGuru &L, string NIP, adrGuru &P) {
    P = findGuru(L, NIP);
    if (P == NULL) {
        cout << "Guru dengan NIP " << NIP << " tidak ditemukan." << endl;
        return;
    }

    // Hapus semua mata pelajaran yang diajar (Child)
    // PERBAIKAN: Gunakan MataPelajaranPertama
    addressMP tempMP;
    while (P->MataPelajaranPertama != NULL) {
        deleteFirstMataPelajaran(P->MataPelajaranPertama, tempMP);
        delete tempMP;
    }

    // Hapus guru dari list (Parent)
    if (P == L.first && P == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else if (P == L.first) {
        L.first = P->next;
        L.first->prev = NULL;
    } else if (P == L.last) {
        L.last = P->prev;
        L.last->next = NULL;
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    P->next = NULL;
    P->prev = NULL;
}

// Cari guru berdasarkan NIP
adrGuru findGuru(ListGuru L, string NIP) {
    adrGuru p = L.first;
    while (p != NULL) {
        if (p->info.NIP == NIP) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
//Tampilkan semua guru saja tanpa matalPelajaran
void showOneGuruAllMapel(ListGuru L, string NIP){
    if (L.first == NULL) {
        cout << "Tidak ada data guru." << endl;
        return;
    }
    adrGuru p = L.first;
    adrGuru q = nullptr;

    while (p != nullptr){
        if (p->info.NIP == NIP){
            q = p;
        }
        p = p->next;
    }

    if (q == nullptr){
        cout << "\nData tersebut kosong";
    }else{
        cout << "\n========================================" << endl;
        cout << "    DAFTAR GURU & MATA PELAJARAN" << endl;
        cout << "========================================" << endl;
        cout << "   NIP    : " << q->info.NIP << endl;
        cout << "   Nama   : " << q->info.nama << endl;
        cout << "   Bidang : " << q->info.bidang << endl;
        cout << "   Total Jam Mengajar: " << q->info.totalJamAjar << " jam/minggu" << endl;
        cout << "   Mata Pelajaran yang Diajar:" << endl;
        // PERBAIKAN: Gunakan MataPelajaranPertama
        showMataPelajaran(q->MataPelajaranPertama);
        cout << "========================================" << endl;
    }
}
// Tampilkan semua guru
void showAllGuru(ListGuru L) {
    if (L.first == NULL) {
        cout << "Tidak ada data guru." << endl;
        return;
    }

    adrGuru p = L.first;
    int no = 1;
    cout << "\n========================================" << endl;
    cout << "           DAFTAR GURU" << endl;
    cout << "========================================" << endl;
    while (p != NULL) {
        cout << no++ << ". NIP    : " << p->info.NIP << endl;
        cout << "   Nama   : " << p->info.nama << endl;
        cout << "   Bidang : " << p->info.bidang << endl;
        cout << "   Total Jam Mengajar: " << p->info.totalJamAjar << " jam/minggu" << endl;
        // PERBAIKAN: Manual count loop karena fungsi countMataPelajaran sudah dihapus/diganti
        int jmlMapel = 0;
        addressMP m = p->MataPelajaranPertama;
        while(m != NULL) { jmlMapel++; m = m->nextMP; }

        cout << "   Jumlah Mata Pelajaran: " << jmlMapel << endl;
        cout << "----------------------------------------" << endl;
        p = p->next;
    }
}

// Tampilkan semua data guru beserta mata pelajarannyaa
void showAllData(ListGuru L) {
    if (L.first == NULL) {
        cout << "Tidak ada data guru." << endl;
        return;
    }

    adrGuru p = L.first;
    int no = 1;
    cout << "\n========================================" << endl;
    cout << "    DAFTAR GURU & MATA PELAJARAN" << endl;
    cout << "========================================" << endl;
    while (p != NULL) {
        cout << no++ << ". NIP    : " << p->info.NIP << endl;
        cout << "   Nama   : " << p->info.nama << endl;
        cout << "   Bidang : " << p->info.bidang << endl;
        cout << "   Total Jam Mengajar: " << p->info.totalJamAjar << " jam/minggu" << endl;
        cout << "   Mata Pelajaran yang Diajar:" << endl;
        // PERBAIKAN: Gunakan MataPelajaranPertama
        showMataPelajaran(p->MataPelajaranPertama);
        cout << "========================================" << endl;
        p = p->next;
    }
}

// Hitung jumlah guru
int countGuru(ListGuru L) {
    int count = 0;
    adrGuru p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

// Hitung total jam mengajar semua guru (update totalJamAjar)
void hitungTotalJam(ListGuru &L) {
    adrGuru p = L.first;
    while (p != NULL) {
        // Hitung manual total jam dari list child
        int total = 0;
        addressMP m = p->MataPelajaranPertama; // PERBAIKAN
        while(m != NULL) {
            total += m->infoMP.jumlah_jam;
            m = m->nextMP;
        }
        p->info.totalJamAjar = total;
        p = p->next;
    }
    cout << "Total jam mengajar semua guru berhasil diperbarui." << endl;
}

// KOMPUTASI 1: Cari guru dengan mata pelajaran terbanyak
adrGuru findGuruWithMostMatpel(ListGuru L) {
    if (L.first == NULL) return NULL;

    adrGuru maxGuru = L.first;
    // Hitung mapel guru pertama
    int maxCount = 0;
    addressMP m = L.first->MataPelajaranPertama;
    while(m != NULL) { maxCount++; m = m->nextMP; }

    adrGuru p = L.first->next;
    while (p != NULL) {
        int currentCount = 0;
        addressMP cm = p->MataPelajaranPertama;
        while(cm != NULL) { currentCount++; cm = cm->nextMP; }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxGuru = p;
        }
        p = p->next;
    }

    return maxGuru;
}

// KOMPUTASI 2: Cari guru dengan jam mengajar terbanyak
adrGuru findGuruWithMostJam(ListGuru L) {
    if (L.first == NULL) return NULL;

    adrGuru maxGuru = L.first;
    int maxJam = L.first->info.totalJamAjar;

    adrGuru p = L.first->next;
    while (p != NULL) {
        if (p->info.totalJamAjar > maxJam) {
            maxJam = p->info.totalJamAjar;
            maxGuru = p;
        }
        p = p->next;
    }

    return maxGuru;
}

// Tampilkan semua mata pelajaran secara unik
void showAllMatpelUnique(ListGuru L) {
    if (L.first == NULL) {
        cout << "Tidak ada data." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "       DAFTAR MATA PELAJARAN UNIK" << endl;
    cout << "========================================" << endl;

    string listedKode[100];
    int countListed = 0;
    int no = 1;

    adrGuru p = L.first;
    while (p != NULL) {
        addressMP mapel = p->MataPelajaranPertama; // PERBAIKAN
        while (mapel != NULL) {
            // Cek apakah sudah ditampilkan
            bool sudahAda = false;
            for (int i = 0; i < countListed; i++) {
                if (listedKode[i] == mapel->infoMP.kode_mapel) {
                    sudahAda = true;
                    break;
                }
            }

            if (!sudahAda) {
                cout << no++ << ". " << mapel->infoMP.kode_mapel
                     << " - " << mapel->infoMP.bidang_studi_mapel
                     << " (" << mapel->infoMP.tingkat_mapel
                     << " - Kelas " << mapel->infoMP.kelas_mapel << ")" << endl;
                cout << "   Diajar oleh: " << p->info.nama << endl;
                cout << "   Jam/minggu: " << mapel->infoMP.jumlah_jam << endl;
                cout << "----------------------------------------" << endl;

                listedKode[countListed++] = mapel->infoMP.kode_mapel;
            }

            mapel = mapel->nextMP;
        }
        p = p->next;
    }

    if (no == 1) {
        cout << "Tidak ada mata pelajaran." << endl;
    }
}

// Tampilkan guru berdasarkan bidang
void showGuruByBidang(ListGuru L, string bidang) {
    if (L.first == NULL) {
        cout << "Tidak ada data guru." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "    GURU BIDANG: " << bidang << endl;
    cout << "========================================" << endl;

    adrGuru p = L.first;
    int no = 1;
    bool found = false;

    while (p != NULL) {
        if (p->info.bidang == bidang) {
            found = true;
            cout << no++ << ". NIP    : " << p->info.NIP << endl;
            cout << "   Nama   : " << p->info.nama << endl;
            cout << "   Total Jam: " << p->info.totalJamAjar << " jam/minggu" << endl;

            int jmlMapel = 0;
            addressMP m = p->MataPelajaranPertama;
            while(m != NULL) { jmlMapel++; m = m->nextMP; }

            cout << "   Jumlah Mapel: " << jmlMapel << endl;
            cout << "----------------------------------------" << endl;
        }
        p = p->next;
    }

    if (!found) {
        cout << "Tidak ada guru dengan bidang " << bidang << endl;
    }
}

// Cari mata pelajaran berdasarkan kode di seluruh system
addressMP findMatpelByKode(ListGuru L, string kodeMapel) {
    adrGuru p = L.first;
    while (p != NULL) {
        addressMP mapel = cariMataPelajaran(p->MataPelajaranPertama, kodeMapel); // PERBAIKAN
        if (mapel != NULL) {
            return mapel;
        }
        p = p->next;
    }
    return NULL;
}
