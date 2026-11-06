#ifndef SORTING_H
#define SORTING_H

template <typename T>
void bubbleSort(T arr[], int maxSize)
{
    for (int i = 0; i < maxSize - 1; i++)
    {
        for (int j = 0; j < maxSize - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int routine_smallest(T arr[], int k, int arrSize) {
    int position = k;

    T smallestElement = arr[k];
    for (int j = k + 1; j < arrSize; j++) {
        if (arr[j] < smallestElement) {
            position = j;
            smallestElement = arr[j];
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], int arrSize) {
    int min;

    for (int i = 0; i < arrSize - 1; i++) {
        min = routine_smallest(arr, i, arrSize);
        T temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

template <typename T>
void insertionSort(T arr[], int arrSize)
{
    int k = 1, j;
    T temp;

    while (k < arrSize)
    {
        temp = arr[k];
        j = k - 1;
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        k++;
    }
} 


#endif 



