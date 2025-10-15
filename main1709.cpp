#include <iostream>
#include <format>

int main() {
    int x = 7;
    std::cout << std::format("Hello, x = {}\n", x) << std::endl;
}