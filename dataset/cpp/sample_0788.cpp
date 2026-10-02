#include <iostream>
#include <vector>

std::vector<int> optimize_shipments(const std::vector<int>& data, int index) {
    if (index >= data.size()) {
        return {};
    }
    int current = data[index];
    std::vector<int> rest = optimize_shipments(data, index + 1);
    if (current < 10) {
        rest.insert(rest.begin(), current);
    }
    return rest;
}

std::vector<int> process_data(const std::vector<int>& data) {
    return optimize_shipments(data, 0);
}

int main() {
    std::vector<int> data = {5, 12, 7, 9, 15, 3};
    std::vector<int> result = process_data(data);
    for (int value : result) {
        std::cout << value << " ";
    }
    return 0;
}