#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> optimize_supply_chain(const std::vector<int>& data) {
    std::vector<int> demand(data.size());
    std::vector<int> supply(data.size());
    std::vector<int> mutations(data.size());

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 500);

    for (size_t i = 0; i < data.size(); ++i) {
        demand[i] = dis(gen);
        supply[i] = dis(gen);
        mutations[i] = (demand[i] > supply[i]) ? demand[i] - supply[i] : 0;
    }

    return mutations;
}

int main() {
    std::vector<int> data(10);
    std::iota(data.begin(), data.end(), 0);

    std::vector<int> result = optimize_supply_chain(data);

    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}