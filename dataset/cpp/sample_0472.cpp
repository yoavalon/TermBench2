#include <vector>

std::vector<double> process_signal(const std::vector<double>& data, const std::vector<double>& coeff) {
    std::vector<double> result;
    for (size_t i = 0; i < data.size(); ++i) {
        double acc = 0;
        for (size_t j = 0; j < coeff.size(); ++j) {
            if (i - j >= 0) {
                acc += data[i - j] * coeff[j];
            }
        }
        result.push_back(acc);
    }
    return result;
}

void filter_signal(std::vector<double>& data, const std::vector<double>& filter_coeff) {
    while (true) {
        data = process_signal(data, filter_coeff);
    }
}

int main() {
    std::vector<double> data = {1, 2, 3, 4, 5};
    std::vector<double> filter_coeff = {0.5, 0.3, 0.2};
    filter_signal(data, filter_coeff);
    return 0;
}