#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int usia;
    string nama;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai, string nama)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->usia = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai, string nama)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->nama = nama;
    baru->usia = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int usia, string nama, int posisi)
{
    if (posisi < 1 || posisi > hitungList() + 1)
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        
        baru->usia = usia;
        baru->nama = nama;

        if (posisi == 1)
        {
            insertDepan(usia, nama);
        }
        else if (posisi == hitungList() + 1)
        {
            insertBelakang(usia, nama);
        }
        else
        {
            // tranversing
            bantu = head;
            int nomor = 1;
            while (nomor < posisi - 1)
            {
                bantu = bantu->next;
                nomor++;
            }
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

// Hapus berdasarkan nama
void hapusNama(string nama)
{
    Node *hapus, *bantu, *bantu2;
    if (isEmpty() == false)
    {
        bantu = head;
        bantu2 = head;
        while (bantu != NULL)
        {
            if (bantu->nama == nama)
            {
                if (bantu == head)
                {
                    hapusDepan();
                    break;
                }
                else if (bantu == tail)
                {
                    hapusBelakang();
                    break;
                }
                else
                {
                    bantu2->next = bantu->next;
                    delete bantu;
                    break;
                }
            }
            bantu2 = bantu;
            bantu = bantu->next;
        }
        if (bantu == NULL)
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Depan
void ubahDepan(int usia, string nama)
{
    if (isEmpty() == false)
    {
        head->usia = usia;
        head->nama = nama;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int usia, string nama, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->usia = usia;
            bantu->nama = nama;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int usia, string nama)
{
    if (isEmpty() == false)
    {
        tail->usia = usia;
        tail->nama = nama;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}


// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    
    {
        cout << "Nama" << " " << "Usia" << endl;
        while (bantu != NULL)
        {
            cout << bantu->nama << " ";
            cout << bantu->usia << " ";
            cout << endl;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Main Program
int main()
{
    init();
    int pilihan, usia, posisi;
    string nama, namaLama;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Masukkan data" << endl;
        cout << "2. Tambah data" << endl;
        cout << "3. Tampilkan data" << endl;
        cout << "4. Ubah data" << endl;
        cout << "5. Hapus data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan usia: ";
            cin >> usia;
            insertBelakang(usia, nama);
            break;
        case 2:
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan usia: ";
            cin >> usia;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            insertTengah(usia, nama, posisi);
            break;
        case 3:
            tampil();
            break;
        case 4:
            cout << "Masukkan nama lama: ";
            cin >> namaLama;
            cout << "Masukkan nama baru: ";
            cin >> nama;
            cout << "Masukkan usia baru: ";
            cin >> usia;
            // Cari posisi nama lama
            Node *bantu;
            bantu = head;
            posisi = 1;
            while (bantu != NULL)
            {
                if (bantu->nama == namaLama)
                {
                    break;
                }
                bantu = bantu->next;
                posisi++;
            }
            ubahTengah(usia, nama, posisi);
            break;
        case 5:
            cout << "Masukkan nama yang akan dihapus: ";
            cin >> nama;
            hapusNama(nama);
            break;
        case 6:
            cout << "Keluar dari program..." << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
        }

    } while (pilihan != 6);

    return 0;
}
