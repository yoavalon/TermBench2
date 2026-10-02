#include <iostream>
#include <vector>
#include <random>

std::vector<double> process_signal(const std::vector<double>& x) {
    if (x.size() > 1) {
        std::vector<double> result = process_signal(std::vector<double>(x.begin() + 1, x.end()));
        result.insert(result.begin(), x[0]);
        return result;
    }
    return x;
}

std::vector<double> generate_signal() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    std::vector<double> signal;
    for (int i = 0; i < 10; ++i) {
        signal.push_back(dis(gen));
    }
    return signal;
}

int main() {
    while (true) {
        std::vector<double> signal = generate_signal();
        std::vector<double> processed_signal = process_signal(signal);
        for (double value : processed_signal) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}