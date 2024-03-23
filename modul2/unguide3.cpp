#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int menu;
    int arr[10];
    bool inputDone = false;

    do {
        // Tampilkan menu
        cout << "MENU" << endl;
        cout << "1. Input Array" << endl;
        cout << "2. Tampil Array" << endl;
        cout << "3. Cari Nilai Minimum" << endl;
        cout << "4. Cari Nilai Maksimum" << endl;
        cout << "5. Hitung Rata-rata" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan 10 bilangan bulat:" << endl;
                for (int i = 0; i < 10; i++) {
                    cout << "Bilangan ke-" << i + 1 << ": ";
                    cin >> arr[i];
                }
                inputDone = true;
                break;

            case 2:
                if (inputDone) {
                    cout << "Isi Array: ";
                    for (int i = 0; i < 10; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Anda belum menginputkan array." << endl;
                }
                break;

            case 3:
                if (inputDone) {
                    int minVal = arr[0];
                    for (int i = 1; i < 10; i++) {
                        if (arr[i] < minVal) {
                            minVal = arr[i];
                        }
                    }
                    cout << "Nilai Minimum: " << minVal << endl;
                } else {
                    cout << "Anda belum menginputkan array." << endl;
                }
                break;

            case 4:
                if (inputDone) {
                    int maxVal = arr[0];
                    for (int i = 1; i < 10; i++) {
                        if (arr[i] > maxVal) {
                            maxVal = arr[i];
                        }
                    }
                    cout << "Nilai Maksimum: " << maxVal << endl;
                } else {
                    cout << "Anda belum menginputkan array." << endl;
                }
                break;

            case 5:
                if (inputDone) {
                    int total = 0;
                    for (int i = 0; i < 10; i++) {
                        total += arr[i];
                    }
                    double rataRata = static_cast<double>(total) / 10;
                    cout << fixed << setprecision(2);
                    cout << "Rata-rata: " << rataRata << endl;
                } else {
                    cout << "Anda belum menginputkan array." << endl;
                }
                break;

            case 6:
                cout << "Terima kasih!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (menu != 6);

    return 0;
}
