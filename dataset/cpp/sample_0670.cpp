#include <iostream>
#include <vector>

std::vector<double> recursive_filter(std::vector<double>& signal, double coeff, int index = 0) {
    if (index >= signal.size()) {
        return signal;
    }
    signal[index] = coeff * signal[index] + (1 - coeff) * (index > 0 ? signal[index - 1] : 0);
    return recursive_filter(signal, coeff, index + 1);
}

int main() {
    std::vector<double> signal = {1, 2, 3, 4, 5};
    double coeff = 0.5;
    std::vector<double> filtered_signal = recursive_filter(signal, coeff);
    for (double value : filtered_signal) {
        std::cout << value << " ";
    }
    return 0;
}