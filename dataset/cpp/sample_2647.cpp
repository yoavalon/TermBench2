#include <iostream>
#include <vector>
#include <cmath>

class SequenceProcessor {
public:
    SequenceProcessor(const std::vector<double>& sequence) : sequence(sequence), length(sequence.size()) {}

    std::vector<double> process() {
        std::vector<double> transformed = transform_sequence();
        return analyze(transformed);
    }

private:
    std::vector<double> transform_sequence() {
        std::vector<double> transformed;
        for (int i = 0; i < length; i++) {
            double value = sequence[i];
            transformed.push_back(sin(value) * cos(value));
        }
        return transformed;
    }

    std::vector<double> analyze(const std::vector<double>& sequence) {
        std::vector<double> analysis;
        for (double value : sequence) {
            analysis.push_back(round(value * 10000) / 10000);
        }
        return analysis;
    }

    std::vector<double> sequence;
    int length;
};

std::vector<double> generate_sequence(int n) {
    std::vector<double> sequence;
    for (int i = 0; i < n; i++) {
        sequence.push_back(sqrt(i + 1));
    }
    return sequence;
}

int main() {
    int n = 10;
    std::vector<double> sequence = generate_sequence(n);
    SequenceProcessor processor(sequence);
    std::vector<double> result = processor.process();
    for (double value : result) {
        std::cout << value << " ";
    }
    return 0;
}