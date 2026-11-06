#include <iostream>
#include <cmath>

class Triangle
{
private:
    double sideA, sideB, sideC;

public:
    Triangle(double A, double B, double C);

    void setSides(double A, double B, double C);

    double getPerimeter();

    double getArea();

    void triangleType();
};

Triangle::Triangle(double A, double B, double C)
{
    sideA = A;
    sideB = B;
    sideC = C;
}

void Triangle::setSides(double A, double B, double C)
{
    sideA = A;
    sideB = B;
    sideC = C;
}

double Triangle::getPerimeter()
{
    return sideA + sideB + sideC;
}

double Triangle::getArea()
{
    double s = getPerimeter() / 2;

    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

void Triangle::triangleType()
{
    double a2 = sideA * sideA;
    double b2 = sideB * sideB;
    double c2 = sideC * sideC;

    if (a2 > b2)
    {
        double temp = a2;
        a2 = b2;
        b2 = temp;
    }

    if (b2 > c2)
    {
        double temp = b2;
        b2 = c2;
        c2 = temp;
    }

    if (a2 > b2)
    {
        double temp = a2;
        a2 = b2;
        b2 = temp;
    }

    if (a2 + b2 > c2)
        std::cout << "Triangle Type: Acute Triangle\n";
    else if (a2 + b2 < c2)
        std::cout << "Triangle Type: Obtuse Triangle\n";
    else
        std::cout << "Triangle Type: Others (Right Triangle)\n";
}

int main()
{
    Triangle t(3, 4, 5);

    std::cout << "Perimeter: " << t.getPerimeter() << std::endl;
    std::cout << "Area: " << t.getArea() << std::endl;

    t.triangleType();

    return 0;
}