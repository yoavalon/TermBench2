#include <iostream>
#include <vector>
#include <random>

class Environment {
public:
    Environment() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 2);
        state = dis(gen);
    }

    std::pair<int, int> step(int action) {
        int reward = 0;
        if (action == state) {
            reward = 1;
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 2);
        state = dis(gen);
        return {state, reward};
    }

private:
    int state;
};

class Agent {
public:
    Agent() {
        policy = {0.33, 0.33, 0.34};
    }

    int select_action() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::discrete_distribution<> dis(policy.begin(), policy.end());
        return dis(gen);
    }

private:
    std::vector<double> policy;
};

class Simulator {
public:
    Simulator(Environment& environment, Agent& agent) : env(environment), agent(agent), total_reward(0) {}

    void simulate() {
        int state = env.state;
        int action = agent.select_action();
        auto [next_state, reward] = env.step(action);
        total_reward += reward;
        simulate();
    }

private:
    Environment& env;
    Agent& agent;
    int total_reward;
};

int main() {
    Environment env;
    Agent agent;
    Simulator simulator(env, agent);
    simulator.simulate();
    return 0;
}