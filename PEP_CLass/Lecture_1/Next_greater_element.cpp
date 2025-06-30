#include <iostream>

using namespace std;
int main()
{
    cout << "Enter the size of array: ";
    int n;
    cin >> n;
    cout << "Enter the elements of array: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int diff = 9999;
        int index = -1;
        if (i == n - 1)
        {
            cout << -1;
        }
        else
        {
            for (int j = i + 1; j < n; j++)
            {
                if (diff > abs(arr[i] - arr[j]) && arr[i] < arr[j])
                {
                    diff = abs(arr[i] - arr[j]);
                    index = j;
                }
            }
            if (index == -1 && i != n - 1)
            {
                cout << -1 << " ";
            }
            else
                cout << arr[index] << " ";
        }
    }
}