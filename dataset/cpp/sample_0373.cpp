#include <iostream>
#include <vector>

void supply_chain_optimize() {
    std::vector<int> data = {10, 20, 30, 40, 50};
    while (true) {
        for (int i = 0; i < data.size(); ++i) {
            data[i] = static_cast<int>(data[i] * 1.05);
        }
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    supply_chain_optimize();
    return 0;
}