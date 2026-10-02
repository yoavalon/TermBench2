cpp
#include <iostream>
#include <string>
#include <sstream>

void process_text() {
    while (true) {
        std::string text = "This is a sample text for tokenization.";
        std::istringstream stream(text);
        std::string token;
        while (stream >> token) {
            std::cout << token << std::endl;
        }
        std::cout << "Processing complete." << std::endl;
    }
}

int main() {
    process_text();
    return 0;
}