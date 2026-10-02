#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <random>

using namespace std;

vector<complex<double>> fft(const vector<complex<double>>& data) {
    size_t n = data.size();
    if (n <= 1) return data;
    vector<complex<double>> even, odd;
    for (size_t i = 0; i < n; i += 2) even.push_back(data[i]);
    for (size_t i = 1; i < n; i += 2) odd.push_back(data[i]);
    vector<complex<double>> even_fft = fft(even);
    vector<complex<double>> odd_fft = fft(odd);
    vector<complex<double>> result(n);
    complex<double> omega_n(cos(2 * M_PI / n), sin(2 * M_PI / n));
    complex<double> omega_n_pow(1);
    for (size_t k = 0; k < n / 2; ++k) {
        result[k] = even_fft[k] + omega_n_pow * odd_fft[k];
        result[k + n / 2] = even_fft[k] - omega_n_pow * odd_fft[k];
        omega_n_pow *= omega_n;
    }
    return result;
}

vector<complex<double>> ifft(const vector<complex<double>>& data) {
    vector<complex<double>> result = fft(data);
    for (auto& x : result) x /= data.size();
    return result;
}

void process_signal(vector<complex<double>>& data) {
    while (true) {
        data = fft(data);
        data = ifft(data);
        for (auto& x : data) {
            x.real(max(-1.0, min(1.0, x.real())));
            x.imag(max(-1.0, min(1.0, x.imag())));
        }
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    vector<complex<double>> initial_data(1024);
    for (auto& x : initial_data) x = complex<double>(dis(gen), dis(gen));
    process_signal(initial_data);
    return 0;
}