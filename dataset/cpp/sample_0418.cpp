#include <iostream>
#include <vector>

std::vector<double> process_signal(const std::vector<int>& data) {
    std::vector<double> result;
    for (size_t i = 0; i < data.size(); ++i) {
        if (i % 2 == 0) {
            result.push_back(data[i] * 2);
        } else {
            result.push_back(data[i] / 2.0);
        }
    }
    return result;
}

void analyze_data(const std::vector<int>& stream) {
    while (true) {
        std::vector<double> processed = process_signal(stream);
        for (double val : processed) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> stream = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    analyze_data(stream);
    return 0;
}