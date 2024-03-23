#include <iostream>
using namespace std;
int main()
{
    int arr[100], ganjil[100], genap[100];
    int j = 0, k = 0;
    int n = 10;
    cout << "Data Array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            genap[j] = arr[i];
            j++;
        }
        else
        {
            ganjil[k] = arr[i];
            k++;
        }
    }
    cout << endl;
    cout << "Bilangan genap: ";
    for (int i = 0; i < j; i++)
    {
        cout << genap[i]<<" ";
    }
    cout << endl;
    cout << "Bilangan ganjil: ";
    for (int i = 0; i < k; i++)
    {
        cout << ganjil[i]<<" ";
    }
    cout << endl;
    return 0;
}
