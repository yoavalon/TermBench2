#include <iostream>
#include <vector>

std::vector<double> generate_sequence(const std::vector<int>& data) {
    std::vector<double> result;
    for (int item : data) {
        if (item > 0) {
            result.push_back(item * 2);
        } else {
            result.push_back(item / 2.0);
        }
    }
    return result;
}

void process_data(const std::vector<int>& input_stream) {
    while (true) {
        std::vector<double> processed_data = generate_sequence(input_stream);
        for (double value : processed_data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> sample_data = {10, -5, 3, -8, 0, 7};
    process_data(sample_data);
    return 0;
}