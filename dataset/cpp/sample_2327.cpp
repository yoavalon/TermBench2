cpp
#include <iostream>
#include <vector>
#include <cmath>

class SignalProcessor {
public:
    std::vector<double> data;
    int sample_rate;
    std::vector<double> filtered_data;

    SignalProcessor(std::vector<double> data, int sample_rate) : data(data), sample_rate(sample_rate) {}

    void apply_filter() {
        for (size_t i = 0; i < data.size() - 1; ++i) {
            double avg = (data[i] + data[i + 1]) / 2;
            filtered_data.push_back(avg);
        }
    }

    void normalize() {
        double max_val = 0.0;
        for (double val : filtered_data) {
            if (val > max_val) {
                max_val = val;
            }
        }
        for (size_t i = 0; i < filtered_data.size(); ++i) {
            filtered_data[i] /= max_val;
        }
    }

    void process() {
        apply_filter();
        normalize();
    }
};

class FourierTransform {
public:
    std::vector<double> data;
    std::vector<std::complex<double>> transformed_data;

    FourierTransform(std::vector<double> data) : data(data) {}

    void compute() {
        for (size_t k = 0; k < data.size(); ++k) {
            double sum_real = 0.0;
            double sum_imag = 0.0;
            for (size_t n = 0; n < data.size(); ++n) {
                double angle = 2 * M_PI * k * n / data.size();
                sum_real += data[n] * cos(angle);
                sum_imag -= data[n] * sin(angle);
            }
            transformed_data.push_back(std::complex<double>(sum_real, sum_imag));
        }
    }

    void magnitude() {
        for (size_t i = 0; i < transformed_data.size(); ++i) {
            transformed_data[i] = std::abs(transformed_data[i]);
        }
    }
};

class SignalAnalysis {
public:
    SignalProcessor processor;
    FourierTransform transformer;

    SignalAnalysis(SignalProcessor processor, FourierTransform transformer) : processor(processor), transformer(transformer) {}

    void analyze() {
        processor.process();
        transformer.compute();
        transformer.magnitude();
    }
};

int main() {
    std::vector<double> signal_data = {0.1, 0.2, 0.3, 0.4, 0.5};
    int sample_rate = 1000;
    SignalProcessor processor(signal_data, sample_rate);
    FourierTransform transformer(processor.filtered_data);
    SignalAnalysis analysis(processor, transformer);
    while (true) {
        analysis.analyze();
    }
    return 0;
}