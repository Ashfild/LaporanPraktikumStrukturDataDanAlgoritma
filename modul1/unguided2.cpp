#include <iostream>
using namespace std;

// Contoh Struct
struct Mobil{
    string nama,merk, jenis;
    int harga;
};

// Contoh Class
class Pegawai{
    public:
    string nama;
    int nip;
};

int main(){
    
    //Penggunaan Struct
    Mobil toyota_rush, xpander_cross;

    toyota_rush.nama = "Toyota Rush";
    toyota_rush.merk = "Toyota";
    toyota_rush.jenis = "SUV";
    toyota_rush.harga = 282700000;

    xpander_cross.nama = "Xpander Cross";
    xpander_cross.merk = "Xpander";
    xpander_cross.jenis = "Crossover";
    xpander_cross.harga = 316750000;

    cout<<"Nama Mobil : "<< toyota_rush.nama<<endl
        <<"Merk : "<< toyota_rush.merk<<endl
        <<"Jenis : "<< toyota_rush.jenis<<endl
        <<"Harga : Rp."<< toyota_rush.harga<<endl;

    cout<<endl;

    cout<<"Nama Mobil : "<< xpander_cross.nama<<endl
        <<"Merk : "<< xpander_cross.merk<<endl
        <<"Jenis : "<< xpander_cross.jenis<<endl
        <<"Harga : Rp."<< xpander_cross.harga<<endl;

    cout<<endl;

    // Penggunaan Class
    Pegawai ahmad, sujatmiko;

    ahmad.nama = "Ahmad Basikal";
    ahmad.nip = 2005031;

    sujatmiko.nama = "Sujatmiko Arafuru";
    sujatmiko.nip = 2000103;

    cout<<"Nama Pegawai : "<<ahmad.nama<<endl
        <<"NIP : "<<ahmad.nip<<endl;

    cout<<endl;

    cout<<"Nama Pegawai : "<<sujatmiko.nama<<endl
        <<"NIP : "<<sujatmiko.nip<<endl;
} 