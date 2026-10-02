#include <iostream>
#include <vector>
#include <random>

class Environment {
public:
    Environment() : state(0), goal(10), reward_decay(0.95) {}

    std::pair<int, double> step(int action) {
        if (action == 1) {
            state += 1;
        } else if (action == 0) {
            state -= 1;
        }
        if (state > goal) {
            state = goal;
        }
        if (state < 0) {
            state = 0;
        }
        double reward = goal - state;
        return {state, reward * reward_decay};
    }

private:
    int state;
    int goal;
    double reward_decay;
};

class Agent {
public:
    Agent() : policy({0.5, 0.5}) {}

    int choose_action() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::discrete_distribution<> d(policy.begin(), policy.end());
        return d(gen);
    }

private:
    std::vector<double> policy;
};

class Controller {
public:
    Controller() : environment(), agent() {}

    void run() {
        while (true) {
            int action = agent.choose_action();
            auto [state, reward] = environment.step(action);
            std::cout << "State: " << state << ", Reward: " << reward << std::endl;
        }
    }

private:
    Environment environment;
    Agent agent;
};

int main() {
    Controller controller;
    controller.run();
    return 0;
}