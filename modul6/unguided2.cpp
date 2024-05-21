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
        charArray[top] = '\0'; // Menghapus karakter dari stack
        return popped;
    }
}

char peek()
{
    if (!isEmpty())
    {
        return charArray[top - 1];
    }
    else
    {
        return '\0';
    }
}

int main()
{
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
    {
        push(input[i]);
    }

    cout << "Hasil pembalikan kalimat : ";
    while (!isEmpty())
    {
        cout << peek();
        pop();
    }

    return 0;
}
