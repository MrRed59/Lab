#include <iostream>
#include <conio.h>

int main()
{
    //std::cout << "Hello World!\n";

    //int value, value2;

    //std::cout << "value" << std::endl;
    //std::cin >> value;

    //std::cout << "value2" << std::endl;
    //std::cin >> value2;

    //std::cout << "value" << std::endl;
    //std::cout << value << std::endl;

    //std::cout << "value2" << std::endl;
    //std::cout << value2 << std::endl;

   
    ///// //////

    //std::cout << "==========================================" << std::endl;


    //int value3, value4;

    //std::cout << "value3" << std::endl;
    //std::cin >> value3;

    //std::cin.ignore(1024, '\n');

    //std::cout << "value4" << std::endl;
    //std::cin >> value4;

    //std::cout << "value3" << std::endl;
    //std::cout << value3 << std::endl;

    //std::cout << "value4" << std::endl;
    //std::cout << value4 << std::endl;

    /*int value;
    do
    {
        if (!std::cin)
        {
            std::cout << "Syntax error" << std::endl;
            std::cin.clear();
            std::cin.ignore(1024, '\n');
        }
        std::cin >> value;
    } while (!std::cin);*/

    short choise;
    short high = 9;
    short low = 0;
    do
    {
        choise = _getche();
        std::cout << std::endl;
        if (choise > (high + 48) || choise < (low + 48))
            std::cout << "Error. Enter a number from " << low << " to " << high << std::endl;
    } while (choise > (high + 48) || choise < (low + 48));
}