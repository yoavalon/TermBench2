#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Environment {
public:
    Environment(int num_states, int num_actions) : num_states(num_states), num_actions(num_actions) {}

    std::tuple<int, double, bool> step(int state, int action) {
        double reward = _compute_reward(state, action);
        int next_state = _transition(state, action);
        bool done = _is_done(next_state);
        return std::make_tuple(next_state, reward, done);
    }

private:
    int num_states;
    int num_actions;

    double _compute_reward(int state, int action) {
        return -std::sqrt(std::pow(state - action, 2));
    }

    int _transition(int state, int action) {
        return (state + action) % num_states;
    }

    bool _is_done(int state) {
        return state == 0;
    }
};

class Agent {
public:
    Agent(int num_actions) : num_actions(num_actions) {
        policy.resize(num_actions, 1.0 / num_actions);
    }

    int select_action() {
        return std::rand() % num_actions;
    }

    void update_policy(int state, int action, double reward) {
        double mean_policy = 0.0;
        for (double p : policy) {
            mean_policy += p;
        }
        mean_policy /= num_actions;
        policy[action] += 0.1 * (reward - mean_policy);
    }

private:
    int num_actions;
    std::vector<double> policy;
};

void main() {
    int num_states = 10;
    int num_actions = 5;
    int max_steps = 100;
    double gamma = 0.99;
    Environment env(num_states, num_actions);
    Agent agent(num_actions);
    std::srand(std::time(nullptr));
    int state = std::rand() % num_states;
    for (int step = 0; step < max_steps; ++step) {
        int action = agent.select_action();
        auto [next_state, reward, done] = env.step(state, action);
        agent.update_policy(state, action, reward);
        state = next_state;
        if (done) {
            break;
        }
    }
}

int main() {
    main();
    return 0;
}