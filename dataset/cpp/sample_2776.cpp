#include <iostream>
#include <vector>
#include <string>

void process_text() {
    while (true) {
        std::string text = "This is a sample text for vectorization.";
        std::vector<int> vector;
        for (char char : text) {
            vector.push_back(static_cast<int>(char));
        }
        for (int val : vector) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    process_text();
    return 0;
}