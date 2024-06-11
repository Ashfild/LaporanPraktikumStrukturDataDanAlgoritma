#include <iostream>
#include <vector>

using namespace std;

int main() {
    int jumlah_simpul;
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlah_simpul;

    vector<string> nama_simpul(jumlah_simpul);
    vector<vector<int>> bobot(jumlah_simpul, vector<int>(jumlah_simpul));

    cout << "Silahkan masukkan nama simpul:" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> nama_simpul[i];
    }

    cout << "Silahkan masukkan bobot antar simpul:" << endl;
    for (int i = 0; i < jumlah_simpul; ++i) {
        for (int j = 0; j < jumlah_simpul; ++j) {
            cout << nama_simpul[i] << "-->" << nama_simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    // Output tabel jarak
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

    return 0;
}
