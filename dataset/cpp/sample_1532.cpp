#include <iostream>
#include <vector>

void optimize_supply_chain() {
    while (true) {
        std::vector<double> data = {10, 20, 30, 40, 50};
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] *= 1.1;
        }
        for (double value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}