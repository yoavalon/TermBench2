#include <iostream>
#include <vector>
#include <algorithm>

class Environment {
public:
    Environment() : state(0), max_state(10) {}

    std::pair<int, int> step(int action) {
        if (action == 1 && state < max_state) {
            state += 1;
            int reward = 1;
            return std::make_pair(state, reward);
        } else {
            int reward = 0;
            return std::make_pair(state, reward);
        }
    }

private:
    int state;
    int max_state;
};

class Agent {
public:
    Agent(double learning_rate, double discount_factor) : learning_rate(learning_rate), discount_factor(discount_factor) {
        q_values = std::vector<double>(11, 0.0);
    }

    int choose_action(int state) {
        return (state < 10) ? 1 : 0;
    }

    void update_q_value(int state, int action, int reward, int next_state) {
        double old_value = q_values[state];
        double next_max = *std::max_element(q_values.begin(), q_values.end());
        double new_value = (1 - learning_rate) * old_value + learning_rate * (reward + discount_factor * next_max);
        q_values[state] = new_value;
    }

private:
    double learning_rate;
    double discount_factor;
    std::vector<double> q_values;
};

void main() {
    Environment env;
    Agent agent(0.1, 0.9);
    while (true) {
        int state = env.state;
        int action = agent.choose_action(state);
        auto [next_state, reward] = env.step(action);
        agent.update_q_value(state, action, reward, next_state);
    }
}