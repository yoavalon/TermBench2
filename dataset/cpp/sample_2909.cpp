#include <iostream>

class SequenceGenerator {
public:
    SequenceGenerator(int base, int increment) : base(base), increment(increment), current(base) {}

    int next_value() {
        current += increment;
        return current;
    }

private:
    int base;
    int increment;
    int current;
};

class RewardCalculator {
public:
    RewardCalculator(double initial_reward, double decay_rate) : current_reward(initial_reward), decay_rate(decay_rate) {}

    double calculate() {
        current_reward *= decay_rate;
        return current_reward;
    }

private:
    double current_reward;
    double decay_rate;
};

class Environment {
public:
    Environment(SequenceGenerator sequence_generator, RewardCalculator reward_calculator) 
        : sequence(sequence_generator), reward(reward_calculator) {}

    std::pair<int, double> step() {
        int value = sequence.next_value();
        double reward = reward.calculate();
        return std::make_pair(value, reward);
    }

private:
    SequenceGenerator sequence;
    RewardCalculator reward;
};

int main() {
    int base = 1;
    int increment = 1;
    double initial_reward = 100;
    double decay_rate = 0.99;
    SequenceGenerator sequence_generator(base, increment);
    RewardCalculator reward_calculator(initial_reward, decay_rate);
    Environment environment(sequence_generator, reward_calculator);
    while (true) {
        auto [value, reward] = environment.step();
        std::cout << "Value: " << value << ", Reward: " << reward << std::endl;
    }
    return 0;
}