#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    int a = 1000;
    double b = 0.0001, c=a-b;
    std::cout.precision(20);
    std::cout << c;
}

