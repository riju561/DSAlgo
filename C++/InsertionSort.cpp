#include <iostream>

int *insertionSort(int *array, size_t n)
{
    std::cout << "Initial Array: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;

    //Insertion sort Algo
    for (int j = 1; j < n; j++)
    {
        int key = *(array + j);
        std::cout << "key " << key << std::endl;
        int i = j - 1;
        while (i >= 0 && *(array + i) > key)
        {
            *(array + i + 1) = *(array + i);
            i -= 1;
        }
        *(array + i + 1) = key;
        std::cout << "Pass no. " << j - 1 << std::endl;
        for (int i = 0; i < n; i++)
        {
            std::cout << *(array + i) << " ";
        }
        std::cout << std::endl;
    }
    return array;
}

int main()
{
    int a[] = {1231, 123123, 12, 3, 123, 21, 3, 12, 3, 24, 234, 4542, 5, 43, 55, 3, 542, 52, 53, 24, 32, 4, 123, 41, 24, 3, 52, 5, 2, 4, 24};
    size_t n = sizeof(a) / sizeof(a[0]);
    int *array = insertionSort(a, n);
    // std::cout << a << " " << array << std::endl;
    // for (int i = 0; i < n; i++)
    // {
    //     std::cout << *(array + i) << " ";
    // }
    // std::cout << std::endl;
    return 0;
}