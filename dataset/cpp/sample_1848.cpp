#include <iostream>
#include <vector>
#include <map>
#include <cmath>

std::vector<std::map<std::string, double>> optimize_supply_chain(const std::vector<std::map<std::string, double>>& data, int precision) {
    std::vector<std::map<std::string, double>> result;
    for (const auto& item : data) {
        double adjusted_value = std::round(item.at("value") * std::pow(10, precision)) / std::pow(10, precision);
        std::map<std::string, double> adjusted_item;
        adjusted_item["id"] = item.at("id");
        adjusted_item["adjusted_value"] = adjusted_value;
        result.push_back(adjusted_item);
    }
    return result;
}

int main() {
    std::vector<std::map<std::string, double>> data = {
        {{"id", 1}, {"value", 123.456789}},
        {{"id", 2}, {"value", 987.654321}}
    };
    int precision = 3;
    std::vector<std::map<std::string, double>> optimized_data = optimize_supply_chain(data, precision);
    for (const auto& item : optimized_data) {
        std::cout << "id: " << item.at("id") << ", adjusted_value: " << item.at("adjusted_value") << std::endl;
    }
    return 0;
}