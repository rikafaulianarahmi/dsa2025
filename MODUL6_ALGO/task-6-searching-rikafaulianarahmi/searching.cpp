#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(vector<int> &nums, int target) {
    int counter = 0;
    int lastIndex = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            counter++;
            lastIndex = i;
        }
    }

    if (counter > 0) {
        cout << "Data ditemukan sebanyak " << counter << " kali.\n";
        cout << "Kemunculan terakhir pada indeks ke-" << lastIndex << ".\n";
    } else {
        cout << "Data tidak ditemukan!\n";
    }
}

void binarySearch(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    cout << "Data setelah diurutkan:\n";
    cout << "Data: ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    int kiri = 0, kanan = nums.size() - 1;
    bool ketemu = false;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (nums[tengah] == target) {
            ketemu = true;
            break;
        } else if (target < nums[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu) {
        cout << "Angka ditemukan!" << endl;
    } else {
        cout << "Angka tidak ditemukan!" << endl;
    }
}

void clearScreen() {
    system("cls");
}

void explain() {
    cout << "\n--- PENJELASAN SEQUENTIAL DAN BINARY SEARCHING ---\n\n";

    cout << "[1] SEQUENTIAL SEARCHING:\n";
    cout << "- Juga dikenal sebagai linear search.\n";
    cout << "- Teknik pencarian yang dilakukan dengan memeriksa satu per satu elemen dalam struktur data,\n";
    cout << "  dimulai dari indeks pertama hingga indeks terakhir.\n";
    cout << "- Jika data ditemukan, pencarian bisa dihentikan (jika hanya mencari satu data),\n";
    cout << "  atau dilanjutkan untuk menghitung jumlah kemunculan data tersebut.\n";
    cout << "- Kelebihan:\n";
    cout << "  * Tidak memerlukan data yang sudah diurutkan.\n";
    cout << "  * Sederhana dan mudah diimplementasikan.\n";
    cout << "- Kekurangan:\n";
    cout << "  * Tidak efisien untuk dataset yang sangat besar karena membutuhkan waktu O(n),\n";
    cout << "    di mana n adalah jumlah elemen.\n\n";

    cout << "[2] BINARY SEARCHING:\n";
    cout << "- Merupakan metode pencarian yang jauh lebih efisien dibanding sequential,\n";
    cout << "  namun hanya dapat digunakan pada data yang telah terurut.\n";
    cout << "- Prinsip kerjanya adalah membagi dua (divide and conquer):\n";
    cout << "  * Bandingkan nilai tengah dengan target.\n";
    cout << "  * Jika target < nilai tengah, lanjut ke separuh kiri.\n";
    cout << "  * Jika target > nilai tengah, lanjut ke separuh kanan.\n";
    cout << "- Proses ini terus diulang hingga data ditemukan atau rentang pencarian habis.\n";
    cout << "- Kelebihan:\n";
    cout << "  * Sangat cepat pada data besar dengan waktu pencarian O(log n).\n";
    cout << "- Kekurangan:\n";
    cout << "  * Hanya bisa digunakan jika data sudah diurutkan sebelumnya.\n";
    cout << "  * Proses pengurutan (sorting) dapat memakan waktu tambahan.\n\n";

    cout << "Kesimpulan:\n";
    cout << "- Gunakan Sequential Search jika data belum diurutkan dan pencarian sederhana.\n";
    cout << "- Gunakan Binary Search jika data sudah diurutkan dan efisiensi sangat dibutuhkan.\n";
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums(100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = dist(rng);
                }

                cout << "100 data acak telah dibuat:\n";
                cout << "Data: ";
                for (int val : nums) {
                    cout << val << " ";
                }
                cout << "\n";

                cout << "Masukkan angka yang ingin dicari: ";
                cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = dist(rng);
                }

                cout << size << " data acak telah dibuat:\n";
                cout << "Data: ";
                for (int val : nums) {
                    cout << val << " ";
                }
                cout << "\n";

                cout << "Masukkan angka yang ingin dicari: ";
                cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by Rika Fauliana Rahmi (2410817120017)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}
