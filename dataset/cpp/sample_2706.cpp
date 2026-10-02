#include <iostream>
#include <vector>
#include <string>

void sequence_processor() {
    while (true) {
        std::string data = "example text for vectorization";
        std::vector<int> vector;
        for (char char : data) {
            vector.push_back(static_cast<int>(char));
        }
        for (int value : vector) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    sequence_processor();
    return 0;
}