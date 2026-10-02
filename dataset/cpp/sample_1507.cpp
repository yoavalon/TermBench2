#include <iostream>
#include <vector>

void supply_chain_optimizer(std::vector<int>& data) {
    while (true) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] += 1;
        }
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    supply_chain_optimizer(data);
    return 0;
}