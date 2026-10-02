#include <iostream>
#include <vector>
#include <numeric>

void optimize_supply_chain(std::vector<double>& data) {
    while (true) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] = data[i] * 1.001;
        }
        std::cout << std::accumulate(data.begin(), data.end(), 0.0) << std::endl;
    }
}

int main() {
    std::vector<double> data = {100.0, 200.0, 300.0};
    optimize_supply_chain(data);
    return 0;
}