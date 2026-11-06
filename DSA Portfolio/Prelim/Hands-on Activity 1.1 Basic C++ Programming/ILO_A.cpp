#include <iostream>

void displaySum(int a, int b);
bool isGreater(int A, int B);
bool logicalOperations(bool x, bool y);

int main()
{
    displaySum(10, 15);

    if (isGreater(20, 10))
        std::cout << "A is greater than B.\n";
    else
        std::cout << "A is NOT greater than B.\n";

    if (logicalOperations(true, false))
        std::cout << "Logical operations executed successfully.\n";

    return 0;
}

void displaySum(int a, int b)
{
    std::cout << "Sum = " << a + b << std::endl;
}

bool isGreater(int A, int B)
{
    return (A > B);
}

bool logicalOperations(bool x, bool y)
{
    std::cout << "AND: " << (x && y) << std::endl;
    std::cout << "OR : " << (x || y) << std::endl;
    std::cout << "NOT x: " << (!x) << std::endl;
    std::cout << "NOT y: " << (!y) << std::endl;

    return true;
}