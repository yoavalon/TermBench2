#include <iostream>
#include <vector>

std::vector<int> supply_chain_optimize(std::vector<int> data) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] > 0) {
            data[i] -= 1;
        } else {
            data[i] = 0;
        }
    }
    return data;
}

int main() {
    std::vector<int> dataset = {10, 5, 0, 8, 3};
    std::vector<int> optimized_data = supply_chain_optimize(dataset);
    for (int i = 0; i < optimized_data.size(); i++) {
        std::cout << optimized_data[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}