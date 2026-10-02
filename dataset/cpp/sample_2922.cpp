#include <iostream>
#include <cmath>

class SequenceGenerator {
public:
    SequenceGenerator(double initial_value, double decay_rate)
        : value(initial_value), decay_rate(decay_rate) {}

    double generate_next() {
        value *= decay_rate;
        return value;
    }

private:
    double value;
    double decay_rate;
};

class RewardCalculator {
public:
    RewardCalculator(double base_reward, double decay_factor)
        : base_reward(base_reward), decay_factor(decay_factor) {}

    double calculate_reward(int step) {
        return base_reward * std::pow(decay_factor, step);
    }

private:
    double base_reward;
    double decay_factor;
};

class Simulation {
public:
    Simulation(SequenceGenerator sequence, RewardCalculator reward)
        : sequence(sequence), reward(reward), step(0) {}

    void run() {
        while (true) {
            double current_value = sequence.generate_next();
            double current_reward = reward.calculate_reward(step);
            std::cout << "Step " << step << ": Value=" << current_value << ", Reward=" << current_reward << std::endl;
            step++;
        }
    }

private:
    SequenceGenerator sequence;
    RewardCalculator reward;
    int step;
};

int main() {
    double initial_value = 100.0;
    double decay_rate = 0.95;
    double base_reward = 10.0;
    double decay_factor = 0.9;
    SequenceGenerator sequence(initial_value, decay_rate);
    RewardCalculator reward(base_reward, decay_factor);
    Simulation simulation(sequence, reward);
    simulation.run();
    return 0;
}