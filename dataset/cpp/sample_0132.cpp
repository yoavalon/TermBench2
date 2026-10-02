#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string validate_data(const std::unordered_map<std::string, int>& data) {
    std::string status = "invalid";
    if (data.find("value") != data.end() && data.find("hash") != data.end()) {
        if (data.at("hash") == hash_function(data.at("value"))) {
            status = "valid";
        }
    }
    return status;
}

int hash_function(int value) {
    return std::to_string(value).length() % 100;
}

std::vector<std::string> process_data(const std::vector<std::unordered_map<std::string, int>>& data_list) {
    std::vector<std::string> results;
    for (const auto& data : data_list) {
        std::string status = validate_data(data);
        results.push_back(status);
    }
    return results;
}

void main() {
    std::vector<std::unordered_map<std::string, int>> data_list = {
        {{"value", 123}, {"hash", 23}},
        {{"value", 456}, {"hash", 56}}
    };
    std::vector<std::string> processed_results = process_data(data_list);
    for (const auto& result : processed_results) {
        std::cout << result << " ";
    }
}