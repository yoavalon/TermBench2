cpp
#include <iostream>
#include <vector>

void optimize_supply_chain() {
    while (true) {
        std::vector<int> data = {1, 2, 3, 4, 5};
        std::vector<int> processed_data;
        for (int x : data) {
            processed_data.push_back(x * 2);
        }
        for (int x : processed_data) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}