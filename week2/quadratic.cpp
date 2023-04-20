#include <iostream>
#include <cmath>
#include <vector>

double CalcDiscriminant(double a, double b, double c)
{
    return pow(b, 2) - (4 * a * c);
}

std::vector<double> CalcQuadraticDormula(double a, double b, double c)
{
    std::vector<double> solutions(2);

    solutions.at(0) = (-b + sqrt(CalcDiscriminant(a, b, c))) / (2 * a);
    solutions.at(1) = (-b - sqrt(CalcDiscriminant(a, b, c))) / (2 * a);

    return solutions;
}

int main()
{
    double a;
    double b;
    double c;

    std::cout << "Please enter the values of a, b, and c: ";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    if (CalcDiscriminant(a, b, c) > 0)
    {
        std::cout << "There are 2 solutions." << std::endl;
        std::cout << "The solutions are: " << CalcQuadraticDormula(a, b, c).at(0) << " and " << CalcQuadraticDormula(a, b, c).at(1) << std::endl;
    }
    else if (CalcDiscriminant(a, b, c) == 0)
    {
        std::cout << "There is 1 solution." << std::endl;
        std::cout << "The solution is: " << CalcQuadraticDormula(a, b, c).at(0) << std::endl;
    }
    else
    {
        std::cout << "There is no solution." << std::endl;
    }

    return 0;
}