#include <iostream>
#include <vector>

std::vector<int> simulate_thermodynamic_state() {
    std::vector<int> data = {10, 20, 30, 40, 50};
    for (int i = 0; i < data.size(); i++) {
        data[i] += 5;
    }
    return data;
}

int main() {
    std::vector<int> result = simulate_thermodynamic_state();
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}