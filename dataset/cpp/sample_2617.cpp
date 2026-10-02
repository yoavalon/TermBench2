#include <iostream>
#include <vector>
#include <random>

class SequenceGenerator {
public:
    SequenceGenerator(int size) : size(size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        sequence = std::vector<double>(size);
        for (int i = 0; i < size; ++i) {
            sequence[i] = dis(gen);
        }
    }

    std::vector<double> generate() {
        return sequence;
    }

private:
    int size;
    std::vector<double> sequence;
};

class RewardCalculator {
public:
    RewardCalculator(double discount_factor) : discount_factor(discount_factor) {}

    double calculate(const std::vector<double>& sequence) {
        double reward = 0;
        for (int t = 0; t < sequence.size(); ++t) {
            reward += std::pow(discount_factor, t) * sequence[t];
        }
        return reward;
    }

private:
    double discount_factor;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(RewardCalculator& reward_calculator) : reward_calculator(reward_calculator) {}

    double analyze(const std::vector<double>& sequence) {
        return reward_calculator.calculate(sequence);
    }

private:
    RewardCalculator& reward_calculator;
};

void main() {
    int size = 10;
    double discount_factor = 0.9;
    SequenceGenerator generator(size);
    RewardCalculator reward_calculator(discount_factor);
    SequenceAnalyzer analyzer(reward_calculator);
    std::vector<double> sequence = generator.generate();
    double reward = analyzer.analyze(sequence);

    std::cout << "Sequence: ";
    for (double value : sequence) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::cout << "Reward: " << reward << std::endl;
}

int main() {
    main();
    return 0;
}