#include <iostream>

class Environment {
public:
    Environment(int max_steps) : max_steps(max_steps), current_step(0) {}

    std::pair<double, bool> step(int action) {
        current_step++;
        double reward = calculate_reward();
        bool done = current_step >= max_steps;
        return std::make_pair(reward, done);
    }

private:
    double calculate_reward() {
        return 1 - static_cast<double>(current_step) / max_steps;
    }

    int max_steps;
    int current_step;
};

class Agent {
public:
    Agent(Environment& environment) : environment(environment) {}

    std::pair<double, bool> act() {
        int action = 0;
        auto [reward, done] = environment.step(action);
        return std::make_pair(reward, done);
    }

private:
    Environment& environment;
};

int main() {
    int max_steps = 50;
    Environment env(max_steps);
    Agent agent(env);
    double total_reward = 0;
    while (true) {
        auto [reward, done] = agent.act();
        total_reward += reward;
        if (done) {
            break;
        }
    }
    std::cout << total_reward << std::endl;
    return 0;
}