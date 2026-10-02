#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

class SignalProcessor {
public:
    SignalProcessor(const std::vector<double>& data) : data(data) {}

    std::vector<double> apply_filter(const std::vector<double>& kernel) {
        std::vector<double> result(data.size(), 0.0);
        for (size_t i = 0; i < data.size(); ++i) {
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
        std::vector<double> normalized_data(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            normalized_data[i] = (data[i] - min_val) / (max_val - min_val);
        }
        return normalized_data;
    }

private:
    std::vector<double> data;
};

class SequenceGenerator {
public:
    SequenceGenerator(size_t length, double amplitude) : length(length), amplitude(amplitude) {}

    std::vector<double> generate_sine_wave() {
        std::vector<double> x(length);
        for (size_t i = 0; i < length; ++i) {
            x[i] = 2 * M_PI * i / length;
        }
        std::vector<double> sine_wave(length);
        for (size_t i = 0; i < length; ++i) {
            sine_wave[i] = amplitude * sin(x[i]);
        }
        return sine_wave;
    }

    std::vector<double> generate_square_wave() {
        std::vector<double> x(length);
        for (size_t i = 0; i < length; ++i) {
            x[i] = 2 * M_PI * i / length;
        }
        std::vector<double> square_wave(length);
        for (size_t i = 0; i < length; ++i) {
            square_wave[i] = amplitude * (sin(x[i]) >= 0 ? 1 : -1);
        }
        return square_wave;
    }

private:
    size_t length;
    double amplitude;
};

int main() {
    SequenceGenerator seq_gen(100, 1);
    std::vector<double> sine_wave = seq_gen.generate_sine_wave();
    std::vector<double> square_wave = seq_gen.generate_square_wave();
    SignalProcessor processor(sine_wave);
    std::vector<double> filtered_sine = processor.apply_filter({0.25, 0.5, 0.25});
    std::vector<double> normalized_sine = processor.normalize(filtered_sine);
    processor.data = square_wave;
    std::vector<double> filtered_square = processor.apply_filter({-0.25, 0.5, -0.25});
    std::vector<double> normalized_square = processor.normalize(filtered_square);
    std::cout << "Normalized Sine Wave: ";
    for (double val : normalized_sine) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "Normalized Square Wave: ";
    for (double val : normalized_square) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}