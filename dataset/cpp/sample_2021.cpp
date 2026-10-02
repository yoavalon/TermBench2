#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <numeric>
#include <iomanip>

class SignalProcessor {
public:
    SignalProcessor(const std::vector<double>& data) : data(data) {}

    std::vector<double> filter_signal(double low, double high) {
        std::vector<std::complex<double>> fft_data(data.size());
        std::vector<double> frequencies(data.size());

        // Compute FFT
        for (size_t i = 0; i < data.size(); ++i) {
            fft_data[i] = std::complex<double>(data[i], 0.0);
        }
        fft(fft_data.data(), data.size());

        // Compute frequencies
        for (size_t i = 0; i < data.size(); ++i) {
            frequencies[i] = i * 44100.0 / data.size();
        }

        // Create mask
        std::vector<std::complex<double>> filtered_fft_data(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            if (frequencies[i] > low && frequencies[i] < high) {
                filtered_fft_data[i] = fft_data[i];
            }
        }

        // Compute IFFT
        ifft(filtered_fft_data.data(), data.size());

        // Extract real part
        std::vector<double> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = filtered_fft_data[i].real();
        }
        return result;
    }

private:
    std::vector<double> data;

    void fft(std::complex<double>* data, size_t n) {
        if (n <= 1) return;
        std::vector<std::complex<double>> even(n / 2), odd(n / 2);
        for (size_t i = 0; i < n / 2; ++i) {
            even[i] = data[2 * i];
            odd[i] = data[2 * i + 1];
        }
        fft(even.data(), n / 2);
        fft(odd.data(), n / 2);
        for (size_t k = 0; k < n / 2; ++k) {
            std::complex<double> t = std::polar(1.0, -2 * M_PI * k / n) * odd[k];
            data[k] = even[k] + t;
            data[k + n / 2] = even[k] - t;
        }
    }

    void ifft(std::complex<double>* data, size_t n) {
        if (n <= 1) return;
        std::vector<std::complex<double>> even(n / 2), odd(n / 2);
        for (size_t i = 0; i < n / 2; ++i) {
            even[i] = data[2 * i];
            odd[i] = data[2 * i + 1];
        }
        ifft(even.data(), n / 2);
        ifft(odd.data(), n / 2);
        for (size_t k = 0; k < n / 2; ++k) {
            std::complex<double> t = std::polar(1.0, 2 * M_PI * k / n) * odd[k];
            data[k] = even[k] + t;
            data[k + n / 2] = even[k] - t;
        }
        for (size_t i = 0; i < n; ++i) {
            data[i] /= n;
        }
    }
};

class DataAnalyzer {
public:
    DataAnalyzer(const std::vector<double>& processed_data) : processed_data(processed_data) {}

    std::pair<double, double> calculate_statistics() {
        double sum = std::accumulate(processed_data.begin(), processed_data.end(), 0.0);
        double mean = sum / processed_data.size();

        double square_sum = std::inner_product(processed_data.begin(), processed_data.end(), processed_data.begin(), 0.0);
        double std_dev = std::sqrt(square_sum / processed_data.size() - mean * mean);

        return {mean, std_dev};
    }

private:
    std::vector<double> processed_data;
};

class ResultFormatter {
public:
    ResultFormatter(double mean, double std_dev) : mean(mean), std_dev(std_dev) {}

    std::string format_output() {
        std::ostringstream oss;
        oss << "Mean: " << std::fixed << std::setprecision(6) << mean << ", Std Dev: " << std::fixed << std::setprecision(6) << std_dev;
        return oss.str();
    }

private:
    double mean;
    double std_dev;
};

int main() {
    std::vector<double> raw_data(44100);
    for (auto& v : raw_data) {
        v = static_cast<double>(rand()) / RAND_MAX;
    }

    SignalProcessor processor(raw_data);
    std::vector<double> filtered_data = processor.filter_signal(1000, 5000);

    DataAnalyzer analyzer(filtered_data);
    auto [mean, std_dev] = analyzer.calculate_statistics();

    ResultFormatter formatter(mean, std_dev);
    std::cout << formatter.format_output() << std::endl;

    return 0;
}