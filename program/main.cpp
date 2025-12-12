#include "header.h"

void runMenuAdmin(ListGuru &L);
void runMenuUser(ListGuru &L);

int main() {
    ListGuru L;
    createListGuru(L);

    int pilihan = -1;

    while (pilihan != 0) {
        cout << "=====================================\n";
        cout << "      APLIKASI DATA GURU & MAPEL     \n";
        cout << "=====================================\n";
        cout << "  1. Login sebagai Admin\n";
        cout << "  2. Login sebagai User\n";
        cout << "  0. Keluar\n";
        cout << "-------------------------------------\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            runMenuAdmin(L);
        } else if (pilihan == 2) {
            runMenuUser(L);
        } else if (pilihan == 0) {
            cout << "Terima kasih." << endl;
        } else {
            cout << "Pilihan tidak valid.\n" << endl;
        }
    }

    return 0;
}