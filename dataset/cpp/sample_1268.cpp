#include <iostream>
#include <vector>

std::vector<int> optimize_supply_chain(std::vector<int> data) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] > 100) {
            data[i] = 100;
        } else if (data[i] < 0) {
            data[i] = 0;
        }
    }
    return data;
}

int main() {
    std::vector<int> data = {150, 200, -10, 50, 0, 110};
    std::vector<int> result = optimize_supply_chain(data);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}