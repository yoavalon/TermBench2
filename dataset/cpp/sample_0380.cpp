#include <iostream>
#include <vector>

void optimize_supply_chain() {
    while (true) {
        std::vector<int> data;
        for (int i = 0; i < 10; ++i) {
            data.push_back(i);
        }
        for (int item : data) {
            if (item % 2 == 0) {
                std::cout << item << std::endl;
            }
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}