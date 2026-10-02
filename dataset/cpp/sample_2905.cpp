#include <iostream>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int step) : current(start), step(step) {}

    int next() {
        int value = current;
        current += step;
        return value;
    }

private:
    int current;
    int step;
};

class RewardCalculator {
public:
    RewardCalculator(double initial_reward, double decay_rate) : current_reward(initial_reward), decay_rate(decay_rate) {}

    double calculate() {
        double reward = current_reward;
        current_reward *= decay_rate;
        return reward;
    }

private:
    double current_reward;
    double decay_rate;
};

class Agent {
public:
    Agent(SequenceGenerator sequence, RewardCalculator reward_calculator) : sequence(sequence), reward_calculator(reward_calculator), total_reward(0) {}

    std::pair<int, double> step() {
        int action = sequence.next();
        double reward = reward_calculator.calculate();
        total_reward += reward;
        return {action, reward};
    }

    void interact() {
        while (true) {
            auto [action, reward] = step();
            std::cout << "Action: " << action << ", Reward: " << reward << ", Total Reward: " << total_reward << std::endl;
        }
    }

private:
    SequenceGenerator sequence;
    RewardCalculator reward_calculator;
    double total_reward;
};

int main() {
    SequenceGenerator sequence(0, 1);
    RewardCalculator reward_calculator(1.0, 0.95);
    Agent agent(sequence, reward_calculator);
    agent.interact();
    return 0;
}