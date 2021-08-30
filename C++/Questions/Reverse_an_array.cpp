#include <iostream>

using namespace std;

int *reverseArray(int *arr, int n)
{
    int c = n % 2 == 0 ? n / 2 : (n / 2) + 1;
    for (int i = 0; i < c; i++)
    {
        int temp = *(arr+i);
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    return arr;
}

int main()
{
    int n;
    n = 10;
    // cin >> n;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int *a = reverseArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}