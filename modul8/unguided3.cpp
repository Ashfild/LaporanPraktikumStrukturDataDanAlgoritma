#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 4;
    int jumlah = 0;

    // Algoritma Sequential Search untuk menghitung jumlah angka 4
    for (int i = 0; i < n; i++) {
        if (data[i] == cari) {
            jumlah++;
        }
    }

    cout << "Data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    cout << "Banyaknya angka " << cari << " dalam data adalah: " << jumlah << endl;

    return 0;
}
