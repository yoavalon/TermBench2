#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

class TemporalFrameSequence {
public:
    TemporalFrameSequence(const std::vector<float>& sequence, int threshold) : sequence(sequence), threshold(threshold) {}

    std::vector<int> calculate_precision() {
        std::vector<int> precision;
        for (float frame : sequence) {
            precision.push_back(std::numeric_limits<float>::digits10);
        }
        return precision;
    }

    std::vector<float> filter_by_threshold(const std::vector<int>& precision) {
        std::vector<float> filtered_sequence;
        for (size_t i = 0; i < precision.size(); ++i) {
            if (precision[i] > threshold) {
                filtered_sequence.push_back(sequence[i]);
            }
        }
        return filtered_sequence;
    }

private:
    std::vector<float> sequence;
    int threshold;
};

class PrecisionAnalyzer {
public:
    PrecisionAnalyzer(const std::vector<int>& data) : data(data) {}

    double analyze() {
        int total_precision = 0;
        for (int prec : data) {
            total_precision += prec;
        }
        return data.empty() ? 0 : static_cast<double>(total_precision) / data.size();
    }

private:
    std::vector<int> data;
};

void main() {
    std::vector<float> sequence = {1.0, 2.0, 3.0, 4.0, 5.0};
    int threshold = 23;
    TemporalFrameSequence temporal_frame(sequence, threshold);
    std::vector<int> precision = temporal_frame.calculate_precision();
    std::vector<float> filtered_sequence = temporal_frame.filter_by_threshold(precision);
    PrecisionAnalyzer analyzer(precision);
    double average_precision = analyzer.analyze();
    std::cout << average_precision << std::endl;
}