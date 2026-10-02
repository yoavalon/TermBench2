#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> optimize_supply_chain(std::vector<int> data) {
    for (int i = 0; i < data.size(); i++) {
        data[i] = std::min(data[i], 100);
    }
    return data;
}

std::vector<int> process_data(std::vector<int> data) {
    std::vector<int> result;
    for (int item : data) {
        if (item > 50) {
            result.push_back(item - 25);
        } else {
            result.push_back(item + 25);
        }
    }
    return result;
}

void main() {
    std::vector<int> initial_data = {60, 20, 110, 30, 80};
    std::vector<int> processed_data = optimize_supply_chain(initial_data);
    std::vector<int> final_data = process_data(processed_data);
    for (int item : final_data) {
        std::cout << item << " ";
    }
}