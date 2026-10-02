#include <iostream>

class Environment {
public:
    int state;
    int max_state;
    double decay_rate;

    Environment() : state(0), max_state(100), decay_rate(0.99) {}

    std::pair<int, double> step(int action) {
        double reward = calculate_reward();
        update_state(action);
        return {state, reward};
    }

    double calculate_reward() {
        return 100 - state * decay_rate;
    }

    void update_state(int action) {
        state += action;
        if (state > max_state) {
            state = max_state;
        }
    }
};

class Agent {
public:
    Environment env;
    int action;

    Agent(Environment env) : env(env), action(1) {}

    std::pair<int, double> act() {
        auto [state, reward] = env.step(action);
        return {state, reward};
    }
};

void simulate() {
    Environment env;
    Agent agent(env);
    double total_reward = 0;
    while (true) {
        auto [state, reward] = agent.act();
        total_reward += reward;
        std::cout << "State: " << state << ", Reward: " << reward << ", Total Reward: " << total_reward << std::endl;
    }
}

int main() {
    simulate();
    return 0;
}