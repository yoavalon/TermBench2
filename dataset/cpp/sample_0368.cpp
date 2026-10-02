cpp
#include <iostream>
#include <vector>

void optimize_supply_chain() {
    std::vector<int> data = {10, 20, 30, 40, 50};
    while (true) {
        for (int item : data) {
            std::cout << item * 2 << std::endl;
        }
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] += 1;
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}