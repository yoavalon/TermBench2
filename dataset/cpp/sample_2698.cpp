#include <iostream>
#include <vector>
#include <numeric>

class SequenceGenerator {
public:
    SequenceGenerator(double initial_value, double decay_factor) : value(initial_value), decay(decay_factor) {}

    std::vector<double> generate(int steps) {
        std::vector<double> sequence;
        for (int i = 0; i < steps; ++i) {
            sequence.push_back(value);
            value *= decay;
        }
        return sequence;
    }

private:
    double value;
    double decay;
};

class RewardCalculator {
public:
    RewardCalculator(const std::vector<double>& sequence) : sequence(sequence) {}

    std::vector<double> calculate_rewards() {
        std::vector<double> rewards;
        for (double value : sequence) {
            double reward = value > 0 ? value : 0;
            rewards.push_back(reward);
        }
        return rewards;
    }

private:
    const std::vector<double>& sequence;
};

class Analysis {
public:
    Analysis(const std::vector<double>& rewards) : rewards(rewards) {}

    double average_reward() const {
        double sum = std::accumulate(rewards.begin(), rewards.end(), 0.0);
        return sum / rewards.size();
    }

    double total_reward() const {
        return std::accumulate(rewards.begin(), rewards.end(), 0.0);
    }

private:
    const std::vector<double>& rewards;
};

int main() {
    double initial_value = 100;
    double decay_factor = 0.95;
    int steps = 100;
    SequenceGenerator sequence_generator(initial_value, decay_factor);
    std::vector<double> sequence = sequence_generator.generate(steps);
    RewardCalculator reward_calculator(sequence);
    std::vector<double> rewards = reward_calculator.calculate_rewards();
    Analysis analysis(rewards);
    double avg_reward = analysis.average_reward();
    double total_reward = analysis.total_reward();
    std::cout << "Average Reward: " << avg_reward << std::endl;
    std::cout << "Total Reward: " << total_reward << std::endl;
    return 0;
}