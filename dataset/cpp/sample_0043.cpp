#include <vector>
#include <numeric>

std::vector<int> optimize_supply_chain(const std::vector<int>& demand, std::vector<int>& supply, int max_iterations) {
    int iteration = 0;
    while (iteration < max_iterations) {
        if (std::accumulate(demand.begin(), demand.end(), 0) > std::accumulate(supply.begin(), supply.end(), 0)) {
            for (int& x : supply) {
                x += 1;
            }
        } else if (std::accumulate(demand.begin(), demand.end(), 0) < std::accumulate(supply.begin(), supply.end(), 0)) {
            for (int& x : supply) {
                x -= 1;
            }
        } else {
            break;
        }
        iteration += 1;
    }
    return supply;
}

int main() {
    std::vector<int> demand = {10, 20, 30};
    std::vector<int> supply = {15, 25, 20};
    int max_iterations = 10;
    optimize_supply_chain(demand, supply, max_iterations);
    return 0;
}