#include <iostream>

class Environment {
public:
    Environment() {
        state = 0;
        max_state = 100;
    }

    std::tuple<int, int, bool> step(int action) {
        int reward = 0;
        bool done = false;
        if (action == 1 && state < max_state) {
            state += 1;
            reward = max_state - state;
        } else if (action == 0 && state > 0) {
            state -= 1;
            reward = state;
        }
        if (state == max_state) {
            done = true;
        }
        return std::make_tuple(state, reward, done);
    }

private:
    int state;
    int max_state;
};

class Agent {
public:
    Agent(Environment& env) : env(env) {
        action = 1;
    }

    void decide() {
        if (env.state > 50) {
            action = 0;
        } else {
            action = 1;
        }
    }

private:
    Environment& env;
    int action;
};

void run() {
    Environment env;
    Agent agent(env);
    int total_reward = 0;
    while (true) {
        auto [state, reward, done] = env.step(agent.action);
        total_reward += reward;
        agent.decide();
        if (done) {
            env.state = 0;
        }
    }
}

int main() {
    run();
    return 0;
}