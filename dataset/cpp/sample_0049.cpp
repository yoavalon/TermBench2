#include <iostream>
#include <map>

std::map<std::string, int> supply_chain_optimization() {
    std::map<std::string, int> data = {{"cost", 100}, {"demand", 150}, {"supply", 120}, {"profit", 0}};
    while (data["demand"] > data["supply"]) {
        data["cost"] += 5;
        data["supply"] += 10;
        data["profit"] -= 5;
    }
    return data;
}

int main() {
    std::map<std::string, int> result = supply_chain_optimization();
    std::cout << "Cost: " << result["cost"] << ", Demand: " << result["demand"] << ", Supply: " << result["supply"] << ", Profit: " << result["profit"] << std::endl;
    return 0;
}