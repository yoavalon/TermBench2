#include <iostream>
#include <cmath>

class Environment {
public:
    Environment(double start_state, double decay_rate) {
        this->state = start_state;
        this->decay_rate = decay_rate;
    }

    double update_state(double action) {
        this->state += action * this->decay_rate;
        return this->state;
    }

    double get_reward() {
        return 1 / this->state;
    }

private:
    double state;
    double decay_rate;
};

class Agent {
public:
    Agent(double learning_rate) {
        this->learning_rate = learning_rate;
        this->action = 1.0;
    }

    double choose_action() {
        return this->action;
    }

    void update_action(double reward) {
        this->action += this->learning_rate * reward;
    }

private:
    double learning_rate;
    double action;
};

class System {
public:
    System(Environment env, Agent agent) {
        this->env = env;
        this->agent = agent;
    }

    void run() {
        while (true) {
            double action = this->agent.choose_action();
            double new_state = this->env.update_state(action);
            double reward = this->env.get_reward();
            this->agent.update_action(reward);
        }
    }

private:
    Environment env;
    Agent agent;
};

int main() {
    Environment env(10.0, 0.01);
    Agent agent(0.001);
    System system(env, agent);
    system.run();
    return 0;
}