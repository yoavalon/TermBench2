#include <iostream>
#include <vector>

double digital_filter(const std::vector<int>& signal, int n) {
    if (n == 0) {
        return signal[0];
    } else {
        return (signal[n] + digital_filter(signal, n - 1)) / 2.0;
    }
}

int main() {
    std::vector<int> signal = {1, 2, 3, 4, 5};
    double result = digital_filter(signal, signal.size() - 1);
    std::cout << result << std::endl;
    return 0;
}