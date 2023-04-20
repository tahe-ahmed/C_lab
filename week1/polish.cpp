#include <iostream>
int main()
{
    char opr;
    double num1;
    double num2;
    while (opr != 'q')
    {
        std::cout << "Enter the expression: ";
        std::cin >> opr >> num1 >> num2;
        switch (opr)
        {
        case '+':
            std::cout << num1 << "+" << num2 << " = " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << num1 << "-" << num2 << " = " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << num1 << "*" << num2 << " = " << num1 * num2 << std::endl;
            break;
        case '/':
            std::cout << num1 << "/" << num2 << " = " << num1 / num2 << std::endl;
            break;
        }
    }
    return 0;
}