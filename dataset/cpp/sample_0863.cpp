#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Environment {
public:
    Environment() : state(0), goal(5) {}

    std::tuple<int, double, bool> step(int action) {
        if (action == 1) {
            state += 1;
        }
        double reward;
        bool done;
        if (state >= goal) {
            reward = 1;
            done = true;
        } else {
            reward = -0.1;
            done = false;
        }
        return std::make_tuple(state, reward, done);
    }

private:
    int state;
    int goal;
};

class Agent {
public:
    Agent(double epsilon, double alpha, double gamma) : epsilon(epsilon), alpha(alpha), gamma(gamma) {}

    int select_action(int state) {
        if (static_cast<double>(rand()) / RAND_MAX < epsilon) {
            return rand() % 2;
        } else {
            auto it = q_table.find(state);
            if (it != q_table.end()) {
                return std::max_element(it->second.begin(), it->second.end()) - it->second.begin();
            } else {
                return 0;
            }
        }
    }

    void update_q_table(int state, int action, double reward, int next_state, bool done) {
        auto it = q_table.find(state);
        if (it == q_table.end()) {
            q_table[state] = {0, 0};
            it = q_table.find(state);
        }
        auto it_next = q_table.find(next_state);
        if (it_next == q_table.end()) {
            q_table[next_state] = {0, 0};
        }
        double old_value = it->second[action];
        double next_max = done ? 0 : *std::max_element(it_next->second.begin(), it_next->second.end());
        double new_value = old_value + alpha * (reward + gamma * next_max - old_value);
        it->second[action] = new_value;
    }

private:
    double epsilon;
    double alpha;
    double gamma;
    std::unordered_map<int, std::vector<double>> q_table;
};

int main() {
    Environment env;
    Agent agent(0.1, 0.5, 0.9);
    int episodes = 1000;
    for (int episode = 0; episode < episodes; ++episode) {
        auto [state, reward, done] = env.step(0); // Assuming reset returns the initial state as 0
        while (!done) {
            int action = agent.select_action(state);
            auto [next_state, reward, done] = env.step(action);
            agent.update_q_table(state, action, reward, next_state, done);
            state = next_state;
        }
    }
    return 0;
}