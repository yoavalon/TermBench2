#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <numeric>

std::vector<double> process_signal(const std::vector<double>& data) {
    std::vector<double> filtered(data.size() - 2);
    std::vector<double> kernel = {0.25, 0.5, 0.25};

    for (size_t i = 0; i < data.size() - 2; ++i) {
        filtered[i] = data[i] * kernel[0] + data[i + 1] * kernel[1] + data[i + 2] * kernel[2];
    }

    std::vector<std::complex<double>> transformed(filtered.size());
    for (size_t k = 0; k < filtered.size(); ++k) {
        for (size_t n = 0; n < filtered.size(); ++n) {
            transformed[k] += filtered[n] * std::exp(-2 * M_PI * std::complex<double>(0, 1) * k * n / filtered.size());
        }
    }

    std::vector<double> processed(filtered.size());
    for (size_t i = 0; i < processed.size(); ++i) {
        processed[i] = std::abs(transformed[i]);
    }

    return processed;
}

int main() {
    std::vector<double> main_data = {1, 2, 3, 4, 5};
    std::vector<double> result = process_signal(main_data);

    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}