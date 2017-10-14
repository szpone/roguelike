#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your first name: ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello " + name;

    for (int i = 0; greeting[i] != '\0'; i++) {
        std::cout << greeting[i] << std::endl;
    }

    return 0;
}
