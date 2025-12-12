#include "header.h"

void runMenuAdmin(ListGuru &L) {
    int pilihan = -1;
    string NIP, kodeMapel;
    
    while (pilihan != 0) {
        cout << "\n=== MENU ADMIN (FULL ACCESS) ===" << endl;
        cout << "1. Tambah Guru" << endl;
        cout << "2. Hapus Guru" << endl;
        cout << "3. Tambah Mapel ke Guru" << endl;
        cout << "4. Hapus Mapel dari Guru" << endl;
        cout << "5. Lihat Semua Data (Guru & Mapel)" << endl;
        cout << "6. Hitung Ulang Total Jam Mengajar" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "   --> 1. Insert First (Awal)" << endl;
            cout << "   --> 2. Insert Last (Akhir)" << endl;
            cout << "   --> 3. Insert Sorted (Urut NIP)" << endl;
            cout << "   Pilihan Posisi: ";
            int subPos;
            cin >> subPos;
            
            infotypeGuru dataGuru;
            cout << "   Masukkan NIP: "; cin >> dataGuru.NIP;
            
            if (findGuru(L, dataGuru.NIP) != NULL) {
                cout << "   ERROR: NIP sudah terdaftar!" << endl;
            } else {
                // Input satu kata (tanpa spasi)
                cout << "   Masukkan Nama (Tanpa Spasi): "; cin >> dataGuru.nama;
                cout << "   Masukkan Bidang (Tanpa Spasi): "; cin >> dataGuru.bidang;
                dataGuru.totalJamAjar = 0;
                
                adrGuru P = createElmGuru(dataGuru);
                
                if (subPos == 1) insertFirstGuru(L, P);
                else if (subPos == 2) insertLastGuru(L, P);
                else if (subPos == 3) insertSortedGuru(L, P);
                else cout << "   Posisi tidak valid, guru tidak ditambahkan." << endl;
                
                if (subPos >= 1 && subPos <= 3) cout << "   Sukses menambah guru." << endl;
            }
        }
        else if (pilihan == 2) {
            cout << "   --> 1. Delete First" << endl;
            cout << "   --> 2. Delete Last" << endl;
            cout << "   --> 3. Delete by NIP" << endl;
            cout << "   Pilihan Hapus: ";
            int subDel;
            cin >> subDel;

            adrGuru P = NULL;
            if (subDel == 1) {
                deleteFirstGuru(L, P);
                if (P != NULL) cout << "   Guru pertama dihapus." << endl;
                else cout << "   List Kosong." << endl;
            } 
            else if (subDel == 2) {
                deleteLastGuru(L, P);
                if (P != NULL) cout << "   Guru terakhir dihapus." << endl;
                else cout << "   List Kosong." << endl;
            } 
            else if (subDel == 3) {
                cout << "   Masukkan NIP: "; cin >> NIP;
                deleteGuru(L, NIP, P);
                if (P != NULL) cout << "   Guru dengan NIP " << NIP << " dihapus." << endl;
                else cout << "   Guru tidak ditemukan." << endl;
            }
        }
        else if (pilihan == 3) {
            cout << "Masukkan NIP Guru: "; cin >> NIP;
            
            if (findGuru(L, NIP) == NULL) {
                cout << "Guru tidak ditemukan." << endl;
            } else {
                infotypeMP dataMapel;
                cout << "Kode Mapel: "; cin >> dataMapel.kode_mapel;
                cout << "Nama Mapel (Tanpa Spasi): "; cin >> dataMapel.bidang_studi_mapel;
                cout << "Tingkat (SD/SMP/SMA): "; cin >> dataMapel.tingkat_mapel;
                cout << "Kelas: "; cin >> dataMapel.kelas_mapel;
                cout << "Jam/Minggu (Angka): "; cin >> dataMapel.jumlah_jam;
                
                addMatpelToGuru(L, NIP, dataMapel);
            }
        }
        else if (pilihan == 4) {
            cout << "Masukkan NIP Guru: "; cin >> NIP;
            cout << "Masukkan Kode Mapel: "; cin >> kodeMapel;
            removeMatpelFromGuru(L, NIP, kodeMapel);
        }
        else if (pilihan == 5) {
            showAllData(L);
        }
        else if (pilihan == 6) {
            hitungTotalJam(L);
        }
        else if (pilihan == 0) {
            cout << "Keluar dari Admin..." << endl;
        }
        else {
            cout << "Pilihan salah." << endl;
        }
    }
}