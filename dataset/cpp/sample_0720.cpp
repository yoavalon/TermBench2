#include <iostream>
#include <vector>

double recursive_filter(const std::vector<double>& data, int index, double factor) {
    if (index == 0) {
        return data[0];
    }
    return factor * data[index] + (1 - factor) * recursive_filter(data, index - 1, factor);
}

std::vector<double> process_signal(const std::vector<double>& data, double factor) {
    std::vector<double> processed;
    for (int i = 0; i < data.size(); ++i) {
        processed.push_back(recursive_filter(data, i, factor));
    }
    return processed;
}

int main() {
    std::vector<double> signal = {1, 2, 3, 4, 5};
    double factor = 0.5;
    std::vector<double> result = process_signal(signal, factor);
    for (double value : result) {
        std::cout << value << " ";
    }
    return 0;
}