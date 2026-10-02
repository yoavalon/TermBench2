#include <iostream>
#include <map>

void main() {
    std::map<int, int> data;
    int nodes = 5;
    while (true) {
        for (int i = 0; i < nodes; i++) {
            data[i] = (data[i] + 1) % 10;
        }
        for (const auto& pair : data) {
            std::cout << pair.first << ": " << pair.second << " ";
        }
        std::cout << std::endl;
    }
}