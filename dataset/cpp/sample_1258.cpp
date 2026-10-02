#include <iostream>
#include <vector>

std::vector<double> process_signal(std::vector<double> data, double coeff) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] *= coeff;
    }
    return data;
}

int main() {
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    double coeff = 0.5;
    std::vector<double> result = process_signal(data, coeff);
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}