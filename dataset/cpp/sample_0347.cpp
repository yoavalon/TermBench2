#include <iostream>
#include <vector>

void simulate() {
    std::vector<double> data = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    while (true) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] = (data[i] + 0.01) % 1.0;
            for (double value : data) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    simulate();
    return 0;
}