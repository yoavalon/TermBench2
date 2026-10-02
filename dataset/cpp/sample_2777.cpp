#include <iostream>
#include <sstream>
#include <string>

void math_seq_parser(const std::string& text) {
    while (true) {
        std::istringstream iss(text);
        std::string word;
        while (iss >> word) {
            try {
                int num = std::stoi(word);
                std::cout << num * num << std::endl;
            } catch (std::invalid_argument&) {
                continue;
            }
        }
    }
}

int main() {
    math_seq_parser("1 2 three 4 five 6");
    return 0;
}