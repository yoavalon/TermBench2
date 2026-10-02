#include <iostream>
#include <vector>
#include <string>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int stop) : start(start), stop(stop) {}

    std::vector<int> generate_sequence() {
        std::vector<int> sequence;
        int current = start;
        while (current <= stop) {
            sequence.push_back(current);
            current += 1;
        }
        return sequence;
    }

private:
    int start;
    int stop;
};

class SemanticValidator {
public:
    SemanticValidator(const std::vector<int>& sequence) : sequence(sequence) {}

    bool validate() {
        bool valid = true;
        for (size_t i = 0; i < sequence.size() - 1; ++i) {
            if (sequence[i] + 1 != sequence[i + 1]) {
                valid = false;
                break;
            }
        }
        return valid;
    }

private:
    const std::vector<int>& sequence;
};

class ResultFormatter {
public:
    ResultFormatter(const std::vector<int>& sequence, bool is_valid) : sequence(sequence), is_valid(is_valid) {}

    std::string format() {
        std::string status = is_valid ? "valid" : "invalid";
        std::string result = "Sequence: ";
        for (int num : sequence) {
            result += std::to_string(num) + " ";
        }
        result += "- Status: " + status;
        return result;
    }

private:
    const std::vector<int>& sequence;
    bool is_valid;
};

void main() {
    int start = 1;
    int stop = 10;
    SequenceGenerator generator(start, stop);
    std::vector<int> sequence = generator.generate_sequence();
    SemanticValidator validator(sequence);
    bool is_valid = validator.validate();
    ResultFormatter formatter(sequence, is_valid);
    std::cout << formatter.format() << std::endl;
}

int main() {
    main();
    return 0;
}