#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class SignalProcessor {
public:
    SignalProcessor(const std::vector<double>& data) : data(data) {}

    std::vector<double> apply_filter(const std::vector<double>& kernel) {
        std::vector<double> result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result[i] = 0;
            for (size_t j = 0; j < kernel.size(); ++j) {
                if (i >= j && i < data.size() - j) {
                    result[i] += data[i - j] * kernel[j];
                }
            }
        }
        return result;
    }

    std::vector<double> normalize(const std::vector<double>& data) {
        double min_val = *std::min_element(data.begin(), data.end());
        double max_val = *std::max_element(data.begin(), data.end());
        std::vector<double> normalized(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            normalized[i] = (data[i] - min_val) / (max_val - min_val);
        }
        return normalized;
    }

private:
    std::vector<double> data;
};

class SequenceGenerator {
public:
    SequenceGenerator(size_t length) : length(length) {}

    std::vector<double> generate_sine_wave(double frequency, double amplitude, double phase) {
        std::vector<double> wave(length);
        for (size_t i = 0; i < length; ++i) {
            double t = static_cast<double>(i) / length;
            wave[i] = amplitude * std::sin(2 * M_PI * frequency * t + phase);
        }
        return wave;
    }

private:
    size_t length;
};

class Analysis {
public:
    Analysis(const std::vector<double>& processed_data) : data(processed_data) {}

    std::vector<std::complex<double>> calculate_fft() {
        std::vector<std::complex<double>> fft_result(data.size());
        for (size_t k = 0; k < data.size(); ++k) {
            std::complex<double> sum(0, 0);
            for (size_t n = 0; n < data.size(); ++n) {
                double angle = 2 * M_PI * k * n / data.size();
                std::complex<double> c(std::cos(angle), -std::sin(angle));
                sum += data[n] * c;
            }
            fft_result[k] = sum;
        }
        return fft_result;
    }

    double find_peak_frequency(const std::vector<std::complex<double>>& fft_result) {
        double peak_freq = 0;
        size_t peak_idx = 0;
        for (size_t i = 0; i < fft_result.size(); ++i) {
            if (std::abs(fft_result[i]) > std::abs(fft_result[peak_idx])) {
                peak_idx = i;
                peak_freq = static_cast<double>(i) / fft_result.size();
            }
        }
        return peak_freq;
    }

private:
    std::vector<double> data;
};

void main() {
    size_t length = 1024;
    SequenceGenerator generator(length);
    std::vector<double> signal = generator.generate_sine_wave(5, 1, 0);
    SignalProcessor processor(signal);
    std::vector<double> kernel = {0.25, 0.5, 0.25};
    std::vector<double> filtered_data = processor.apply_filter(kernel);
    std::vector<double> normalized_data = processor.normalize(filtered_data);
    Analysis analysis(normalized_data);
    std::vector<std::complex<double>> fft_result = analysis.calculate_fft();
    double peak_frequency = analysis.find_peak_frequency(fft_result);
    std::cout << "Peak Frequency: " << peak_frequency << std::endl;
}

int main() {
    main();
    return 0;
}