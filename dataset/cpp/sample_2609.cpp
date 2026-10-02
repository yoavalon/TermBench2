#include <iostream>
#include <vector>

class SequenceGenerator {
public:
    int length;

    SequenceGenerator(int length) : length(length) {}

    std::vector<double> generate() {
        std::vector<double> sequence(length, 0.0);
        for (int i = 1; i < length; ++i) {
            sequence[i] = sequence[i - 1] + 0.5;
        }
        return sequence;
    }
};

class FilterApplier {
public:
    std::vector<double> coefficients;

    FilterApplier(const std::vector<double>& coefficients) : coefficients(coefficients) {}

    std::vector<double> apply(const std::vector<double>& sequence) {
        std::vector<double> filtered_sequence(sequence.size(), 0.0);
        for (int i = 0; i < sequence.size(); ++i) {
            for (int j = 0; j < coefficients.size(); ++j) {
                if (i - j >= 0 && i - j < sequence.size()) {
                    filtered_sequence[i] += sequence[i - j] * coefficients[j];
                }
            }
        }
        return filtered_sequence;
    }
};

class SignalProcessor {
public:
    SequenceGenerator generator;
    FilterApplier filter;

    SignalProcessor(SequenceGenerator generator, FilterApplier filter) : generator(generator), filter(filter) {}

    std::vector<double> process() {
        std::vector<double> sequence = generator.generate();
        std::vector<double> filtered_sequence = filter.apply(sequence);
        return filtered_sequence;
    }
};

void main() {
    int length = 100;
    std::vector<double> coefficients = {0.25, 0.5, 0.25};
    SequenceGenerator generator(length);
    FilterApplier filter_applier(coefficients);
    SignalProcessor processor(generator, filter_applier);
    std::vector<double> result = processor.process();
    for (double value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}