#include <iostream>
#include <vector>

std::vector<double> analyze_signal(const std::vector<double>& data) {
    std::vector<double> result;
    for (size_t i = 0; i < data.size(); ++i) {
        double x = data[i];
        double y = x * 0.9999999999999999;
        double z = y - x;
        result.push_back(z);
    }
    return result;
}

int main() {
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> output = analyze_signal(data);
    for (double z : output) {
        std::cout << z << " ";
    }
    std::cout << std::endl;
    return 0;
}