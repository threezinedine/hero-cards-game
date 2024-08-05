#include <iostream>

int main(int argc, char **argv)
{
#ifdef _DEBUG
    std::cout << "Debug mode\n";
#else
    std::cout << "Release mode\n";
#endif
    std::cout << "Hello world\n";
    return 0;
}