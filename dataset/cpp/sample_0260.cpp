#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Filter {
public:
    Filter(const std::vector<double>& coefficients) : coeffs(coefficients), state(coefficients.size() - 1, 0.0) {}

    std::vector<double> apply(const std::vector<double>& signal) {
        std::vector<double> output;
        output.reserve(signal.size() - coeffs.size() + 1);
        for (size_t i = 0; i <= signal.size() - coeffs.size(); ++i) {
            double sum = 0.0;
            for (size_t j = 0; j < coeffs.size(); ++j) {
                sum += coeffs[j] * signal[i + j];
            }
            output.push_back(sum);
        }
        update_state(signal, output);
        return output;
    }

    void update_state(const std::vector<double>& signal, const std::vector<double>& output) {
        std::vector<double> new_state;
        new_state.insert(new_state.end(), signal.end() - (coeffs.size() - 1), signal.end());
        new_state.insert(new_state.end(), output.begin(), output.end());
        state.assign(new_state.end() - (coeffs.size() - 1), new_state.end());
    }

private:
    std::vector<double> coeffs;
    std::vector<double> state;
};

class BoundaryProcessor {
public:
    BoundaryProcessor(Filter& filter_obj, const std::pair<double, double>& boundary_values) 
        : filter(filter_obj), boundaries(boundary_values) {}

    std::vector<double> process(const std::vector<double>& data) {
        std::vector<double> filtered_data = filter.apply(data);
        std::vector<double> clipped_data = clip(filtered_data);
        return clipped_data;
    }

    std::vector<double> clip(const std::vector<double>& data) {
        std::vector<double> clipped_data(data.size());
        std::transform(data.begin(), data.end(), clipped_data.begin(), [this](double value) {
            return std::max(boundaries.first, std::min(value, boundaries.second));
        });
        return clipped_data;
    }

private:
    Filter& filter;
    std::pair<double, double> boundaries;
};

class DataAnalyzer {
public:
    DataAnalyzer(BoundaryProcessor& processor) : processor(processor) {}

    std::vector<double> analyze(const std::vector<double>& input_data) {
        return processor.process(input_data);
    }

private:
    BoundaryProcessor& processor;
};

void main() {
    std::vector<double> coefficients = {0.05, 0.1, 0.2, 0.1, 0.05};
    Filter filter_obj(coefficients);
    std::pair<double, double> boundary_values = {-1.0, 1.0};
    BoundaryProcessor processor(filter_obj, boundary_values);
    DataAnalyzer analyzer(processor);
    std::vector<double> input_data(1000);
    std::iota(input_data.begin(), input_data.end(), 0.0);
    std::vector<double> result = analyzer.analyze(input_data);
    for (double value : result) {
        std::cout << value << " ";
    }
}

int main() {
    main();
    return 0;
}