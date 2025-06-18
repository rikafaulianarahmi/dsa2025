#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 20
using namespace std;

struct Queue {
    char data[n];
    int front;
    int rear;
};

Queue q;

void Inisialisasi() {
    q.front = -1;
    q.rear = -1;
}

bool isFull() {
    return q.rear == n - 1;
}

bool isEmpty() {
    return q.front == -1 || q.front > q.rear;
}

void INSERT() {
    char huruf;
    if (isFull()) {
        cout << "Queue Penuh!" << endl;
        return;
    }

    cout << "Masukkan Huruf: ";
    cin >> huruf;

    if (isEmpty()) {
        q.front = q.rear = 0;
    } else {
        q.rear++;
    }
    q.data[q.rear] = huruf;
    cout << "Data: " << huruf << " Masuk ke dalam Queue" << endl;
}

void DELETE() {
    if (isEmpty()) {
        cout << "Queue Kosong!" << endl;
        return;
    }
    cout << "Data: " << q.data[q.front] << " Dihapus dari Queue" << endl;
    q.front++;
}

void CETAKLAYAR() {
    if (isEmpty()) {
        cout << "Queue Kosong!" << endl;
        return;
    }

    cout << "Isi Queue:\n";
    for (int i = q.front; i <= q.rear; i++) {
        cout << "Queue ke " << i << " = " << q.data[i] << endl;
    }
}

void RESET() {
    q.front = q.rear = -1;
    cout << "Queue telah di-reset.\n";
}

int main() {
    int PIL;
    char PILIHAN[1];

    Inisialisasi();

    do {
        cout << "QUEUE" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN ANDA : ";
        cin >> PILIHAN;

        PIL = atoi(PILIHAN); // Ubah dari string ke int

        switch (PIL) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            case 4:
                RESET();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }

        cout << "Tekan tombol apa saja untuk melanjutkan..." << endl;
        getch();
        system("cls");

    } while (PIL < 4);

    return 0;
}
