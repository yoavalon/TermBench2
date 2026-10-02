#include <iostream>
#include <vector>
#include <random>

class Environment {
public:
    Environment() : state(0), reward(1.0) {}

    std::pair<int, double> step(int action) {
        if (action == 0) {
            state += 1;
            reward *= 0.95;
        } else {
            state -= 1;
            reward *= 0.9;
        }
        return {state, reward};
    }

private:
    int state;
    double reward;
};

class Agent {
public:
    Agent() : policy{0.5, 0.5} {}

    int select_action() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::discrete_distribution<> d(policy.begin(), policy.end());
        return d(gen);
    }

private:
    std::vector<double> policy;
};

class Trainer {
public:
    Trainer(Environment& env, Agent& agent) : env(env), agent(agent) {}

    void train() {
        while (true) {
            int action = agent.select_action();
            auto [state, reward] = env.step(action);
            std::cout << "State: " << state << ", Reward: " << std::fixed << std::setprecision(2) << reward << std::endl;
        }
    }

private:
    Environment& env;
    Agent& agent;
};

int main() {
    Environment env;
    Agent agent;
    Trainer trainer(env, agent);
    trainer.train();
    return 0;
}