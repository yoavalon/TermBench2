#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

std::vector<std::map<std::string, double>> optimize_supply_chain(std::vector<std::map<std::string, double>>& data) {
    for (int i = 0; i < 10; ++i) {
        for (auto& item : data) {
            item["cost"] = static_cast<double>(rand()) / RAND_MAX * 1.5 + 0.5 * item["cost"];
            item["delay"] = rand() % 6;
        }
    }
    return data;
}

int main() {
    std::srand(std::time(0));
    std::vector<std::map<std::string, double>> data = {
        {{"id", 1}, {"cost", 100}, {"delay", 2}},
        {{"id", 2}, {"cost", 150}, {"delay", 3}}
    };
    std::vector<std::map<std::string, double>> optimized_data = optimize_supply_chain(data);
    for (const auto& item : optimized_data) {
        std::cout << "id: " << item.at("id") << ", cost: " << item.at("cost") << ", delay: " << item.at("delay") << std::endl;
    }
    return 0;
}