#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr;

void tambahDepan() {
    Mahasiswa* baru = new Mahasiswa();
    cout << "Masukkan Nama : ";
    cin >> baru->nama;
    cout << "Masukkan NIM : ";
    cin >> baru->nim;
    baru->next = head;
    head = baru;
    cout << "\nData telah ditambahkan\n\n";
}

void tambahBelakang() {
    Mahasiswa* baru = new Mahasiswa();
    cout << "Masukkan Nama : ";
    cin >> baru->nama;
    cout << "Masukkan NIM : ";
    cin >> baru->nim;
    baru->next = nullptr;
    if (head == nullptr) {
        head = baru;
    } else {
        Mahasiswa* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "\nData telah ditambahkan\n\n";
}

void tambahTengah() {
    Mahasiswa* baru = new Mahasiswa();
    cout << "Masukkan Nama : ";
    cin >> baru->nama;
    cout << "Masukkan NIM : ";
    cin >> baru->nim;
    cout << "Masukkan Posisi : ";
    int pos;
    cin >> pos;
    if (pos == 1) {
        baru->next = head;
        head = baru;
    } else {
        Mahasiswa* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp->next != nullptr) {
                temp = temp->next;
            } else {
                cout << "Posisi tidak valid\n";
                return;
            }
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << "\nData telah ditambahkan\n\n";
}

void ubahDepan() {
    if (head == nullptr) {
        cout << "Linked List kosong\n";
    } else {
        cout << "Masukkan nama baru : ";
        string namaBaru;
        cin >> namaBaru;
        cout << "Masukkan NIM baru : ";
        string nimBaru;
        cin >> nimBaru;
        head->nama = namaBaru;
        head->nim = nimBaru;
        cout << "Data berhasil diubah\n";
    }
}

void ubahBelakang() {
    if (head == nullptr) {
        cout << "Linked List kosong\n";
    } else if (head->next == nullptr) {
        cout << "Masukkan nama baru : ";
        string namaBaru;
        cin >> namaBaru;
        cout << "Masukkan NIM baru : ";
        string nimBaru;
        cin >> nimBaru;
        head->nama = namaBaru;
        head->nim = nimBaru;
        cout << "Data berhasil diubah\n";
    } else {
        Mahasiswa* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cout << "Masukkan nama baru : ";
        string namaBaru;
        cin >> namaBaru;
        cout << "Masukkan NIM baru : ";
        string nimBaru;
        cin >> nimBaru;
        temp->nama = namaBaru;
        temp->nim = nimBaru;
        cout << "Data berhasil diubah\n";
    }
}

void ubahTengah() {
    if (head == nullptr) {
        cout << "Linked List kosong\n";
    } else {
        cout << "Masukkan nama mahasiswa yang ingin diubah : ";
        string namaCari;
        cin >> namaCari;
        Mahasiswa* temp = head;
        bool ditemukan = false;
        while (temp != nullptr) {
            if (temp->nama == namaCari) {
                ditemukan = true;
                break;
            }
            temp = temp->next;
        }
        if (ditemukan) {
            cout << "Masukkan nama baru : ";
            string namaBaru;
            cin >> namaBaru;
            cout << "Masukkan NIM baru : ";
            string nimBaru;
            cin >> nimBaru;
            temp->nama = namaBaru;
            temp->nim = nimBaru;
            cout << "Data berhasil diubah\n";
        } else {
            cout << "Nama mahasiswa tidak ditemukan\n";
        }
    }
}

void hapusDepan() {
    if (head == nullptr) {
        cout << "Linked List kosong\n";
    } else {
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus\n";
    }
}

void hapusBelakang() {
    if (head == nullptr) {
        cout << "Linked List kosong\n";
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Mahasiswa* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    cout << "Data berhasil dihapus\n";
}

void hapusTengah() {
    if (head == nullptr) {
        cout << "Linked List kosong\n";
    } else {
        cout << "Masukkan nama mahasiswa yang ingin dihapus : ";
        string namaCari;
        cin >> namaCari;
        Mahasiswa* temp = head;
        Mahasiswa* prev = nullptr;
        bool ditemukan = false;
        while (temp != nullptr) {
            if (temp->nama == namaCari) {
                ditemukan = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if (ditemukan) {
            if (prev == nullptr) {
                // Hapus data di depan
                head = temp->next;
                delete temp;
            } else {
                prev->next = temp->next;
                delete temp;
            }
            cout << "Data berhasil dihapus\n";
        } else {
            cout << "Nama mahasiswa tidak ditemukan\n";
        }
    }
}

void hapusList() {
    Mahasiswa* temp = head;
    while (temp != nullptr) {
        Mahasiswa* hapus = temp;
        temp = temp->next;
        delete hapus;
    }
    head = nullptr;
    cout << "Linked List berhasil dihapus\n";
}

void tampilkan() {
    if (head == nullptr) {
        cout << "Linked List kosong\n";
    } else {
        cout << "DATA MAHASISWA\n";
        cout << "NAMA\t\tNIM\n";
        Mahasiswa* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << "\t\t" << temp->nim << endl;
            temp = temp->next;
            cout << endl;
        }
    }
}

int main() {
    int choice;
    do {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR\n\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Tampilkan\n";
        cout << "11. Keluar\n";
        cout << "Pilih Operasi : ";
        cin >> choice;
        switch (choice) {
            case 1:
                tambahDepan();                
                break;
            case 2:
                tambahBelakang();
                break;
            case 3:
                tambahTengah();
                break;
            case 4:
                ubahDepan();
                break;
            case 5:
                ubahBelakang();
                break;
            case 6:
                ubahTengah();
                break;
            case 7:
                hapusDepan();
                break;
            case 8:
                hapusBelakang();
                break;
            case 9:
                hapusTengah();
                break;
            case 10:
                tampilkan();
                break;
            case 0:
                cout << "Keluar dari program\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
