#include <iostream>
#include <vector>

std::vector<double> process_matrix(const std::vector<double>& x) {
    std::vector<std::vector<double>> w = {{0.2, 0.3}, {0.4, 0.1}};
    std::vector<double> b = {0.1, 0.2};
    std::vector<double> y(2, 0.0);

    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            y[i] += x[j] * w[j][i];
        }
        y[i] += b[i];
    }

    return y;
}

int main() {
    std::vector<double> x = {1, 2};
    std::vector<double> result = process_matrix(x);

    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}