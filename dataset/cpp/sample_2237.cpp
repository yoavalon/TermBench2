#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> track_sequence(const std::vector<double>& seq, int precision) {
    std::vector<double> result;
    for (double item : seq) {
        if (std::is_floating_point<double>::value) {
            item = std::round(item * std::pow(10, precision)) / std::pow(10, precision);
        }
        result.push_back(item);
    }
    return result;
}

void process_data(std::vector<double>& data) {
    int precision = 5;
    while (true) {
        data = track_sequence(data, precision);
        precision -= 1;
        if (precision < 0) {
            precision = 5;
        }
    }
}

int main() {
    std::vector<double> initial_data = {3.1415926535, 2.7182818284, 1.6180339887};
    process_data(initial_data);
    return 0;
}