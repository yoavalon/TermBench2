#include <iostream>
#include <vector>
#include <random>

class Agent {
public:
    int state;
    double discount_factor;

    Agent() : state(0), discount_factor(0.9) {}

    int take_action() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        return dis(gen);
    }

    double receive_reward(int action) {
        return action == 1 ? 1.0 : 0.0;
    }

    void update_state(int action) {
        if (action == 1) {
            state += 1;
        } else {
            state -= 1;
        }
    }
};

class Environment {
public:
    std::vector<int> action_space;

    Environment() : action_space({0, 1}) {}

    std::vector<int> get_possible_actions() {
        return action_space;
    }
};

class Simulator {
public:
    Agent agent;
    Environment environment;
    double total_reward;

    Simulator() : total_reward(0.0) {}

    double run_step() {
        int action = agent.take_action();
        double reward = agent.receive_reward(action) * std::pow(agent.discount_factor, agent.state);
        total_reward += reward;
        agent.update_state(action);
        return reward;
    }

    void simulate() {
        while (true) {
            run_step();
        }
    }
};

int main() {
    Simulator simulator;
    simulator.simulate();
    return 0;
}