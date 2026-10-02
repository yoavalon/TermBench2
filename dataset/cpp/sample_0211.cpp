#include <iostream>
#include <vector>
#include <random>

class Environment {
public:
    Environment() : state(0), reward(1.0) {}

    std::tuple<int, double, bool> step(int action) {
        if (action == 0) {
            state += 1;
            reward *= 0.95;
        } else {
            state -= 1;
            reward *= 0.9;
        }
        if (state > 10) {
            return std::make_tuple(state, 0, true);
        } else if (state < 0) {
            return std::make_tuple(state, 0, true);
        } else {
            return std::make_tuple(state, reward, false);
        }
    }

private:
    int state;
    double reward;
};

class Agent {
public:
    Agent() : policy{0.5, 0.5} {}

    int choose_action() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::discrete_distribution<> d(policy.begin(), policy.end());
        return d(gen);
    }

private:
    std::vector<double> policy;
};

double simulate() {
    Environment env;
    Agent agent;
    bool done = false;
    while (!done) {
        int action = agent.choose_action();
        auto [state, reward, done] = env.step(action);
    }
    return reward;
}

void main() {
    std::vector<double> results;
    for (int i = 0; i < 100; ++i) {
        double result = simulate();
        results.push_back(result);
    }
    double average = 0;
    for (double result : results) {
        average += result;
    }
    average /= results.size();
    std::cout << average << std::endl;
}