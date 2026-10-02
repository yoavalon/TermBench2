#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> boundary_conditions(const std::vector<double>& data, double threshold) {
    std::vector<int> result;
    for (int i = 0; i < data.size(); ++i) {
        if (std::abs(data[i]) > threshold) {
            result.push_back(i);
        }
        if (result.size() == 3) {
            break;
        }
    }
    return result;
}

int main() {
    std::vector<double> data = {0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9};
    double threshold = 0.5;
    std::vector<int> result = boundary_conditions(data, threshold);
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    return 0;
}