#include <iostream>
#include <vector>
#include <cmath>

class DigitalFilter {
public:
    std::vector<double> a;
    std::vector<double> b;
    std::vector<double> x;
    std::vector<double> y;

    DigitalFilter(const std::vector<double>& coefficients_a, const std::vector<double>& coefficients_b) {
        a = coefficients_a;
        b = coefficients_b;
        x = std::vector<double>(a.size() - 1, 0.0);
        y = std::vector<double>(b.size() - 1, 0.0);
    }

    double process(double sample) {
        for (size_t i = 0; i < x.size() - 1; ++i) {
            x[i] = x[i + 1];
        }
        x.back() = sample;

        double output = 0.0;
        for (size_t i = 0; i < b.size(); ++i) {
            output += b[i] * x[i];
        }
        for (size_t i = 1; i < a.size(); ++i) {
            output -= a[i] * y[i - 1];
        }

        for (size_t i = 0; i < y.size() - 1; ++i) {
            y[i] = y[i + 1];
        }
        y.back() = output;

        return output;
    }
};

class SignalGenerator {
public:
    double frequency;
    double sample_rate;
    double duration;

    SignalGenerator(double freq, double sr, double dur) : frequency(freq), sample_rate(sr), duration(dur) {}

    std::vector<double> generate() {
        std::vector<double> t(int(sample_rate * duration));
        for (size_t i = 0; i < t.size(); ++i) {
            t[i] = i / sample_rate;
        }
        std::vector<double> signal(t.size());
        for (size_t i = 0; i < signal.size(); ++i) {
            signal[i] = std::sin(2 * M_PI * frequency * t[i]);
        }
        return signal;
    }
};

std::vector<double> filter_signal(const std::vector<double>& signal, const std::vector<double>& coefficients_a, const std::vector<double>& coefficients_b, double sample_rate, double duration) {
    DigitalFilter filter(coefficients_a, coefficients_b);
    std::vector<double> filtered_signal;
    for (double sample : signal) {
        filtered_signal.push_back(filter.process(sample));
    }
    return filtered_signal;
}

int main() {
    std::vector<double> coefficients_a = {1, -0.9};
    std::vector<double> coefficients_b = {0.5, 0.5};
    SignalGenerator generator(5, 1000, 1);
    std::vector<double> signal = generator.generate();
    std::vector<double> filtered_signal = filter_signal(signal, coefficients_a, coefficients_b, 1000, 1);
    for (double value : filtered_signal) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}