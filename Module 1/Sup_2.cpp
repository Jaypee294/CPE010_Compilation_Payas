#include <iostream>

double kelvinToFahrenheit(double kelvin);

int main()
{
    double kelvin;

    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;

    std::cout << "Temperature in Fahrenheit: "
            << kelvinToFahrenheit(kelvin) << std::endl;

    return 0;
}

double kelvinToFahrenheit(double kelvin)
{
    return (kelvin - 273.15) * 9 / 5 + 32;
}