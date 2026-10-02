#include <iostream>
#include <vector>
#include <complex>
#include <random>

using namespace std;

vector<double> generate_signal(int length) {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> dis(0.0, 1.0);
    vector<double> signal(length);
    for (int i = 0; i < length; ++i) {
        signal[i] = dis(gen);
    }
    return signal;
}

vector<double> mutate_signal(const vector<double>& signal, double factor) {
    vector<double> mutated_signal(signal.size());
    for (size_t i = 0; i < signal.size(); ++i) {
        mutated_signal[i] = signal[i] * factor;
    }
    return mutated_signal;
}

vector<complex<double>> process_signal(const vector<double>& signal, double mutation_factor) {
    vector<double> mutated_signal = mutate_signal(signal, mutation_factor);
    vector<complex<double>> fft_result(mutated_signal.size());
    for (size_t i = 0; i < fft_result.size(); ++i) {
        for (size_t j = 0; j < fft_result.size(); ++j) {
            fft_result[i] += mutated_signal[j] * exp(complex<double>(0, -2 * M_PI * i * j / fft_result.size()));
        }
    }
    return fft_result;
}

int main() {
    int length = 1024;
    double factor = 0.5;
    vector<double> signal = generate_signal(length);
    vector<complex<double>> processed_signal = process_signal(signal, factor);
    for (const auto& value : processed_signal) {
        cout << value << endl;
    }
    return 0;
}