#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main()
{
    int unsortedArr[maxSize];
    int shellArr[maxSize];
    int mergeArr[maxSize];
    int quickArr[maxSize];

    srand(time(0));

    for (int i = 0; i < maxSize; i++)
    {
        unsortedArr[i] = rand() % 100;
    }

    for (int i = 0; i < maxSize; i++)
    {
        shellArr[i] = unsortedArr[i];
        mergeArr[i] = unsortedArr[i];
        quickArr[i] = unsortedArr[i];
    }

    std::cout << "Original Array: \n";
    displayArr(unsortedArr);

    std::cout << "\nShell Sort: \n";
    shellSort(shellArr, maxSize);
    displayArr(shellArr);

    std::cout << "\nMerge Sort: \n";
    mergeSort(mergeArr, 0, maxSize - 1);
    displayArr(mergeArr);

    std::cout << "\nQuick Sort: \n";
    quickSort(quickArr, 0, maxSize - 1);
    displayArr(quickArr);

    return 0;
}

void displayArr(int arr[])
{
    for (int i = 0; i < maxSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}