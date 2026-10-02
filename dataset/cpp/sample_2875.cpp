#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

std::vector<double> generate_sequence(int length) {
    std::vector<double> sequence(length);
    for (int i = 0; i < length; ++i) {
        sequence[i] = std::sin(2 * M_PI * i / length) + std::cos(4 * M_PI * i / length);
    }
    return sequence;
}

std::vector<double> hanning(int length) {
    std::vector<double> window(length);
    for (int i = 0; i < length; ++i) {
        window[i] = 0.5 * (1 - std::cos(2 * M_PI * i / length));
    }
    return window;
}

std::vector<std::complex<double>> fft(const std::vector<double>& signal) {
    int n = signal.size();
    if (n <= 1) return {std::complex<double>(signal[0], 0)};

    std::vector<std::complex<double>> even = fft(std::vector<double>(signal.begin(), signal.begin() + n / 2));
    std::vector<std::complex<double>> odd = fft(std::vector<double>(signal.begin() + n / 2, signal.end()));

    std::vector<std::complex<double>> result(n);
    for (int k = 0; k < n / 2; ++k) {
        std::complex<double> t = std::polar(1.0, -2 * M_PI * k / n) * odd[k];
        result[k] = even[k] + t;
        result[k + n / 2] = even[k] - t;
    }
    return result;
}

std::vector<double> ifft(const std::vector<std::complex<double>>& signal) {
    int n = signal.size();
    std::vector<std::complex<double>> conjugate(signal.size());
    for (int i = 0; i < n; ++i) {
        conjugate[i] = std::conj(signal[i]);
    }
    std::vector<std::complex<double>> result = fft(conjugate);
    std::vector<double> real_part(n);
    for (int i = 0; i < n; ++i) {
        real_part[i] = result[i].real() / n;
    }
    return real_part;
}

void process_signal(std::vector<double>& signal) {
    while (true) {
        std::vector<double> window = hanning(signal.size());
        std::vector<double> filtered_signal(signal.size());
        for (int i = 0; i < signal.size(); ++i) {
            filtered_signal[i] = signal[i] * window[i];
        }
        std::vector<std::complex<double>> processed_signal = fft(filtered_signal);
        signal = ifft(processed_signal);
    }
}

int main() {
    int sequence_length = 1024;
    std::vector<double> initial_sequence = generate_sequence(sequence_length);
    process_signal(initial_sequence);
    return 0;
}