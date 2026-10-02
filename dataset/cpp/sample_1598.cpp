#include <iostream>
#include <vector>

void optimize_supply_chain(std::vector<int>& data) {
    while (true) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] = data[i] + 1;
        }
    }
}

int main() {
    std::vector<int> data = {0, 1, 2, 3, 4};
    optimize_supply_chain(data);
    return 0;
}