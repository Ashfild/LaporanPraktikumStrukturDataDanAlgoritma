#include <iostream>
using namespace std;

int hitungVokal(string kalimat) {
    int jumlah = 0;
    for (char huruf : kalimat) {
        // Konversi huruf ke huruf kecil untuk pengecekan yang lebih mudah
        char huruf_kecil = tolower(huruf);
        // Cek apakah huruf adalah huruf vokal
        if (huruf_kecil == 'a' || huruf_kecil == 'e' || huruf_kecil == 'i' ||
            huruf_kecil == 'o' || huruf_kecil == 'u') {
            jumlah++;
        }
        // Cek huruf vokal kapital
        else if (huruf == 'A' || huruf == 'E' || huruf == 'I' || huruf == 'O' || huruf == 'U') {
            jumlah++;
        }
    }
    return jumlah;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    
    int jumlah_vokal = hitungVokal(kalimat);
    
    cout << "Jumlah huruf vokal (termasuk kapital) dalam kalimat adalah: " << jumlah_vokal << endl;
    
    return 0;
}
