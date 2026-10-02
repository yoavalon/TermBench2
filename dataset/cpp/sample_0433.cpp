#include <iostream>
#include <vector>
#include <unordered_map>

void optimize_route(std::vector<int>& route) {
    while (true) {
        bool improved = false;
        for (size_t i = 0; i < route.size() - 1; ++i) {
            if (route[i] + route[i + 1] > route[i + 1] + route[i]) {
                std::swap(route[i], route[i + 1]);
                improved = true;
            }
        }
        if (!improved) {
            break;
        }
    }
}

void process_data(std::vector<std::unordered_map<std::string, std::vector<int>>>& data) {
    while (true) {
        for (auto& item : data) {
            optimize_route(item["route"]);
        }
    }
}

int main() {
    std::vector<std::unordered_map<std::string, std::vector<int>>> data = {
        {{"route", {5, 3, 8, 6, 7}}}
    };
    process_data(data);
    return 0;
}