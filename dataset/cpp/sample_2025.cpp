#include <iostream>
#include <cmath>

class RewardSystem {
public:
    RewardSystem(double initial_value, double decay_rate) : value(initial_value), decay_rate(decay_rate) {}

    double decay() {
        value *= decay_rate;
        return value;
    }

private:
    double value;
    double decay_rate;
};

class Environment {
public:
    Environment(RewardSystem* reward_system) : reward_system(reward_system) {}

    double step() {
        return reward_system->decay();
    }

private:
    RewardSystem* reward_system;
};

class Agent {
public:
    Agent(Environment* environment) : environment(environment) {}

    double act() {
        return environment->step();
    }

private:
    Environment* environment;
};

int main() {
    double initial_value = 1.0;
    double decay_rate = 0.99;
    RewardSystem reward_system(initial_value, decay_rate);
    Environment environment(&reward_system);
    Agent agent(&environment);
    double threshold = 0.01;
    int iterations = 0;
    while (true) {
        double reward = agent.act();
        iterations += 1;
        if (reward < threshold) {
            break;
        }
    }
    std::cout << "Terminated after " << iterations << " iterations with reward " << std::fixed << std::setprecision(6) << reward << std::endl;
    return 0;
}