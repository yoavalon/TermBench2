#include <iostream>
#include <vector>
#include <cstdlib>

class Environment {
public:
    Environment() : state(0), done(false) {}

    std::tuple<int, double, bool> step(int action) {
        double reward = 0;
        if (action == 1) {
            reward = 1 - state * 0.1;
            state += 1;
        }
        if (state >= 10) {
            done = true;
        }
        return std::make_tuple(state, reward, done);
    }

    void reset() {
        state = 0;
        done = false;
    }

private:
    int state;
    bool done;
};

class Agent {
public:
    Agent(const std::vector<int>& action_space) : action_space(action_space) {}

    int act() {
        return action_space[rand() % action_space.size()];
    }

private:
    std::vector<int> action_space;
};

void train(Agent& agent, Environment& env, int episodes, int max_steps) {
    for (int episode = 0; episode < episodes; ++episode) {
        env.reset();
        for (int step = 0; step < max_steps; ++step) {
            int action = agent.act();
            auto [state, reward, done] = env.step(action);
            if (done) {
                break;
            }
        }
    }
}

int main() {
    std::vector<int> action_space = {0, 1};
    Agent agent(action_space);
    Environment env;
    int episodes = 100;
    int max_steps = 20;
    train(agent, env, episodes, max_steps);
    return 0;
}