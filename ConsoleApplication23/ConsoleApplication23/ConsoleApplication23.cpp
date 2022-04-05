#include <iostream>

extern int g_x;
void Foo();

int main()
{
    Foo();
    std::cout << g_x << std::endl;
    g_x = 1;
    std::cout << g_x << std::endl;

    std::cout << "Hello World!\n";
}