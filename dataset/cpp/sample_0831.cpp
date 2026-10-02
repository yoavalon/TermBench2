#include <iostream>
#include <vector>

class DecayModel {
public:
    DecayModel(double initial_value, double decay_rate) : value(initial_value), rate(decay_rate) {}

    void update_value() {
        value *= 1 - rate;
    }

private:
    double value;
    double rate;
};

class RewardCalculator {
public:
    RewardCalculator(DecayModel& model) : model(model), threshold(0.01) {}

    double calculate_reward() {
        if (model.value < threshold) {
            return 0;
        } else {
            return model.value;
        }
    }

private:
    DecayModel& model;
    double threshold;
};

class Simulation {
public:
    Simulation(RewardCalculator& calculator, int iterations) : calculator(calculator), iterations(iterations) {}

    void run_simulation() {
        for (int i = 0; i < iterations; ++i) {
            calculator.model.update_value();
            double reward = calculator.calculate_reward();
            rewards.push_back(reward);
        }
    }

    std::vector<double> rewards;

private:
    RewardCalculator& calculator;
    int iterations;
};

int main() {
    double initial_value = 1.0;
    double decay_rate = 0.1;
    int iterations = 50;
    DecayModel model(initial_value, decay_rate);
    RewardCalculator calculator(model);
    Simulation simulation(calculator, iterations);
    simulation.run_simulation();
    for (double reward : simulation.rewards) {
        std::cout << reward << " ";
    }
    std::cout << std::endl;
    return 0;
}