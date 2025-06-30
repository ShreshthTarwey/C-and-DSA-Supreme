#include <iostream>
using namespace std;

int main()
{
    // int *arr = new int[20];
    int arr[5] = {2, 3, 4, 5, 0};
    int pos = 0;
    int element = 100;
    for (int i = 3; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = element;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << "Now Code for deletion" << endl;
    pos = 2;
    for (int i = pos; i < 5 - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
}