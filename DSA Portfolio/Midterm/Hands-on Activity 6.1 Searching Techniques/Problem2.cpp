#include <iostream>

int sequentialSearchCount(int list[], int size, int k)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i] == k)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int list[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = 10;
    int k = 18;
    int count = sequentialSearchCount(list, size, k);
    std::cout << "Search element: " << k << std::endl;
    std::cout << "Number of repeating instances: "
              << count << std::endl;
    return 0;
}
