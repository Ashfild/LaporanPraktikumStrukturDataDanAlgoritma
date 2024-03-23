#include <iostream>
using namespace std;

int main()
{
    int x, y, z;
    cout << "Masukkan jumlah elemen ke-1: ";
    cin >> x;
    cout << "Masukkan jumlah elemen ke-2: ";
    cin >> y;
    cout << "Masukkan jumlah elemen ke-3: ";
    cin >> z;

    int arr[x][y][z];

    // Input Array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Data Array[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
            }
        }
    }

    cout << endl;

    // Tampilan array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
