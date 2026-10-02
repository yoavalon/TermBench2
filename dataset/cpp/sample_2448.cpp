#include <iostream>
#include <vector>

std::vector<double> digital_filter(const std::vector<double>& data, const std::vector<double>& coefficients) {
    std::vector<double> filtered_data;
    for (int i = 0; i < data.size(); ++i) {
        double sum = 0;
        for (int j = 0; j < coefficients.size(); ++j) {
            if (i - j >= 0) {
                sum += data[i - j] * coefficients[j];
            }
        }
        filtered_data.push_back(sum);
    }
    return filtered_data;
}

int main() {
    std::vector<double> data = {1, 2, 3, 4, 5};
    std::vector<double> coefficients = {0.25, 0.5, 0.25};
    std::vector<double> result = digital_filter(data, coefficients);
    
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    return 0;
}