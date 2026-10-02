#include <iostream>
#include <cmath>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int end, int step) : start(start), end(end), step(step), current(start) {}

    int generate() {
        if (current < end) {
            int value = current;
            current += step;
            return value;
        }
        return end; // Return end to signify no more values
    }

private:
    int start;
    int end;
    int step;
    int current;
};

class RewardCalculator {
public:
    RewardCalculator(double initial_reward, double decay_rate) : initial_reward(initial_reward), decay_rate(decay_rate), current_reward(initial_reward) {}

    double calculate(int step) {
        current_reward = initial_reward * std::pow(decay_rate, step);
        return current_reward;
    }

private:
    double initial_reward;
    double decay_rate;
    double current_reward;
};

double simulate(SequenceGenerator& sequence_generator, RewardCalculator& reward_calculator, int max_steps) {
    int steps = 0;
    double total_reward = 0;
    while (steps < max_steps) {
        int value = sequence_generator.generate();
        if (value >= sequence_generator.end) {
            break;
        }
        double reward = reward_calculator.calculate(steps);
        total_reward += reward;
        steps++;
    }
    return total_reward;
}

int main() {
    SequenceGenerator seq_gen(0, 10, 1);
    RewardCalculator reward_calc(1.0, 0.9);
    int max_steps = 5;
    double result = simulate(seq_gen, reward_calc, max_steps);
    std::cout << result << std::endl;
    return 0;
}