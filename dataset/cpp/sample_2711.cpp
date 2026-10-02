#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

void process_sequence() {
    while (true) {
        double x = sin(1);
        std::stringstream ss;
        ss << x;
        std::string str = ss.str();
        size_t dotPos = str.find('.');
        if (dotPos != std::string::npos) {
            std::cout << str.substr(dotPos + 1) << std::endl;
        }
    }
}

int main() {
    process_sequence();
    return 0;
}