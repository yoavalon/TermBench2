#include <iostream>
#include <vector>
#include <cmath>

double optimize_supply_chain(const std::vector<std::map<std::string, double>>& data) {
    double total_cost = 0.0;
    for (const auto& item : data) {
        total_cost += item.at("quantity") * item.at("price");
    }
    return std::round(total_cost * 100) / 100;
}

int main() {
    std::vector<std::map<std::string, double>> data = {
        {{"quantity", 150.75}, {"price", 2.34}},
        {{"quantity", 200.5}, {"price", 1.8}},
        {{"quantity", 120.25}, {"price", 3.15}}
    };
    double result = optimize_supply_chain(data);
    std::cout << result << std::endl;
    return 0;
}