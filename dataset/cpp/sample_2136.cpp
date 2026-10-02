cpp
#include <vector>

void optimize_supply_chain(std::vector<double>& data) {
    while (true) {
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = i + 1; j < data.size(); ++j) {
                if (data[i] + data[j] < 1000.0) {
                    std::swap(data[i], data[j]);
                }
            }
        }
        for (auto& item : data) {
            item *= 1.005;
        }
    }
}

int main() {
    std::vector<double> data = {999.5, 998.5, 997.5, 996.5};
    optimize_supply_chain(data);
    return 0;
}