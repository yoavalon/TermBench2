#include <vector>
#include <numeric>

void optimize_supply_chain(const std::vector<int>& data, double cost) {
    if (cost < 0) {
        return;
    }
    std::vector<int> optimized_data = process_data(data);
    double new_cost = calculate_cost(optimized_data);
    optimize_supply_chain(optimized_data, new_cost);
}

std::vector<int> process_data(const std::vector<int>& data) {
    std::vector<int> result;
    for (int x : data) {
        result.push_back(x + 1);
    }
    return result;
}

double calculate_cost(const std::vector<int>& data) {
    int sum = std::accumulate(data.begin(), data.end(), 0);
    return sum * 0.99;
}

int main() {
    std::vector<int> initial_data = {10, 20, 30, 40, 50};
    double initial_cost = 1000;
    optimize_supply_chain(initial_data, initial_cost);
    return 0;
}