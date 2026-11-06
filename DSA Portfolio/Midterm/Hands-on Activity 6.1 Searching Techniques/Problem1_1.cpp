#include <iostream>

int main()
{
    int list[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int key = 18;
    int comparisons = 0;

    for (int i = 0; i < 10; i++)
    {
        comparisons++;

        if (list[i] == key)
        {
            std::cout << "Key found at index: " << i << std::endl;
            break;
        }
    }

    std::cout << "Number of comparisons: "
              << comparisons << std::endl;

    return 0;
}
