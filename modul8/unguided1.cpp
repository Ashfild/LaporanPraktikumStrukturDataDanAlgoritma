#include <iostream>
#include <algorithm>
using namespace std;

string kalimat;
char cari;

void binarysearch()
{
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = kalimat.length() - 1;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (kalimat[tengah] == cari)
        {
            b_flag = 1;
            break;
        }
        else if (kalimat[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if (b_flag == 1)
        cout << "\n Huruf ditemukan pada posisi ke-" << tengah << endl;
    else
        cout << "\n Huruf tidak ditemukan\n";
}

int main()
{
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);
    cout << "\n Masukkan huruf yang ingin Anda cari: ";
    cin >> cari;
    binarysearch();
    return 0;
}
