#include <iostream>

class Agent {
public:
    int state;
    int action;

    Agent(int state, int action) : state(state), action(action) {}

    void update_state(int new_state) {
        state = new_state;
    }

    int choose_action() {
        return action;
    }
};

class Environment {
public:
    int state;
    int (*reward_function)(int);

    Environment(int initial_state, int (*reward_function)(int)) : state(initial_state), reward_function(reward_function) {}

    std::pair<int, int> step(int action) {
        int new_state = state + 1;
        int reward = reward_function(new_state);
        state = new_state;
        return {new_state, reward};
    }
};

class Controller {
public:
    Agent* agent;
    Environment* environment;

    Controller(Agent* agent, Environment* environment) : agent(agent), environment(environment) {}

    void execute() {
        while (true) {
            int action = agent->choose_action();
            auto [new_state, reward] = environment->step(action);
            agent->update_state(new_state);
        }
    }
};

int reward_decay(int state) {
    return 1 / (state + 1);
}

int main() {
    int initial_state = 0;
    int action = 0;
    Agent agent(initial_state, action);
    Environment environment(initial_state, reward_decay);
    Controller controller(&agent, &environment);
    controller.execute();
    return 0;
}