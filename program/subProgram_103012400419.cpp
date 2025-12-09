#include "header_103012400419.hpp"

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
    p->MataPelajaran = NULL;
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
    
    // Hapus semua mata pelajaran yang diajar
    while (P->MataPelajaran != NULL) {
        addressMP tempMP;
        deleteFirstMataPelajaran(P->MataPelajaran, tempMP);
        delete tempMP;
    }
    
    // Hapus guru dari list
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
        cout << "   Jumlah Mata Pelajaran: " << countMataPelajaran(p->MataPelajaran) << endl;
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
        showMataPelajaran(p->MataPelajaran);
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

// Tambah mata pelajaran ke guru
void addMatpelToGuru(ListGuru &L, string NIP, infotypeMP dataMatpel) {
    adrGuru guru = findGuru(L, NIP);
    if (guru == NULL) {
        cout << "Guru dengan NIP " << NIP << " tidak ditemukan." << endl;
        return;
    }
    
    // Cek apakah mata pelajaran sudah ada
    if (cariMataPelajaran(guru->MataPelajaran, dataMatpel.kode_mapel) != NULL) {
        cout << "Mata pelajaran dengan kode " << dataMatpel.kode_mapel 
             << " sudah diajar oleh guru ini." << endl;
        return;
    }
    
    addressMP newMapel = createElemenMataPelajaran(dataMatpel);
    insertLastMataPelajaran(guru->MataPelajaran, newMapel);
    guru->info.totalJamAjar += dataMatpel.jumlah_jam;
    
    cout << "Mata pelajaran berhasil ditambahkan ke guru " << guru->info.nama << endl;
}

// Hapus mata pelajaran dari guru
void removeMatpelFromGuru(ListGuru &L, string NIP, string kodeMatpel) {
    adrGuru guru = findGuru(L, NIP);
    if (guru == NULL) {
        cout << "Guru dengan NIP " << NIP << " tidak ditemukan." << endl;
        return;
    }
    
    addressMP mapel = cariMataPelajaran(guru->MataPelajaran, kodeMatpel);
    if (mapel == NULL) {
        cout << "Mata pelajaran dengan kode " << kodeMatpel 
             << " tidak ditemukan pada guru ini." << endl;
        return;
    }
    
    int jamMapel = mapel->infoMP.jumlah_jam;
    addressMP deletedMapel;
    deleteMataPelajaran(guru->MataPelajaran, kodeMatpel, deletedMapel);
    
    if (deletedMapel != NULL) {
        guru->info.totalJamAjar -= jamMapel;
        delete deletedMapel;
        cout << "Mata pelajaran berhasil dihapus dari guru " << guru->info.nama << endl;
    }
}

// Hitung total jam mengajar semua guru (update totalJamAjar)
void hitungTotalJam(ListGuru &L) {
    adrGuru p = L.first;
    while (p != NULL) {
        p->info.totalJamAjar = hitungTotalJamMapel(p->MataPelajaran);
        p = p->next;
    }
    cout << "Total jam mengajar semua guru berhasil diperbarui." << endl;
}

// KOMPUTASI 1: Cari guru dengan mata pelajaran terbanyak
adrGuru findGuruWithMostMatpel(ListGuru L) {
    if (L.first == NULL) return NULL;
    
    adrGuru maxGuru = L.first;
    int maxCount = countMataPelajaran(L.first->MataPelajaran);
    
    adrGuru p = L.first->next;
    while (p != NULL) {
        int count = countMataPelajaran(p->MataPelajaran);
        if (count > maxCount) {
            maxCount = count;
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
        addressMP mapel = p->MataPelajaran;
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
            cout << "   Jumlah Mapel: " << countMataPelajaran(p->MataPelajaran) << endl;
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
        addressMP mapel = cariMataPelajaran(p->MataPelajaran, kodeMapel);
        if (mapel != NULL) {
            return mapel;
        }
        p = p->next;
    }
    return NULL;
}