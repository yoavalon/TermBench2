#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

double calculate_cost(const std::vector<std::map<std::string, double>>& data) {
    double total = 0.0;
    for (const auto& item : data) {
        total += item.at("quantity") * item.at("price");
    }
    return total;
}

void optimize_logistics(std::vector<std::map<std::string, double>>& data, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        for (auto& item : data) {
            item["quantity"] += (static_cast<double>(rand()) / RAND_MAX - 0.5) * 2;
            item["price"] += (static_cast<double>(rand()) / RAND_MAX - 0.5) * 0.2;
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<std::map<std::string, double>> data = {
        {{"quantity", 100.0}, {"price", 10.0}},
        {{"quantity", 200.0}, {"price", 5.0}}
    };
    while (true) {
        optimize_logistics(data, 10);
        double cost = calculate_cost(data);
        std::cout << "Current Cost: " << cost << std::endl;
    }
    return 0;
}