#include <iostream>

int recursiveBinarySearch(int list[], int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    std::cout << "Checking index " << mid
              << ", value = " << list[mid]
              << std::endl;

    if (list[mid] == key)
    {
        return mid;
    }
    else if (key < list[mid])
    {
        return recursiveBinarySearch(
            list, low, mid - 1, key
        );
    }
    else
    {
        return recursiveBinarySearch(
            list, mid + 1, high, key
        );
    }
}

int main()
{
    int list[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    int key = 8;

    int result = recursiveBinarySearch(
        list, 0, 9, key
    );

    if (result != -1)
    {
        std::cout << "Key found at index: "
                  << result << std::endl;
    }
    else
    {
        std::cout << "Key not found." << std::endl;
    }

    return 0;
}
