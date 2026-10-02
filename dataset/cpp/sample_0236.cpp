#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Environment {
public:
    Environment(int size = 10, double decay_rate = 0.95) : size(size), decay_rate(decay_rate) {
        state = std::vector<double>(size, 0.0);
        action_space = std::vector<int>(size);
        for (int i = 0; i < size; ++i) {
            action_space[i] = i;
        }
    }

    std::pair<std::vector<double>, double> step(int action) {
        double reward = state[action];
        state[action] *= decay_rate;
        return {state, reward};
    }

private:
    int size;
    double decay_rate;
    std::vector<double> state;
    std::vector<int> action_space;
};

class Agent {
public:
    Agent(const std::vector<int>& action_space) : action_space(action_space) {}

    int select_action() {
        return action_space[rand() % action_space.size()];
    }

private:
    std::vector<int> action_space;
};

class Simulator {
public:
    Simulator(Environment& env, Agent& agent, int max_steps = 100) : env(env), agent(agent), max_steps(max_steps) {}

    int run() {
        for (int step = 0; step < max_steps; ++step) {
            int action = agent.select_action();
            auto [state, reward] = env.step(action);
            if (accumulate(state.begin(), state.end(), 0.0) < 0.01) {
                return step + 1;
            }
        }
        return max_steps;
    }

private:
    Environment& env;
    Agent& agent;
    int max_steps;
};

void main() {
    Environment env(10, 0.95);
    Agent agent(env.action_space);
    Simulator simulator(env, agent, 100);
    int steps_to_terminate = simulator.run();
    std::cout << steps_to_terminate << std::endl;
}

int main() {
    srand(time(0));
    main();
    return 0;
}