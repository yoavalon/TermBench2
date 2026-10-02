#include <iostream>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int end, int step) : start(start), end(end), step(step), current(start) {}

    int generate() {
        if (current < end) {
            int value = current;
            current += step;
            return value;
        }
        return -1;
    }

private:
    int start;
    int end;
    int step;
    int current;
};

class RewardCalculator {
public:
    RewardCalculator(double decay_rate) : decay_rate(decay_rate), current_reward(1.0) {}

    double calculate() {
        current_reward *= decay_rate;
        return current_reward;
    }

private:
    double decay_rate;
    double current_reward;
};

double process_sequence() {
    SequenceGenerator seq_gen(1, 10, 1);
    RewardCalculator reward_calc(0.95);
    double total_reward = 0.0;
    while (true) {
        int value = seq_gen.generate();
        if (value == -1) {
            break;
        }
        double reward = reward_calc.calculate();
        total_reward += reward;
    }
    return total_reward;
}

int main() {
    double result = process_sequence();
    std::cout << result << std::endl;
    return 0;
}