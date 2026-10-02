#include <iostream>
#include <cmath>
#include <random>

class Environment {
public:
    Environment(int start, int goal, double decay_rate) {
        current = start;
        this->goal = goal;
        this->decay_rate = decay_rate;
        time_step = 0;
    }

    std::tuple<int, double, bool> step(int action) {
        current += action;
        time_step += 1;
        double reward = compute_reward();
        bool done = is_done();
        return std::make_tuple(current, reward, done);
    }

private:
    double compute_reward() {
        int distance = std::abs(current - goal);
        double reward = 1.0 / (distance + 1);
        reward *= std::pow(1 - decay_rate, time_step);
        return reward;
    }

    bool is_done() {
        return current == goal || time_step > 1000;
    }

    int current;
    int goal;
    double decay_rate;
    int time_step;
};

class Agent {
public:
    Agent(std::mt19937& action_space) : action_space(action_space) {}

    int act(int observation) {
        std::uniform_int_distribution<int> distribution(0, 1);
        return distribution(action_space);
    }

private:
    std::mt19937& action_space;
};

double run_episode(Environment& env, Agent& agent) {
    int observation = env.current;
    double total_reward = 0;
    bool done = false;
    while (!done) {
        int action = agent.act(observation);
        std::tie(observation, total_reward, done) = env.step(action);
    }
    return total_reward;
}

int main() {
    std::random_device rd;
    std::mt19937 action_space(rd());
    action_space.seed(42);

    Environment env(0, 10, 0.01);
    Agent agent(action_space);
    double episode_reward = run_episode(env, agent);
    std::cout << "Episode reward: " << episode_reward << std::endl;
    return 0;
}