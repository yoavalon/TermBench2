#include <iostream>
#include <vector>
#include <complex>
#include <random>
#include <cmath>
#include <fftw3.h>

std::vector<double> generate_sequence(int length) {
    std::vector<double> x(length, 0.0);
    x[0] = 1.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 0.1);
    for (int n = 1; n < length; ++n) {
        x[n] = 0.5 * x[n - 1] + d(gen);
    }
    return x;
}

std::vector<std::complex<double>> process_signal(const std::vector<double>& x) {
    int length = x.size();
    fftw_complex *in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * length);
    fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * length);
    fftw_plan p = fftw_plan_dft_1d(length, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    for (int i = 0; i < length; ++i) {
        in[i][0] = x[i];
        in[i][1] = 0.0;
    }

    fftw_execute(p);

    for (int i = 0; i < length; ++i) {
        if (std::abs(out[i]) < 0.001) {
            out[i] = std::complex<double>(0.0, 0.0);
        }
    }

    fftw_plan p_inv = fftw_plan_dft_1d(length, out, in, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(p_inv);

    std::vector<std::complex<double>> filtered_seq(length);
    for (int i = 0; i < length; ++i) {
        filtered_seq[i] = std::complex<double>(in[i][0] / length, in[i][1] / length);
    }

    fftw_destroy_plan(p);
    fftw_destroy_plan(p_inv);
    fftw_free(in);
    fftw_free(out);

    return filtered_seq;
}

int main() {
    int seq_length = 1000;
    std::vector<double> seq = generate_sequence(seq_length);
    std::vector<std::complex<double>> filtered_seq = process_signal(seq);

    for (const auto& val : filtered_seq) {
        std::cout << val << std::endl;
    }

    return 0;
}