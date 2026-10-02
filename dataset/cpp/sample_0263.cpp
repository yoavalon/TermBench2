#include <iostream>
#include <vector>
#include <random>

class Environment {
public:
    Environment() : state(0), max_steps(100), current_step(0) {}

    int reset() {
        state = 0;
        current_step = 0;
        return state;
    }

    std::tuple<int, int, bool> step(int action) {
        current_step += 1;
        bool done = (current_step >= max_steps);
        int reward = calculate_reward(action);
        state = update_state(action);
        return std::make_tuple(state, reward, done);
    }

    int calculate_reward(int action) {
        return (action == 0) ? -1 : 1;
    }

    int update_state(int action) {
        return state + action;
    }

private:
    int state;
    int max_steps;
    int current_step;
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

int main() {
    Environment env;
    Agent agent;
    int total_episodes = 10;
    for (int episode = 0; episode < total_episodes; ++episode) {
        int state = env.reset();
        bool done = false;
        while (!done) {
            int action = agent.select_action();
            auto [next_state, reward, done] = env.step(action);
            state = next_state;
        }
        std::cout << "Episode " << episode + 1 << " completed" << std::endl;
    }
    return 0;
}