#include "header.h"

void runMenuUser(ListGuru &L) {
    int pilihan = -1;
    string inputStr;

    while (pilihan != 0) {
        cout << "\n==========================================" << endl;
        cout << "           MENU USER (READ ONLY)          " << endl;
        cout << "==========================================" << endl;
        cout << "1. Cari Guru (Berdasarkan NIP)" << endl;
        cout << "2. Cari Guru (Berdasarkan Bidang)" << endl;
        cout << "3. Cari Mata Pelajaran (Global Search)" << endl;
        cout << "4. Tampilkan Mata Pelajaran Unik" << endl;
        cout << "5. Statistik Guru (Mapel & Jam Terbanyak)" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan NIP: "; cin >> inputStr;
            adrGuru P = findGuru(L, inputStr); // Panggil Header
            if (P != NULL) {
                cout << "Ditemukan: " << P->info.nama << endl;
                showMataPelajaran(P->MataPelajaranPertama);
            } else cout << "Tidak ditemukan." << endl;
        }
        else if (pilihan == 2) {
            cout << "Masukkan Bidang: "; cin >> inputStr;
            showGuruByBidang(L, inputStr); // Panggil Header
        }
        else if (pilihan == 3) {
            cout << "Masukkan Kode Mapel: "; cin >> inputStr;
            addressMP M = findMatpelByKode(L, inputStr); // Panggil Header
            if (M != NULL) {
                cout << "Mapel Ada: " << M->infoMP.bidang_studi_mapel << endl;
            } else cout << "Mapel tidak ditemukan di guru manapun." << endl;
        }
        else if (pilihan == 4) {
            showAllMatpelUnique(L); // Panggil Header
        }
        else if (pilihan == 5) {
            cout << "--- Statistik Sistem ---" << endl;
            adrGuru gJam = findGuruWithMostJam(L); // Panggil Header
            if (gJam != NULL)
                cout << "Guru Jam Terbanyak: " << gJam->info.nama << " (" << gJam->info.totalJamAjar << " jam)" << endl;

            adrGuru gMapel = findGuruWithMostMatpel(L); // Panggil Header
            if (gMapel != NULL)
                cout << "Guru Mapel Terbanyak: " << gMapel->info.nama << endl;
        }
        else if (pilihan == 0) {
            cout << "Keluar Menu User..." << endl;
        }
    }
}
