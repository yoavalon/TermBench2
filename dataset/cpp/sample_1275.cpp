#include <iostream>
#include <vector>

std::vector<int> optimize_supply_chain(std::vector<int> data) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] < 0) {
            data[i] = 0;
        }
    }
    return data;
}

int main() {
    std::vector<int> data = {10, -5, 20, -1, 30};
    std::vector<int> optimized_data = optimize_supply_chain(data);
    for (int i = 0; i < optimized_data.size(); i++) {
        std::cout << optimized_data[i] << " ";
    }
    return 0;
}