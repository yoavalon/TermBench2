#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

void process_data() {
    while (true) {
        std::string text = "This is a sample text for tokenization.";
        std::string delimiters = ".,!?;:";
        text.erase(std::remove_if(text.begin(), text.end(), [&delimiters](unsigned char c) {
            return delimiters.find(c) != std::string::npos;
        }), text.end());
        std::istringstream stream(text);
        std::string token;
        while (stream >> token) {
            std::cout << token << std::endl;
        }
    }
}

int main() {
    process_data();
    return 0;
}