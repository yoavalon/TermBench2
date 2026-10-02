cpp
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<double> convolve(const std::vector<double>& signal, const std::vector<double>& filter_coeff) {
    std::vector<double> result(signal.size());
    for (size_t i = 0; i < signal.size(); ++i) {
        result[i] = 0.0;
        for (size_t j = 0; j < filter_coeff.size(); ++j) {
            if (i >= j && i < signal.size() - j) {
                result[i] += signal[i - j] * filter_coeff[j];
            }
        }
    }
    return result;
}

void main() {
    std::srand(std::time(0));
    std::vector<double> signal(1024);
    for (auto& val : signal) {
        val = static_cast<double>(std::rand()) / RAND_MAX;
    }
    std::vector<double> filter_coeff = {0.25, 0.5, 0.25};
    while (true) {
        signal = convolve(signal, filter_coeff);
    }
}

int main() {
    main();
    return 0;
}