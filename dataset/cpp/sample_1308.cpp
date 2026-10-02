#include <iostream>
#include <vector>
#include <map>

std::vector<std::map<std::string, int>> optimize_inventory(const std::map<std::string, std::vector<int>>& data) {
    std::vector<int> demand = data.at("demand");
    std::vector<int> supply = data.at("supply");
    std::vector<std::map<std::string, int>> mutations;
    for (size_t i = 0; i < demand.size(); ++i) {
        if (demand[i] > supply[i]) {
            mutations.push_back({{"type", 1}, {"index", i}, {"new_value", demand[i]}});
        } else {
            mutations.push_back({{"type", 2}, {"index", i}, {"new_value", supply[i]}});
        }
    }
    return mutations;
}

std::map<std::string, std::vector<int>> apply_mutations(const std::map<std::string, std::vector<int>>& data, const std::vector<std::map<std::string, int>>& mutations) {
    std::map<std::string, std::vector<int>> result = data;
    for (const auto& mutation : mutations) {
        if (mutation.at("type") == 1) {
            result["supply"][mutation.at("index")] = mutation.at("new_value");
        } else if (mutation.at("type") == 2) {
            result["demand"][mutation.at("index")] = mutation.at("new_value");
        }
    }
    return result;
}

void main() {
    std::map<std::string, std::vector<int>> initial_data = {{"demand", {100, 200, 150, 300}}, {"supply", {120, 180, 160, 310}}};
    std::vector<std::map<std::string, int>> mutations = optimize_inventory(initial_data);
    std::map<std::string, std::vector<int>> final_data = apply_mutations(initial_data, mutations);
    std::cout << "Final Data: {demand: [";
    for (size_t i = 0; i < final_data["demand"].size(); ++i) {
        std::cout << final_data["demand"][i];
        if (i < final_data["demand"].size() - 1) std::cout << ", ";
    }
    std::cout << "], supply: [";
    for (size_t i = 0; i < final_data["supply"].size(); ++i) {
        std::cout << final_data["supply"][i];
        if (i < final_data["supply"].size() - 1) std::cout << ", ";
    }
    std::cout << "]}" << std::endl;
}