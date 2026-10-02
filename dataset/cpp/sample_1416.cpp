#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class Environment {
public:
    Environment(int size) {
        state = std::vector<int>(size, 0);
    }

    std::vector<int> reset() {
        for (int& s : state) {
            s = 0;
        }
        return state;
    }

    std::tuple<std::vector<int>, double, bool> step(int action) {
        double reward = static_cast<double>(std::rand()) / RAND_MAX * 2 - 1;
        state[action] += 1;
        bool done = false;
        for (int s : state) {
            if (s > 10) {
                done = true;
                break;
            }
        }
        return std::make_tuple(state, reward, done);
    }

private:
    std::vector<int> state;
};

class Agent {
public:
    Agent(const std::vector<int>& action_space) {
        this->action_space = action_space;
    }

    int choose_action() {
        return action_space[std::rand() % action_space.size()];
    }

private:
    std::vector<int> action_space;
};

std::vector<double> train_agent(Environment& env, Agent& agent, int episodes, double decay_rate) {
    std::vector<double> rewards;
    for (int episode = 0; episode < episodes; ++episode) {
        auto state = env.reset();
        double total_reward = 0;
        for (int _ = 0; _ < 100; ++_) {
            int action = agent.choose_action();
            auto [new_state, reward, done] = env.step(action);
            total_reward += reward;
            if (done) {
                break;
            }
        }
        rewards.push_back(total_reward);
        if (episode > 0 && episode % 10 == 0) {
            for (double& r : rewards) {
                r *= decay_rate;
            }
        }
    }
    return rewards;
}

int main() {
    int env_size = 5;
    std::vector<int> action_space(env_size);
    for (int i = 0; i < env_size; ++i) {
        action_space[i] = i;
    }
    Environment env(env_size);
    Agent agent(action_space);
    int episodes = 50;
    double decay_rate = 0.9;
    train_agent(env, agent, episodes, decay_rate);
    return 0;
}