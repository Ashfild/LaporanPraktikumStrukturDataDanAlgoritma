#include<iostream>
using namespace std;

int tambah(int x, int y){
    return x + y;
}

float kali(float m, float n){
    return m * n;
}

int main(){
    int x= 10;
    int y= 6;
    float m= 3.2;
    float n= 4;
    
    cout<<"Hasil penjumlahan 10 + 6 adalah "<<tambah(x,y)<<endl;
    cout<<"Hasil perkalian 3.2 x 4 adalah "<<kali(m,n);

}