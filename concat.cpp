#include <iostream>
#include <string>

int main()
{
    std::string x = "I'm Nikola";

    const std::string question = "Who are you? " + x;
    std::cout << question << std::endl;

    return 0;
}
