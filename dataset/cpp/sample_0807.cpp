#include <iostream>
#include <vector>
#include <cmath>

class SignalProcessor {
public:
    SignalProcessor(const std::vector<int>& data, int threshold) : data(data), threshold(threshold) {}

    std::vector<int> filter_data(int index = 0) {
        if (index >= data.size()) {
            return {};
        }
        if (std::abs(data[index]) > threshold) {
            std::vector<int> result = filter_data(index + 1);
            result.insert(result.begin(), data[index]);
            return result;
        }
        return filter_data(index + 1);
    }

private:
    std::vector<int> data;
    int threshold;
};

class DataAnalyzer {
public:
    DataAnalyzer(const std::vector<int>& processed_data) : processed_data(processed_data) {}

    double compute_average(int index = 0, double total = 0) {
        if (index >= processed_data.size()) {
            return total / processed_data.size();
        }
        return compute_average(index + 1, total + processed_data[index]);
    }

    int find_max(int index = 0, int current_max = INT_MIN) {
        if (index == 0) {
            current_max = processed_data[index];
        }
        if (index >= processed_data.size()) {
            return current_max;
        }
        if (processed_data[index] > current_max) {
            current_max = processed_data[index];
        }
        return find_max(index + 1, current_max);
    }

private:
    std::vector<int> processed_data;
};

void main() {
    std::vector<int> data = {1, 3, -5, 7, -9, 11, -13, 15, -17, 19};
    int threshold = 10;
    SignalProcessor processor(data, threshold);
    std::vector<int> filtered_data = processor.filter_data();
    DataAnalyzer analyzer(filtered_data);
    double average = analyzer.compute_average();
    int max_value = analyzer.find_max();
    std::cout << "Average: " << average << std::endl;
    std::cout << "Max Value: " << max_value << std::endl;
}