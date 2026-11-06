#include <iostream>
#include <cmath>

double distance(double x1, double y1, double x2, double y2);

int main()
{
    double x1, y1, x2, y2;

    std::cout << "Enter x1 y1: ";
    std::cin >> x1 >> y1;

    std::cout << "Enter x2 y2: ";
    std::cin >> x2 >> y2;

    std::cout << "Distance = "
            << distance(x1, y1, x2, y2)
            << std::endl;

    return 0;
}

double distance(double x1, double y1, double x2, double y2)
{
    return std::sqrt((x2 - x1) * (x2 - x1) +
                     (y2 - y1) * (y2 - y1));
}