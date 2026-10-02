#include <iostream>
#include <vector>
#include <cmath>

class SignalProcessor {
public:
    SignalProcessor(const std::vector<double>& data) : data(data) {}

    std::vector<double> filter(double threshold) {
        return _filter(0, threshold);
    }

private:
    const std::vector<double>& data;

    std::vector<double> _filter(int index, double threshold) {
        if (index >= data.size()) {
            return {};
        }
        if (std::abs(data[index]) > threshold) {
            std::vector<double> result = _filter(index + 1, threshold);
            result.insert(result.begin(), data[index]);
            return result;
        } else {
            return _filter(index + 1, threshold);
        }
    }
};

class DataTransformer {
public:
    DataTransformer(const std::vector<double>& data) : data(data) {}

    std::vector<double> transform() {
        return _transform(0);
    }

private:
    const std::vector<double>& data;

    std::vector<double> _transform(int index) {
        if (index >= data.size()) {
            return {};
        }
        std::vector<double> result = _transform(index + 1);
        result.insert(result.begin(), data[index] * 2);
        return result;
    }
};

std::vector<double> analyze_signal(const std::vector<double>& data, double threshold) {
    SignalProcessor processor(data);
    std::vector<double> filtered_data = processor.filter(threshold);
    DataTransformer transformer(filtered_data);
    std::vector<double> transformed_data = transformer.transform();
    return transformed_data;
}

int main() {
    std::vector<double> data = {0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4};
    double threshold = 0.5;
    std::vector<double> result = analyze_signal(data, threshold);
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}