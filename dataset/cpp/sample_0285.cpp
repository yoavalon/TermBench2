#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class Environment {
public:
    Environment() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 9);
        state = dis(gen);
        action_space = {0, 1};
    }

    std::tuple<int, double, bool> step(int action) {
        double reward = 0;
        if (action == 0) {
            reward = 1 - static_cast<double>(state) / 10.0;
        } else {
            reward = static_cast<double>(state) / 10.0;
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 9);
        state = dis(gen);
        return std::make_tuple(state, reward, is_done());
    }

    bool is_done() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        return dis(gen) < 0.05;
    }

private:
    int state;
    std::vector<int> action_space;
};

class Agent {
public:
    Agent(const std::vector<int>& action_space) : action_space(action_space), epsilon(1.0) {}

    int choose_action(int state) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        if (dis(gen) < epsilon) {
            return action_space[dis(gen) < 0.5 ? 0 : 1];
        } else {
            return policy(state);
        }
    }

    int policy(int state) {
        return state < 5 ? 0 : 1;
    }

private:
    std::vector<int> action_space;
    double epsilon;
};

void train(Agent& agent, Environment& env, int episodes) {
    for (int episode = 0; episode < episodes; ++episode) {
        int state = env.reset();
        bool done = false;
        while (!done) {
            int action = agent.choose_action(state);
            auto [next_state, reward, done] = env.step(action);
            state = next_state;
        }
        agent.epsilon = std::max(0.01, agent.epsilon * 0.99);
    }
}

int main() {
    Environment env;
    Agent agent(env.action_space);
    int episodes = 1000;
    train(agent, env, episodes);
    return 0;
}