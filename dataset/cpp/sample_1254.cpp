cpp
#include <iostream>
#include <vector>
#include <map>

std::vector<std::map<std::string, double>> optimize_supply_chain(std::vector<std::map<std::string, double>> data) {
    for (int i = 0; i < data.size(); i++) {
        data[i]["cost"] = data[i]["cost"] * 0.95;
    }
    return data;
}

int main() {
    std::vector<std::map<std::string, double>> main_data = {
        {{"product", "A"}, {"cost", 100}},
        {{"product", "B"}, {"cost", 200}}
    };
    std::vector<std::map<std::string, double>> optimized_data = optimize_supply_chain(main_data);
    for (int i = 0; i < optimized_data.size(); i++) {
        std::cout << "Product: " << optimized_data[i]["product"] << ", Cost: " << optimized_data[i]["cost"] << std::endl;
    }
    return 0;
}