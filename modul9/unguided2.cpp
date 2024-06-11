#include <iostream>
#include <vector>

using namespace std;

void inputNamaSimpul(vector<string> &nama_simpul, int jumlah_simpul) {
    cout << "Silahkan masukkan nama simpul:" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nama_simpul[i];
    }
}

void inputBobot(vector<vector<int>> &bobot, const vector<string> &nama_simpul, int jumlah_simpul) {
    cout << "Silahkan masukkan bobot antar simpul:" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << nama_simpul[i] << "-->" << nama_simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }
}

void tampilkanTabelJarak(const vector<string> &nama_simpul, const vector<vector<int>> &bobot, int jumlah_simpul) {
    cout << "\t";
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << nama_simpul[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << nama_simpul[i] << "\t";
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << bobot[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int jumlah_simpul;
    vector<string> nama_simpul;
    vector<vector<int>> bobot;

    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input jumlah simpul\n";
        cout << "2. Input nama simpul\n";
        cout << "3. Input bobot antar simpul\n";
        cout << "4. Tampilkan tabel jarak\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Silahkan masukkan jumlah simpul: ";
                cin >> jumlah_simpul;
                nama_simpul.resize(jumlah_simpul);
                bobot.resize(jumlah_simpul, vector<int>(jumlah_simpul));
                break;
            case 2:
                if (jumlah_simpul == 0) {
                    cout << "Silahkan input jumlah simpul terlebih dahulu!\n";
                } else {
                    inputNamaSimpul(nama_simpul, jumlah_simpul);
                }
                break;
            case 3:
                if (jumlah_simpul == 0) {
                    cout << "Silahkan input jumlah simpul terlebih dahulu!\n";
                } else {
                    inputBobot(bobot, nama_simpul, jumlah_simpul);
                }
                break;
            case 4:
                if (jumlah_simpul == 0) {
                    cout << "Silahkan input jumlah simpul terlebih dahulu!\n";
                } else if (nama_simpul.empty()) {
                    cout << "Silahkan input nama simpul terlebih dahulu!\n";
                } else if (bobot.empty()) {
                    cout << "Silahkan input bobot antar simpul terlebih dahulu!\n";
                } else {
                    tampilkanTabelJarak(nama_simpul, bobot, jumlah_simpul);
                }
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silahkan coba lagi.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
