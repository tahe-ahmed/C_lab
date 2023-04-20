#include <iostream>

int main()
{
    int num;
    int coutOne;

    std::cout << "Enter the first number of the sequence: ";
    std::cin >> num;

    coutOne = (num == 1) ? 1 : 0;

    if (num <= 0)
    {
        std::cout << "Please enter a number greater than Zero!" << std::endl;
        return 0;
    }

    std::cout << num << " ";

    while (coutOne < 3)
    {
        (num % 2 == 0) ? num /= 2 : num = (3 * num) + 1;
        std::cout << num << " ";
        (num == 1) ? coutOne++ : coutOne;
    }

    std::cout << "..." << std::endl;

    return 0;
}