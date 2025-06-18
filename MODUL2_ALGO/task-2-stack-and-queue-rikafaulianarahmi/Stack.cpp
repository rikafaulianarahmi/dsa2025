#include <iostream>
#include <conio.h>  
using namespace std;

#define MAX 10

struct Stack {
    int data[MAX];
    int atas;
};

Stack Tumpuk;

void inisialisasi() {
    Tumpuk.atas = -1;
}

int kosong() {
    return Tumpuk.atas == -1;
}

int penuh() {
    return Tumpuk.atas == MAX - 1;
}

void input(int data) {
    if (!penuh()) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << data << " Masuk ke Stack\n";
    } else {
        cout << "Tumpukan Penuh\n";
    }
}

void hapus() {
    if (!kosong()) {
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Teratas Sudah Terambil\n";
        Tumpuk.atas--;
    } else {
        cout << "Data Kosong\n";
    }
}

void tampil() {
    if (!kosong()) {
        cout << "Isi Stack:\n";
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    } else {
        cout << "Data Kosong\n";
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong!\n";
}

int main() {
    int pilihan, nilai;
    inisialisasi();

    do {
        cout << "\nSTACK\n";
        cout << "===============\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. CETAK STACK\n";
        cout << "4. BERSIHKAN STACK\n";
        cout << "5. QUIT\n";
        cout << "PILIHAN : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                input(nilai);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "Program Selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

        cout << "Tekan tombol apa saja untuk melanjutkan...\n";
        getch();  
    } while (pilihan != 5);

    return 0;
}
