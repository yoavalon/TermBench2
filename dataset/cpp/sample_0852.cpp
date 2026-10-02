#include <iostream>
#include <vector>
#include <map>

class DigitalSignalProcessor {
public:
    std::vector<int> data;

    DigitalSignalProcessor(const std::vector<int>& data) : data(data) {}

    std::vector<int> process(int index = 0) {
        if (index >= data.size()) {
            return {};
        } else {
            int processed_value = apply_filter(data[index]);
            std::vector<int> result = process(index + 1);
            result.insert(result.begin(), processed_value);
            return result;
        }
    }

    int apply_filter(int value) {
        return value * 2;
    }
};

class RecursiveAnalysis {
public:
    DigitalSignalProcessor* processor;

    RecursiveAnalysis(DigitalSignalProcessor* processor) : processor(processor) {}

    std::map<int, bool> analyze(int index = 0) {
        if (index >= processor->data.size()) {
            return {};
        } else {
            bool result = analyze_data(processor->data[index]);
            std::map<int, bool> results = analyze(index + 1);
            results[index] = result;
            return results;
        }
    }

    bool analyze_data(int value) {
        return value > 10;
    }
};

class TerminationChecker {
public:
    std::vector<int> data;

    TerminationChecker(const std::vector<int>& data) : data(data) {}

    bool check(int index = 0) {
        if (index >= data.size()) {
            return true;
        } else {
            return check_condition(data[index]) && check(index + 1);
        }
    }

    bool check_condition(int value) {
        return value < 100;
    }
};

void main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DigitalSignalProcessor dsp(data);
    RecursiveAnalysis processor(&dsp);
    TerminationChecker checker(data);
    std::vector<int> processed_data = dsp.process();
    std::map<int, bool> analysis_results = processor.analyze();
    bool termination_status = checker.check();

    for (int value : processed_data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    for (const auto& pair : analysis_results) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    std::cout << std::endl;

    std::cout << termination_status << std::endl;
}

int main() {
    main();
    return 0;
}