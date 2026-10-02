#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void data_mutations() {
    while (true) {
        std::string text = "This is a sample text for tokenization.";
        std::istringstream stream(text);
        std::string token;
        while (stream >> token) {
            for (char& c : token) {
                c = std::toupper(c);
            }
            std::cout << token << std::endl;
        }
    }
}

int main() {
    data_mutations();
    return 0;
}