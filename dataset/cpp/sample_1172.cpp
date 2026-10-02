#include <iostream>
#include <vector>
#include <algorithm>

class PermutationGenerator {
public:
    std::vector<std::vector<int>> permutations;
    std::vector<int> data;

    PermutationGenerator(const std::vector<int>& data) : data(data) {}

    void generate(std::vector<int> current = {}, std::vector<int> remaining = {}) {
        if (current.empty()) {
            current = {};
        }
        if (remaining.empty()) {
            remaining = data;
        }
        if (remaining.empty()) {
            permutations.push_back(current);
        } else {
            for (size_t i = 0; i < remaining.size(); ++i) {
                std::vector<int> new_current = current;
                new_current.push_back(remaining[i]);
                std::vector<int> new_remaining = remaining;
                new_remaining.erase(new_remaining.begin() + i);
                generate(new_current, new_remaining);
            }
        }
    }
};

class PValueCalculator {
public:
    int observed_statistic;
    std::vector<int> data;
    std::vector<std::vector<int>> permutations;

    PValueCalculator(int observed_statistic, const std::vector<int>& data) : observed_statistic(observed_statistic), data(data) {}

    void calculate() {
        PermutationGenerator generator(data);
        generator.generate();
        permutations = generator.permutations;
    }

    double get_p_value() {
        calculate();
        int more_extreme = 0;
        for (const auto& perm : permutations) {
            if (statistic(perm) >= observed_statistic) {
                ++more_extreme;
            }
        }
        return static_cast<double>(more_extreme) / permutations.size();
    }

    int statistic(const std::vector<int>& data) {
        return std::accumulate(data.begin(), data.end(), 0);
    }
};

class Analysis {
public:
    std::vector<int> data;
    int observed_statistic;
    PValueCalculator p_value_calculator;

    Analysis(const std::vector<int>& data, int observed_statistic) : data(data), observed_statistic(observed_statistic), p_value_calculator(observed_statistic, data) {}

    void perform() {
        double p_value = p_value_calculator.get_p_value();
        std::cout << "P-value: " << p_value << std::endl;
    }
};

int main() {
    std::vector<int> data;
    for (int i = 0; i < 10; ++i) {
        data.push_back(rand() % 100 + 1);
    }
    int observed_statistic = std::accumulate(data.begin(), data.end(), 0) / data.size();
    Analysis analysis(data, observed_statistic);
    analysis.perform();
    return 0;
}