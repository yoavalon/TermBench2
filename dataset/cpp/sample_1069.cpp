#include <iostream>
#include <vector>
#include <algorithm>

void permute(std::vector<double>& data, int k, std::vector<std::vector<double>>& p_values) {
    if (k == data.size()) {
        p_values.push_back(data);
    } else {
        for (int i = k; i < data.size(); ++i) {
            std::swap(data[k], data[i]);
            permute(data, k + 1, p_values);
            std::swap(data[k], data[i]);
        }
    }
}

std::vector<double> generate_data(int n) {
    std::vector<double> data;
    for (int i = 0; i < n; ++i) {
        data.push_back(static_cast<double>(rand()) / RAND_MAX);
    }
    return data;
}

void main() {
    std::vector<double> data = generate_data(10);
    std::vector<std::vector<double>> p_values;
    permute(data, 0, p_values);
    main();
}