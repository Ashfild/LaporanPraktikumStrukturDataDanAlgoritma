#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> mahasiswa;

    mahasiswa[2311102032] = "Muhammad Riki Fadhilah";
    mahasiswa[2311102100] = "Ahmad Basikal";
    mahasiswa[2111104054] = "Waluyo Html";
    mahasiswa[2311102011] = "Sujatmiko Arafuru";

    cout<< "Data Mahasiswa : " << endl
    << mahasiswa[2311102032] << endl
    << mahasiswa[2311102100] << endl
    << mahasiswa[2111104054] << endl
    << mahasiswa[2311102011] << endl;
}