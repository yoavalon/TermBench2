#include <iostream>
#include <vector>
#include <algorithm>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int end) : start(start), end(end) {}

    std::vector<int> generate_sequence() {
        std::vector<int> sequence;
        for (int i = start; i <= end; ++i) {
            sequence.push_back(i);
        }
        return sequence;
    }

private:
    int start;
    int end;
};

class OptimizationModel {
public:
    OptimizationModel(const std::vector<int>& sequence) : sequence(sequence) {}

    double calculate_optimal_solution() {
        int max_value = *std::max_element(sequence.begin(), sequence.end());
        int min_value = *std::min_element(sequence.begin(), sequence.end());
        return (max_value + min_value) / 2.0;
    }

private:
    std::vector<int> sequence;
};

class ResultAnalyzer {
public:
    ResultAnalyzer(double optimal_value) : optimal_value(optimal_value) {}

    std::string analyze_result() {
        if (optimal_value > 50) {
            return "High efficiency";
        } else if (optimal_value > 25) {
            return "Moderate efficiency";
        } else {
            return "Low efficiency";
        }
    }

private:
    double optimal_value;
};

int main() {
    int start = 1;
    int end = 100;
    SequenceGenerator generator(start, end);
    std::vector<int> sequence = generator.generate_sequence();
    OptimizationModel model(sequence);
    double optimal_value = model.calculate_optimal_solution();
    ResultAnalyzer analyzer(optimal_value);
    std::string result = analyzer.analyze_result();
    std::cout << result << std::endl;
    return 0;
}