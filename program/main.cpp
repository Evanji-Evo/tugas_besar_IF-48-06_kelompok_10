#include "header.h"

// Forward Declaration
void runMenuAdmin(ListGuru &L);
void runMenuUser(ListGuru &L);

int main() {
    ListGuru L;
    createListGuru(L); // Panggil Header

    int pilihan = -1;

    while (pilihan != 0) {
        cout << "\n##########################################" << endl;
        cout << "        APLIKASI DATA GURU & MAPEL        " << endl;
        cout << "##########################################" << endl;
        cout << "1. ADMIN (Full Access - Insert/Delete)" << endl;
        cout << "2. USER (Read Only - Search/View)" << endl;
        cout << "0. EXIT" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            runMenuAdmin(L);
        } else if (pilihan == 2) {
            runMenuUser(L);
        } else if (pilihan == 0) {
            cout << "Terima Kasih." << endl;
        } else {
            cout << "Pilihan salah." << endl;
        }
    }
    return 0;
}
