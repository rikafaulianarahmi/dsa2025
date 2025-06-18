#include <iostream>
#include <string>

using namespace std;

// Definisi struct untuk menyimpan informasi kendaraan
struct Kendaraan {
    string platNomor;
    string jenisKendaraan;
    string namaPemilik;
    string alamat;
    string kota;
};

int main() {
    // Membuat variabel bertipe struct Kendaraan
    Kendaraan kendaraan;

    // Mengisi data kendaraan
    kendaraan.platNomor = "DA1234MK";
    kendaraan.jenisKendaraan = "RUSH";
    kendaraan.namaPemilik = "Andika Hartanto";
    kendaraan.alamat = "Jl. Kayu Tangi 1";
    kendaraan.kota = "Banjarmasin";

    // Menampilkan informasi kendaraan
    cout << "Plat Nomor Kendaraan : " << kendaraan.platNomor << endl;
    cout << "Jenis Kendaraan      : " << kendaraan.jenisKendaraan << endl;
    cout << "Nama Pemilik         : " << kendaraan.namaPemilik << endl;
    cout << "Alamat               : " << kendaraan.alamat << endl;
    cout << "Kota                 : " << kendaraan.kota << endl;

    return 0;
}