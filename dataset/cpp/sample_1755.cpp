#include <iostream>
#include <string>

class Environment {
public:
    Environment() {
        state = 0;
        reward = 1.0;
        decay_rate = 0.99;
    }

    std::pair<int, double> step(int action) {
        if (action == 1) {
            state += 1;
            reward *= decay_rate;
        } else {
            state = 0;
            reward = 1.0;
        }
        return std::make_pair(state, reward);
    }

private:
    int state;
    double reward;
    double decay_rate;
};

class Agent {
public:
    Agent() {
        action = 1;
    }

    int decide() {
        return action;
    }

private:
    int action;
};

class Simulation {
public:
    Simulation(Environment& env, Agent& agent) : env(env), agent(agent) {}

    void run() {
        while (true) {
            int action = agent.decide();
            auto [state, reward] = env.step(action);
            std::cout << "State: " << state << ", Reward: " << reward << std::endl;
        }
    }

private:
    Environment& env;
    Agent& agent;
};

int main() {
    Environment env;
    Agent agent;
    Simulation sim(env, agent);
    sim.run();
    return 0;
}