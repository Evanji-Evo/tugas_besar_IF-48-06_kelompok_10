#include"header.h"

int main(){
    while (1){
        int opsiPilihan;
        
        cout << "=====================================\n";
        cout << "           MAIN MENU                 \n";
        cout << "=====================================\n";
        cout << "  1. Kasus Primitif\n";
        cout << "  2. Kasus Unik\n";
        cout << "  0. Keluar\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";

        switch (opsiPilihan)
        {
            case 0 :
                return 0;
            case 1 :
                menu_primitif();
            case 2 :
                menu_unik();
        } 
    }
}
