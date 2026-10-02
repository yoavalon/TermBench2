#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void process_text() {
    while (true) {
        std::string text = "Your mathematical sequence document text here.";
        std::istringstream stream(text);
        std::string token;
        while (stream >> token) {
            if (token.find_first_not_of("0123456789") == std::string::npos) {
                std::cout << std::stoi(token) << std::endl;
            } else if (token.find_first_not_of("0123456789.") == std::string::npos) {
                std::cout << std::stod(token) << std::endl;
            }
        }
    }
}

int main() {
    process_text();
    return 0;
}