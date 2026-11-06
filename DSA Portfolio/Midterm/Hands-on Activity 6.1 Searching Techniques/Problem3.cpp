#include <iostream>

int binarySearch(int list[], int size, int key)
{
    int low = 0;
    int high = size - 1;
    int comparisons = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        comparisons++;
        std::cout << "Iteration " << comparisons
                  << ": mid = " << mid
                  << ", value = " << list[mid]
                  << std::endl;
        if (list[mid] == key)
        {
            std::cout << "Key found at index: "
                      << mid << std::endl;

            std::cout << "Total comparisons: "
                      << comparisons << std::endl;
            return mid;
        }
        else if (key < list[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    std::cout << "Key not found." << std::endl;

    return -1;
}

int main()
{
    int list[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int key = 8;
    binarySearch(list, 10, key);
    return 0;
}
