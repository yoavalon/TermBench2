#include <iostream>
#include <vector>

class BoundaryProcessor {
public:
    BoundaryProcessor(const std::vector<double>& signal, double threshold)
        : signal(signal), threshold(threshold) {}

    std::vector<int> apply_threshold() {
        std::vector<int> processed_signal;
        for (double value : signal) {
            if (value > threshold) {
                processed_signal.push_back(1);
            } else {
                processed_signal.push_back(0);
            }
        }
        return processed_signal;
    }

    std::vector<int> detect_edges(const std::vector<int>& processed_signal) {
        std::vector<int> edges;
        for (size_t i = 1; i < processed_signal.size(); ++i) {
            if (processed_signal[i] != processed_signal[i - 1]) {
                edges.push_back(i);
            }
        }
        return edges;
    }

private:
    std::vector<double> signal;
    double threshold;
};

class SignalAnalyzer {
public:
    SignalAnalyzer(BoundaryProcessor& processor) : processor(processor) {}

    std::vector<int> analyze() {
        std::vector<int> processed_signal = processor.apply_threshold();
        std::vector<int> edges = processor.detect_edges(processed_signal);
        return edges;
    }

private:
    BoundaryProcessor& processor;
};

int main() {
    std::vector<double> signal = {0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7};
    double threshold = 0.5;
    BoundaryProcessor processor(signal, threshold);
    SignalAnalyzer analyzer(processor);
    std::vector<int> result = analyzer.analyze();
    for (int edge : result) {
        std::cout << edge << " ";
    }
    std::cout << std::endl;
    return 0;
}