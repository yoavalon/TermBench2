#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void process_data() {
    while (true) {
        std::string text = "A quick brown fox jumps over the lazy dog";
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