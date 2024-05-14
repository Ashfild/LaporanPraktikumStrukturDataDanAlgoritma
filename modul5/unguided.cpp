#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    int nim;
    int nilai;
};

// Ukuran hash table
const int TABLE_SIZE = 11;

// Class untuk hash table
class HashTable {
private:
    vector<list<Mahasiswa>> table;

    // Fungsi hash sederhana
    int hashFunction(int nim) {
        return nim % TABLE_SIZE;
    }

public:
    // Konstruktor
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    // Menambahkan data mahasiswa baru
    void tambahData(int nim, int nilai) {
        Mahasiswa mhs;
        mhs.nim = nim;
        mhs.nilai = nilai;

        int index = hashFunction(nim);
        table[index].push_back(mhs);
    }

    // Menghapus data mahasiswa berdasarkan NIM
    void hapusData(int nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim == nim) {
                table[index].erase(it);
                break;
            }
        }
    }

    // Mencari data mahasiswa berdasarkan NIM
    void cariByNIM(int nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim == nim) {
                cout << "Data ditemukan: NIM " << it->nim << ", Nilai " << it->nilai << endl;
                return;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    // Mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
    void cariByRange() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                if (it->nilai >= 80 && it->nilai <= 90) {
                    cout << "NIM " << it->nim << ", Nilai " << it->nilai << endl;
                }
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int choice, nim, nilai;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Cari Data Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80 - 90)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                hashTable.tambahData(nim, nilai);
                break;
            case 2:
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> nim;
                hashTable.hapusData(nim);
                break;
            case 3:
                cout << "Masukkan NIM yang akan dicari: ";
                cin >> nim;
                hashTable.cariByNIM(nim);
                break;
            case 4:
                hashTable.cariByRange();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while(choice != 5);

    return 0;
}
