#include <iostream>
using namespace std;
char charArray[100];
int maksimal = 100, top = 0;
bool isFull()
{
    return (top == maksimal);
}
bool isEmpty()
{
    return (top == 0);
}
void push(char data)
{
    if (isFull())
    {
        cout << "Stack telah penuh" << endl;
    }
    else
    {
        charArray[top] = data;
        top++;
    }
}
char pop()
{
    if (isEmpty())
    {
        cout << "Stack kosong" << endl;
        return -1; // Mengembalikan karakter khusus untuk menandai kesalahan
    }
    else
    {
        top--;
        char popped = charArray[top]; // Mengambil karakter sebelum mengurangi top
        return popped;
    }
}

int main()
{
    string kata;
    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    string kataDibalik = "";
    for (int i = 0; i < kata.length(); i++)
    {
        kataDibalik.push_back(pop());
    }

    if (kata == kataDibalik){
        cout << kata << " adalah palindrom" << endl;
    } else {
        cout << kata << " bukan palindrom" << endl;
    }
    return 0;
}
