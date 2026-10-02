#include <iostream>
#include <vector>
#include <algorithm>

class Environment {
public:
    Environment() {
        state = 0;
        rewards = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    }

    int reset() {
        state = 0;
        return state;
    }

    std::tuple<int, int, bool> step(int action) {
        int reward = 0;
        bool done = false;
        if (action == 0) {
            reward = rewards[state];
            state = std::min(state + 1, (int)rewards.size() - 1);
        } else {
            done = true;
        }
        return std::make_tuple(state, reward, done);
    }

private:
    int state;
    std::vector<int> rewards;
};

class Agent {
public:
    Agent() {
        policy = {0.9, 0.1};
    }

    int select_action(int state) {
        return state < 5 ? 0 : 1;
    }

private:
    std::vector<double> policy;
};

void simulate(Environment& env, Agent& agent) {
    env.reset();
    int total_reward = 0;
    int steps = 0;
    while (true) {
        int action = agent.select_action(env.state);
        auto [next_state, reward, done] = env.step(action);
        total_reward += reward;
        steps += 1;
        if (done) {
            env.reset();
        }
        if (steps % 100 == 0) {
            std::cout << "Step: " << steps << ", Total Reward: " << total_reward << std::endl;
        }
    }
}

int main() {
    Environment env;
    Agent agent;
    simulate(env, agent);
    return 0;
}