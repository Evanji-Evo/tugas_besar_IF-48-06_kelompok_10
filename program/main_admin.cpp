#include "header_103012400419.hpp"
#include <iostream>
#include <limits>
using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    ListGuru L;
    createListGuru(L);
    
    int pilihan;
    do {
        clearScreen();
        cout << "╔════════════════════════════════════════╗" << endl;
        cout << "║          MENU ADMIN                    ║" << endl;
        cout << "║      (Full Access Management)          ║" << endl;
        cout << "╚════════════════════════════════════════╝" << endl;
        cout << "\n=== MANAJEMEN GURU ===" << endl;
        cout << "1.  Tambah Guru (Insert First)" << endl;
        cout << "2.  Tambah Guru (Insert Last)" << endl;
        cout << "3.  Tambah Guru (Insert Sorted by NIP)" << endl;
        cout << "4.  Hapus Guru (Delete First)" << endl;
        cout << "5.  Hapus Guru (Delete Last)" << endl;
        cout << "6.  Hapus Guru (Delete by NIP)" << endl;
        
        cout << "\n=== MANAJEMEN MATA PELAJARAN ===" << endl;
        cout << "7.  Tambah Mata Pelajaran ke Guru" << endl;
        cout << "8.  Hapus Mata Pelajaran dari Guru" << endl;
        
        cout << "\n=== TAMPILAN DATA ===" << endl;
        cout << "9.  Lihat Semua Guru" << endl;
        cout << "10. Lihat Semua Data (Guru + Mapel)" << endl;
        cout << "11. Lihat Mata Pelajaran Unik" << endl;
        
        cout << "\n=== KOMPUTASI & UTILITAS ===" << endl;
        cout << "12. Hitung Ulang Total Jam Mengajar" << endl;
        cout << "13. Tampilkan Statistik Sistem" << endl;
        cout << "14. Load Data Dummy (untuk testing)" << endl;
        
        cout << "\n0.  Keluar" << endl;
        cout << "\nPilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case 1: {
                cout << "\n=== TAMBAH GURU (INSERT FIRST) ===" << endl;
                infotypeGuru dataGuru;
                cout << "NIP: "; getline(cin, dataGuru.NIP);
                
                if (findGuru(L, dataGuru.NIP) != NULL) {
                    cout << "ERROR: NIP sudah terdaftar!" << endl;
                    break;
                }
                
                cout << "Nama: "; getline(cin, dataGuru.nama);
                cout << "Bidang: "; getline(cin, dataGuru.bidang);
                dataGuru.totalJamAjar = 0;
                
                adrGuru newGuru = createElmGuru(dataGuru);
                insertFirstGuru(L, newGuru);
                cout << "\n✓ Guru berhasil ditambahkan di posisi pertama!" << endl;
                break;
            }
            
            case 2: {
                cout << "\n=== TAMBAH GURU (INSERT LAST) ===" << endl;
                infotypeGuru dataGuru;
                cout << "NIP: "; getline(cin, dataGuru.NIP);
                
                if (findGuru(L, dataGuru.NIP) != NULL) {
                    cout << "ERROR: NIP sudah terdaftar!" << endl;
                    break;
                }
                
                cout << "Nama: "; getline(cin, dataGuru.nama);
                cout << "Bidang: "; getline(cin, dataGuru.bidang);
                dataGuru.totalJamAjar = 0;
                
                adrGuru newGuru = createElmGuru(dataGuru);
                insertLastGuru(L, newGuru);
                cout << "\n✓ Guru berhasil ditambahkan di posisi terakhir!" << endl;
                break;
            }
            
            case 3: {
                cout << "\n=== TAMBAH GURU (INSERT SORTED BY NIP) ===" << endl;
                infotypeGuru dataGuru;
                cout << "NIP: "; getline(cin, dataGuru.NIP);
                
                if (findGuru(L, dataGuru.NIP) != NULL) {
                    cout << "ERROR: NIP sudah terdaftar!" << endl;
                    break;
                }
                
                cout << "Nama: "; getline(cin, dataGuru.nama);
                cout << "Bidang: "; getline(cin, dataGuru.bidang);
                dataGuru.totalJamAjar = 0;
                
                adrGuru newGuru = createElmGuru(dataGuru);
                insertSortedGuru(L, newGuru);
                cout << "\n✓ Guru berhasil ditambahkan secara terurut!" << endl;
                break;
            }
            
            case 4: {
                cout << "\n=== HAPUS GURU (DELETE FIRST) ===" << endl;
                if (L.first == NULL) {
                    cout << "ERROR: List kosong!" << endl;
                    break;
                }
                
                adrGuru deletedGuru;
                string namaGuru = L.first->info.nama;
                deleteFirstGuru(L, deletedGuru);
                
                if (deletedGuru != NULL) {
                    // Hapus semua mata pelajaran
                    while (deletedGuru->MataPelajaran != NULL) {
                        addressMP tempMP;
                        deleteFirstMataPelajaran(deletedGuru->MataPelajaran, tempMP);
                        delete tempMP;
                    }
                    delete deletedGuru;
                    cout << "\n✓ Guru " << namaGuru << " berhasil dihapus!" << endl;
                }
                break;
            }
            
            case 5: {
                cout << "\n=== HAPUS GURU (DELETE LAST) ===" << endl;
                if (L.first == NULL) {
                    cout << "ERROR: List kosong!" << endl;
                    break;
                }
                
                adrGuru deletedGuru;
                string namaGuru = L.last->info.nama;
                deleteLastGuru(L, deletedGuru);
                
                if (deletedGuru != NULL) {
                    // Hapus semua mata pelajaran
                    while (deletedGuru->MataPelajaran != NULL) {
                        addressMP tempMP;
                        deleteFirstMataPelajaran(deletedGuru->MataPelajaran, tempMP);
                        delete tempMP;
                    }
                    delete deletedGuru;
                    cout << "\n✓ Guru " << namaGuru << " berhasil dihapus!" << endl;
                }
                break;
            }
            
            case 6: {
                cout << "\n=== HAPUS GURU (DELETE BY NIP) ===" << endl;
                string NIP;
                cout << "NIP Guru yang akan dihapus: ";
                getline(cin, NIP);
                
                adrGuru deletedGuru;
                deleteGuru(L, NIP, deletedGuru);
                if (deletedGuru != NULL) {
                    cout << "\n✓ Guru " << deletedGuru->info.nama << " berhasil dihapus!" << endl;
                    delete deletedGuru;
                }
                break;
            }
            
            case 7: {
                cout << "\n=== TAMBAH MATA PELAJARAN KE GURU ===" << endl;
                
                if (L.first == NULL) {
                    cout << "ERROR: Belum ada guru! Tambahkan guru terlebih dahulu." << endl;
                    break;
                }
                
                string NIP;
                cout << "NIP Guru: "; getline(cin, NIP);
                
                adrGuru guru = findGuru(L, NIP);
                if (guru == NULL) {
                    cout << "ERROR: Guru dengan NIP " << NIP << " tidak ditemukan!" << endl;
                    break;
                }
                
                cout << "\n--- Data Guru ---" << endl;
                cout << "Nama: " << guru->info.nama << endl;
                cout << "Bidang: " << guru->info.bidang << endl;
                
                infotypeMP dataMapel;
                cout << "\n--- Input Mata Pelajaran ---" << endl;
                cout << "Kode Mata Pelajaran: "; getline(cin, dataMapel.kode_mapel);
                cout << "Bidang Studi: "; getline(cin, dataMapel.bidang_studi_mapel);
                cout << "Tingkat (SD/SMP/SMA): "; getline(cin, dataMapel.tingkat_mapel);
                cout << "Kelas: "; getline(cin, dataMapel.kelas_mapel);
                cout << "Jumlah Jam/Minggu: "; cin >> dataMapel.jumlah_jam;
                cin.ignore();
                
                addMatpelToGuru(L, NIP, dataMapel);
                break;
            }
            
            case 8: {
                cout << "\n=== HAPUS MATA PELAJARAN DARI GURU ===" << endl;
                string NIP, kodeMapel;
                cout << "NIP Guru: "; getline(cin, NIP);
                
                adrGuru guru = findGuru(L, NIP);
                if (guru == NULL) {
                    cout << "ERROR: Guru dengan NIP " << NIP << " tidak ditemukan!" << endl;
                    break;
                }
                
                cout << "\nMata Pelajaran yang diajar:" << endl;
                showMataPelajaran(guru->MataPelajaran);
                
                cout << "\nKode Mata Pelajaran yang akan dihapus: ";
                getline(cin, kodeMapel);
                
                removeMatpelFromGuru(L, NIP, kodeMapel);
                break;
            }
            
            case 9: {
                showAllGuru(L);
                break;
            }
            
            case 10: {
                showAllData(L);
                break;
            }
            
            case 11: {
                showAllMatpelUnique(L);
                break;
            }
            
            case 12: {
                hitungTotalJam(L);
                break;
            }
            
            case 13: {
                cout << "\n========================================" << endl;
                cout << "           STATISTIK SISTEM" << endl;
                cout << "========================================" << endl;
                cout << "Total Guru: " << countGuru(L) << endl;
                
                int totalMapel = 0;
                int totalJam = 0;
                adrGuru p = L.first;
                while (p != NULL) {
                    totalMapel += countMataPelajaran(p->MataPelajaran);
                    totalJam += p->info.totalJamAjar;
                    p = p->next;
                }
                
                cout << "Total Mata Pelajaran: " << totalMapel << endl;
                cout << "Total Jam Mengajar: " << totalJam << " jam/minggu" << endl;
                
                if (L.first != NULL) {
                    cout << "\n--- Komputasi ---" << endl;
                    
                    adrGuru guruMostMapel = findGuruWithMostMatpel(L);
                    if (guruMostMapel != NULL) {
                        cout << "Guru dengan Mapel Terbanyak: " << guruMostMapel->info.nama 
                             << " (" << countMataPelajaran(guruMostMapel->MataPelajaran) << " mapel)" << endl;
                    }
                    
                    adrGuru guruMostJam = findGuruWithMostJam(L);
                    if (guruMostJam != NULL) {
                        cout << "Guru dengan Jam Terbanyak: " << guruMostJam->info.nama 
                             << " (" << guruMostJam->info.totalJamAjar << " jam/minggu)" << endl;
                    }
                }
                break;
            }
            
            case 14: {
                cout << "\n=== LOADING DATA DUMMY ===" << endl;
                cout << "Memuat data untuk testing..." << endl;
                
                // Data Guru 1
                infotypeGuru g1 = {"G001", "Dr. Ahmad Santoso, M.Pd", "Matematika", 0};
                adrGuru guru1 = createElmGuru(g1);
                insertLastGuru(L, guru1);
                
                infotypeMP m1 = {"MTK101", "Aljabar Linear", "SMA", "10", 4};
                addMatpelToGuru(L, "G001", m1);
                infotypeMP m2 = {"MTK102", "Geometri Analitik", "SMA", "11", 4};
                addMatpelToGuru(L, "G001", m2);
                infotypeMP m3 = {"MTK103", "Kalkulus", "SMA", "12", 6};
                addMatpelToGuru(L, "G001", m3);
                
                // Data Guru 2
                infotypeGuru g2 = {"G002", "Siti Nurhaliza, S.Pd", "Bahasa Indonesia", 0};
                adrGuru guru2 = createElmGuru(g2);
                insertLastGuru(L, guru2);
                
                infotypeMP m4 = {"BIN101", "Sastra Indonesia", "SMA", "10", 4};
                addMatpelToGuru(L, "G002", m4);
                infotypeMP m5 = {"BIN102", "Tata Bahasa", "SMA", "11", 3};
                addMatpelToGuru(L, "G002", m5);
                
                // Data Guru 3
                infotypeGuru g3 = {"G003", "Budi Prasetyo, M.Pd", "Fisika", 0};
                adrGuru guru3 = createElmGuru(g3);
                insertLastGuru(L, guru3);
                
                infotypeMP m6 = {"FIS101", "Mekanika", "SMA", "10", 4};
                addMatpelToGuru(L, "G003", m6);
                infotypeMP m7 = {"FIS102", "Termodinamika", "SMA", "11", 4};
                addMatpelToGuru(L, "G003", m7);
                infotypeMP m8 = {"FIS103", "Elektromagnetik", "SMA", "12", 5};
                addMatpelToGuru(L, "G003", m8);
                infotypeMP m9 = {"FIS104", "Fisika Modern", "SMA", "12", 3};
                addMatpelToGuru(L, "G003", m9);
                
                // Data Guru 4
                infotypeGuru g4 = {"G004", "Dewi Kartika, S.Si", "Kimia", 0};
                adrGuru guru4 = createElmGuru(g4);
                insertLastGuru(L, guru4);
                
                infotypeMP m10 = {"KIM101", "Kimia Dasar", "SMA", "10", 4};
                addMatpelToGuru(L, "G004", m10);
                infotypeMP m11 = {"KIM102", "Kimia Organik", "SMA", "11", 5};
                addMatpelToGuru(L, "G004", m11);
                
                cout << "\n✓ Data dummy berhasil dimuat!" << endl;
                cout << "Total: " << countGuru(L) << " guru dengan berbagai mata pelajaran" << endl;
                break;
            }
            
            case 0:
                cout << "\nTerima kasih! Keluar dari Menu Admin..." << endl;
                break;
                
            default:
                cout << "ERROR: Pilihan tidak valid!" << endl;
        }
        
        if (pilihan != 0) pause();
    } while(pilihan != 0);
    
    return 0;
}