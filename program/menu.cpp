#include"header.h"

void menu_primitif(){
    int opsiPilihan;
    cout << "=====================================\n";
    cout << "               Primitif              \n";
    cout << "=====================================\n";
    cout << "  1. Data Guru (Parents)\n";
    cout << "  2. Data Mata Pelajaran (Child)\n";
    cout << "  0. Kembali\n";
    cout << "-------------------------------------\n";
    cout << "Enter your choice: ";
    cin >> opsiPilihan;

    switch (opsiPilihan)
    {
        case 0 :
            return;
        case 1 :
            menu_parents();
        case 2 :
            menu_child();
    }
}

void menu_parents(){

}

void menu_child(){
    int opsiPilihan;
    cout << "=====================================\n";
    cout << "            Primitif Child           \n";
    cout << "=====================================\n";
    cout << "  1. Insert Mata Pelajaran\n";
    cout << "  2. Delate Mata Pelajaran\n";
    cout << "  3. Opsi Mata Pelajaran lainnya\n";
    cout << "  0. Kembali\n";
    cout << "-------------------------------------\n";
    cout << "Enter your choice: ";
    cin >> opsiPilihan;

    switch (opsiPilihan)
    {
        case 0 :
            return;
        case 1 :
            menu_insert_child();
        case 2 :
            menu_delate_child();
        case 3 :
            menu_lainnya_child();
    }
}

void menu_insert_child();
void menu_delate_child();
void menu_lainnya_child();

void menu_unik(){

}