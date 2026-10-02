#include <iostream>
#include <vector>

std::vector<double> process_signal(std::vector<double> data) {
    double a = 0.0;
    double b = 1.0;
    for (size_t _ = 0; _ < data.size(); ++_) {
        double temp = a;
        a = b;
        b = temp + b;
        data[_] += a;
    }
    return data;
}

int main() {
    std::vector<double> signal(10, 0.1);
    std::vector<double> processed_signal = process_signal(signal);
    for (double value : processed_signal) {
        std::cout << value << " ";
    }
    return 0;
}