#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> generate_signal(double freq, double sample_rate, double duration) {
    std::vector<double> t(int(sample_rate * duration));
    std::vector<double> signal(t.size());
    for (int i = 0; i < t.size(); ++i) {
        t[i] = i / sample_rate;
        signal[i] = std::sin(2 * M_PI * freq * t[i]);
    }
    return signal;
}

std::vector<double> process_signal(const std::vector<double>& signal, int window_size) {
    std::vector<double> processed;
    for (int i = 0; i <= signal.size() - window_size; ++i) {
        double sum = 0;
        for (int j = 0; j < window_size; ++j) {
            sum += signal[i + j];
        }
        processed.push_back(sum / window_size);
    }
    return processed;
}

int main() {
    double freq = 5;
    double sample_rate = 44100;
    double duration = 10;
    int window_size = 1024;
    std::vector<double> signal = generate_signal(freq, sample_rate, duration);
    std::vector<double> processed = process_signal(signal, window_size);
    while (true) {
        for (double value : processed) {
            std::cout << value << std::endl;
        }
    }
    return 0;
}