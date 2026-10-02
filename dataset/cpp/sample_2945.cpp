#include <iostream>
#include <random>

class SequenceGenerator {
public:
    SequenceGenerator(int start, double step, double decay_factor) 
        : current_value(start), step(step), decay_factor(decay_factor) {}

    int generate_next() {
        current_value += step;
        step *= decay_factor;
        return current_value;
    }

private:
    int current_value;
    double step;
    double decay_factor;
};

class RewardEvaluator {
public:
    RewardEvaluator(int threshold) : threshold(threshold) {}

    int evaluate(int value) {
        return std::max(0, value - threshold);
    }

private:
    int threshold;
};

class NonTerminatingSimulation {
public:
    NonTerminatingSimulation(SequenceGenerator& sequence_gen, RewardEvaluator& reward_eval) 
        : sequence_gen(sequence_gen), reward_eval(reward_eval) {}

    void run() {
        int total_reward = 0;
        while (true) {
            int next_value = sequence_gen.generate_next();
            int reward = reward_eval.evaluate(next_value);
            total_reward += reward;
            std::cout << "Value: " << next_value << ", Reward: " << reward << ", Total Reward: " << total_reward << std::endl;
        }
    }

private:
    SequenceGenerator& sequence_gen;
    RewardEvaluator& reward_eval;
};

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis1(1, 10);
    std::uniform_real_distribution<> dis2(0.5, 2.0);
    std::uniform_real_distribution<> dis3(0.9, 0.99);
    std::uniform_int_distribution<> dis4(5, 15);

    int start_value = dis1(gen);
    double step_size = dis2(gen);
    double decay_factor = dis3(gen);
    int threshold = dis4(gen);

    SequenceGenerator seq_gen(start_value, step_size, decay_factor);
    RewardEvaluator reward_eval(threshold);
    NonTerminatingSimulation simulation(seq_gen, reward_eval);
    simulation.run();

    return 0;
}