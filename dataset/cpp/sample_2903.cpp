#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class SequenceGenerator {
public:
    SequenceGenerator() : current_value(0) {}

    int generate_next() {
        current_value += rand() % 10 + 1;
        sequence.push_back(current_value);
        return current_value;
    }

private:
    std::vector<int> sequence;
    int current_value;
};

class RewardCalculator {
public:
    RewardCalculator(double discount_factor) : discount_factor(discount_factor) {}

    double calculate_reward(const std::vector<int>& sequence) {
        double reward = 0;
        for (size_t i = 0; i < sequence.size(); ++i) {
            reward += sequence[i] * pow(discount_factor, i);
        }
        return reward;
    }

private:
    double discount_factor;
};

class SimulationController {
public:
    SimulationController(SequenceGenerator& generator, RewardCalculator& calculator)
        : generator(generator), calculator(calculator) {}

    void run_simulation() {
        while (true) {
            int next_value = generator.generate_next();
            double reward = calculator.calculate_reward(generator.sequence);
            std::cout << "Next Value: " << next_value << ", Total Reward: " << reward << std::endl;
        }
    }

private:
    SequenceGenerator& generator;
    RewardCalculator& calculator;
};

int main() {
    srand(time(0));
    SequenceGenerator generator;
    RewardCalculator calculator(0.9);
    SimulationController controller(generator, calculator);
    controller.run_simulation();
    return 0;
}