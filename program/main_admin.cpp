#include "header.h"

void runMenuAdmin(ListGuru &L) {
    int pilihan = -1;
    string NIP, inputString;

    while (pilihan != 0) {
        cout << "\n==========================================" << endl;
        cout << "          MENU ADMIN (FULL ACCESS)        " << endl;
        cout << "==========================================" << endl;
        cout << "1. Manajemen GURU (Insert/Delete)" << endl;
        cout << "2. Manajemen MATA PELAJARAN (Insert/Delete)" << endl;
        cout << "3. Tampilkan Data (Show)" << endl;
        cout << "4. Utilitas (Hitung Jam & Count)" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        clearScreen();

        // --- SUB MENU 1: GURU ---
        if (pilihan == 1) {
            int subGuru = -1;
            while (subGuru != 0) {
                showAllGuru(L);
                cout << "\n\n   --- MANAJEMEN GURU ---" << endl;
                cout << "   1. Insert First Guru" << endl;
                cout << "   2. Insert Last Guru" << endl;
                cout << "   3. Insert Sorted Guru (By NIP)" << endl;
                cout << "   4. Delete First Guru" << endl;
                cout << "   5. Delete Last Guru" << endl;
                cout << "   6. Delete Guru By NIP" << endl;
                cout << "   0. Kembali" << endl;
                cout << "   Pilihan Guru: ";
                cin >> subGuru;
                clearScreen();

                if (subGuru >= 1 && subGuru <= 3) {
                    // INPUT DATA GURU
                    infotypeGuru g;
                    cout << "   Masukkan NIP: "; cin >> g.NIP;
                    if (findGuru(L, g.NIP) != NULL) {
                        cout << "   [!] Error: NIP sudah ada." << endl;
                    } else {
                        cout << "   Nama (Ganti spasi dgn _): "; cin >> g.nama;
                        cout << "   Bidang (Ganti spasi dgn _): "; cin >> g.bidang;
                        g.totalJamAjar = 0;
                        adrGuru P = createElmGuru(g);

                        // PEMANGGILAN FUNGSI INSERT HEADER
                        if (subGuru == 1) insertFirstGuru(L, P);
                        else if (subGuru == 2) insertLastGuru(L, P);
                        else if (subGuru == 3) insertSortedGuru(L, P);

                        cout << "   [v] Guru berhasil ditambahkan." << endl;
                    }
                }
                else if (subGuru >= 4 && subGuru <= 6) {
                    adrGuru P = NULL;
                    // PEMANGGILAN FUNGSI DELETE HEADER
                    if (subGuru == 4) {
                        deleteFirstGuru(L, P);
                        if (P != NULL) cout << "   [v] Guru First (" << P->info.nama << ") dihapus." << endl;
                    }
                    else if (subGuru == 5) {
                        deleteLastGuru(L, P);
                        if (P != NULL) cout << "   [v] Guru Last (" << P->info.nama << ") dihapus." << endl;
                    }
                    else if (subGuru == 6) {
                        showAllGuru(L);
                        cout << "   Masukkan NIP yg dihapus: "; cin >> inputString;
                        deleteGuru(L, inputString, P);
                        if (P != NULL) cout << "   [v] Guru (" << P->info.nama << ") dihapus." << endl;
                    }

                    if (P == NULL) cout << "   [!] Gagal menghapus (List kosong/NIP tidak ketemu)." << endl;
                }
            }
        }

        // --- SUB MENU 2: MATA PELAJARAN ---
        else if (pilihan == 2) {
            if (L.first == NULL) {
                cout << "   [!] Data Guru masih kosong." << endl;
            } else {
                showAllGuru(L);
                cout << "   Masukkan NIP Guru Target: "; cin >> NIP;
                adrGuru P = findGuru(L, NIP);

                if (P == NULL) {
                    cout << "   [!] Guru tidak ditemukan." << endl;
                } else {
                    cout << "\n   --- DATA GURU SAAT INI ---" << endl;
                    cout << "   Guru Terpilih: " << P->info.nama << endl;
                    cout << "   Mapel saat ini:" << endl;
                    showMataPelajaran(P->MataPelajaranPertama);

                    int subMapel = -1;
                    while (subMapel != 0) {
                        
                        cout << "\n   --- MANAJEMEN MAPEL (CHILD) ---" << endl;
                        cout << "   1. Insert First Mapel" << endl;
                        cout << "   2. Insert Last Mapel" << endl;
                        cout << "   3. Insert After Mapel" << endl;
                        cout << "   4. Delete First Mapel" << endl;
                        cout << "   5. Delete Last Mapel" << endl;
                        cout << "   6. Delete After Mapel" << endl;
                        cout << "   0. Selesai/Kembali" << endl;
                        cout << "   Pilihan Mapel: ";
                        cin >> subMapel;
                        clearScreen();
                    
                        addressMP pMapel, prec, deleted;
                        infotypeMP dataM;
                        string kodePrec;

                        if (subMapel >= 1 && subMapel <= 3) {
                            // INPUT DATA MAPEL
                            cout << "   Kode Mapel: "; cin >> dataM.kode_mapel;
                            if (cariMataPelajaran(P->MataPelajaranPertama, dataM.kode_mapel) != NULL) {
                                cout << "   [!] Kode Mapel sudah ada di guru ini." << endl;
                            } else {
                                cout << "   Nama Mapel (_): "; cin >> dataM.bidang_studi_mapel;
                                cout << "   Tingkat: "; cin >> dataM.tingkat_mapel;
                                cout << "   Kelas: "; cin >> dataM.kelas_mapel;
                                cout << "   Jam/Minggu: "; cin >> dataM.jumlah_jam;
                                pMapel = createElemenMataPelajaran(dataM);

                                // PEMANGGILAN FUNGSI INSERT CHILD HEADER
                                if (subMapel == 1) {
                                    insertFirstMataPelajaran(P->MataPelajaranPertama, pMapel);
                                    cout << "   [v] Insert First Mapel sukses." << endl;
                                } else if (subMapel == 2) {
                                    insertLastMataPelajaran(P->MataPelajaranPertama, pMapel);
                                    cout << "   [v] Insert Last Mapel sukses." << endl;
                                } else if (subMapel == 3) {
                                    cout << "\n";
                                    cout << "\n   --- DATA GURU SAAT INI ---" << endl;
                                    cout << "   Guru Terpilih: " << P->info.nama << endl;
                                    cout << "   Mapel saat ini:" << endl;
                                    showMataPelajaran(P->MataPelajaranPertama);

                                    cout << "   Insert SETELAH kode mapel apa? "; cin >> kodePrec;
                                    prec = cariMataPelajaran(P->MataPelajaranPertama, kodePrec);
                                    if (prec != NULL) {
                                        insertAfterMataPelajaran(P->MataPelajaranPertama, prec, pMapel);
                                        cout << "   [v] Insert After Mapel sukses." << endl;
                                    } else {
                                        cout << "   [!] Kode Predecessor tidak ditemukan." << endl;
                                    }
                                }
                            }
                        }
                        else if (subMapel >= 4 && subMapel <= 6) {
                            deleted = NULL;
                            // PEMANGGILAN FUNGSI DELETE CHILD HEADER
                            if (subMapel == 4) {
                                deleteFirstMataPelajaran(P->MataPelajaranPertama, deleted);
                            } else if (subMapel == 5) {
                                deleteLastMataPelajaran(P->MataPelajaranPertama, deleted);
                            } else if (subMapel == 6) {
                                cout << "\n";
                                cout << "\n";
                                cout << "\n   --- DATA GURU SAAT INI ---" << endl;
                                cout << "   Guru Terpilih: " << P->info.nama << endl;
                                cout << "   Mapel saat ini:" << endl;
                                showMataPelajaran(P->MataPelajaranPertama);
                                
                                cout << "   Hapus mapel SETELAH kode apa? "; cin >> kodePrec;
                                prec = cariMataPelajaran(P->MataPelajaranPertama, kodePrec);
                                if (prec != NULL) {
                                    deleteAfterMataPelajaran(P->MataPelajaranPertama, prec, deleted);
                                } else {
                                    cout << "   [!] Kode Predecessor tidak ditemukan." << endl;
                                }
                            }

                            if (deleted != NULL) {
                                cout << "   [v] Mapel " << deleted->infoMP.bidang_studi_mapel << " berhasil dihapus." << endl;
                            } else {
                                cout << "   [!] Hapus gagal (List kosong/Target salah)." << endl;
                            }
                        }
                    cout << "\n   --- DATA GURU SAAT INI ---" << endl;
                    cout << "   Guru Terpilih: " << P->info.nama << endl;
                    cout << "   Mapel saat ini:" << endl;
                    showMataPelajaran(P->MataPelajaranPertama);
                    }
                }
            }
        }

        // --- SUB MENU 3: VIEW DATA ---
        else if (pilihan == 3) {
            clearScreen();
            adrGuru p;
            cout << "\n   1. Show All Guru (List Saja)" << endl;
            cout << "   2. Show One Guru All Mapel (Satu Guru Semua Mapel)" << endl;
            cout << "   3. Show All Data (Lengkap dengan Mapel)" << endl;
            cout << "   Pilihan: ";
            int subView;
            cin >> subView;
            clearScreen();

            if (subView == 1){
                showAllGuru(L); // Panggil Header
            } else if (subView == 2) {
                string NIP;
                showAllGuru(L);
                cout << "NIP Guru yang mau di tampilkan: "; 
                cin >> NIP;
                showOneGuruAllMapel(L,NIP);
            }else if (subView == 3) showAllData(L); // Panggil Header
        }

        // --- SUB MENU 4: UTILITIES ---
        else if (pilihan == 4) {
            cout << "\n   1. Hitung Jumlah Guru" << endl;
            cout << "   2. Hitung Ulang Total Jam Mengajar" << endl;
            cout << "   Pilihan: ";
            int subUtil;
            cin >> subUtil;

            clearScreen();
            
            if (subUtil == 1) {
                cout << "   Total Guru: " << countGuru(L) << endl; // Panggil Header
            } else if (subUtil == 2) {
                hitungTotalJam(L); // Panggil Header
            }
        }

        else if (pilihan == 0) {
            cout << "Keluar Menu Admin..." << endl;
        }
    }
}
