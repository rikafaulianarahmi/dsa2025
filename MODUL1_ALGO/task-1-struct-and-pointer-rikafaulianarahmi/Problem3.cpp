#include <iostream>
using namespace std;

struct UserInput {
    char huruf;
    string kata;
    int angka;
};

int main() {
    UserInput input;
    
    cout << "Masukkan sebuah huruf = ";
    cin >> input.huruf;
    
    cout << "Masukkan sebuah kata = ";
    cin >> input.kata;
    
    cout << "Masukkan sebuah angka = ";
    cin >> input.angka;
    
    cout << "\nHuruf yang Anda masukkan adalah " << input.huruf;
    cout << "\nKata yang Anda masukkan adalah " << input.kata;
    cout << "\nAngka yang Anda masukkan adalah " << input.angka;
    
    return 0;
}
