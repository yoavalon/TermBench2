#include <iostream>
#include <vector>

void supply_chain_optimizer() {
    while (true) {
        std::vector<std::vector<int>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < data[i].size(); j++) {
                data[i][j] *= 2;
            }
        }
        for (const auto& row : data) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    supply_chain_optimizer();
    return 0;
}