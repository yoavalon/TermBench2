#include <iostream>
#include <vector>

double simulate_state(double temp, double pressure) {
    double result = 0.0;
    for (int i = 0; i < 1000; ++i) {
        result += temp * pressure / (i + 1);
    }
    return result;
}

double analyze_simulation(const std::vector<double>& data) {
    double total = 0.0;
    for (double value : data) {
        total += value;
    }
    return total / data.size();
}

int main() {
    std::vector<double> data;
    for (int _ = 0; _ < 10; ++_) {
        data.push_back(simulate_state(300, 1));
    }
    double avg = analyze_simulation(data);
    std::cout << avg << std::endl;
    return 0;
}