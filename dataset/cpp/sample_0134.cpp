#include <iostream>
#include <vector>

std::vector<int> filter_signal(const std::vector<int>& data, const std::vector<int>& kernel) {
    std::vector<int> result;
    for (size_t i = 0; i <= data.size() - kernel.size(); ++i) {
        std::vector<int> segment(data.begin() + i, data.begin() + i + kernel.size());
        int convolution = 0;
        for (size_t j = 0; j < segment.size(); ++j) {
            convolution += segment[j] * kernel[j];
        }
        result.push_back(convolution);
    }
    return result;
}

std::vector<int> apply_boundary_conditions(const std::vector<int>& data, const std::string& boundary_type = "reflect") {
    if (boundary_type == "reflect") {
        std::vector<int> extended_data = data;
        for (int i = data.size() - 2; i >= 0; --i) {
            extended_data.push_back(data[i]);
        }
        return extended_data;
    } else if (boundary_type == "zero") {
        std::vector<int> extended_data = data;
        extended_data.insert(extended_data.end(), data.size(), 0);
        return extended_data;
    } else if (boundary_type == "constant") {
        std::vector<int> extended_data = data;
        extended_data.insert(extended_data.end(), data.size(), data.back());
        return extended_data;
    } else {
        return data;
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> kernel = {1, 0, -1};
    std::vector<int> extended_data = apply_boundary_conditions(data);
    std::vector<int> filtered_data = filter_signal(extended_data, kernel);
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << filtered_data[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}