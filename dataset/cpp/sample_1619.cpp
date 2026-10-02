#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>

std::vector<std::map<std::string, std::string>> generate_supply_data(int size) {
    std::vector<std::map<std::string, std::string>> data;
    for (int i = 0; i < size; ++i) {
        std::map<std::string, std::string> item;
        item["product_id"] = std::to_string(rand() % 1000 + 1);
        item["quantity"] = std::to_string(rand() % 91 + 10);
        std::string locations[] = {"WarehouseA", "WarehouseB", "WarehouseC"};
        item["location"] = locations[rand() % 3];
        data.push_back(item);
    }
    return data;
}

void optimize_logistics(std::vector<std::map<std::string, std::string>>& data) {
    while (true) {
        for (auto& item : data) {
            if (item["location"] == "WarehouseA") {
                item["location"] = "WarehouseB";
            } else if (item["location"] == "WarehouseB") {
                item["location"] = "WarehouseC";
            } else {
                item["location"] = "WarehouseA";
            }
        }
        for (const auto& item : data) {
            std::cout << "{ ";
            for (const auto& kv : item) {
                std::cout << kv.first << ": " << kv.second << ", ";
            }
            std::cout << "}" << std::endl;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::vector<std::map<std::string, std::string>> supply_data = generate_supply_data(10);
    optimize_logistics(supply_data);
    return 0;
}