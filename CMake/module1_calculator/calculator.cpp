#include <iostream>
#include "math.hpp"
#include "log.hpp"

int main()
{
    int first_number, second_number;
    std::cout << "*** Addition ***" << std::endl;
    std::cout << "  Enter first number: ";
    std::cin >> first_number;
    std::cout << "  Enter second number: ";
    std::cin >> second_number;
    print_result("Addition result", add(first_number, second_number));

    int dividend, divisor;
    std::cout << std::endl << "*** Division ***" << std::endl;
    std::cout << "  Enter dividend: ";
    std::cin >> dividend;
    std::cout << "  Enter divisor: ";
    std::cin >> divisor;
    print_result("Division result", divide(dividend, divisor));
}
