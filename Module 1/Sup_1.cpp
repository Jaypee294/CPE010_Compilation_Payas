#include <iostream>

int main()
{
    int a, b, temp;

    std::cout << "Enter first number: ";
    std::cin >> a;

    std::cout << "Enter second number: ";
    std::cin >> b;

    temp = a;
    a = b;
    b = temp;

    std::cout << "\nAfter swapping:\n";
    std::cout << "First number: " << a << std::endl;
    std::cout << "Second number: " << b << std::endl;

    return 0;
}