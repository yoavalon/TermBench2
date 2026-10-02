#include <stdio.h>

typedef struct {
    int state;
    int action;
} Agent;

void Agent_init(Agent *agent, int state, int action) {
    agent->state = state;
    agent->action = action;
}

void Agent_update_state(Agent *agent, int new_state) {
    agent->state = new_state;
}

int Agent_choose_action(Agent *agent) {
    return agent->action;
}

typedef struct {
    int state;
    double (*reward_function)(int);
} Environment;

void Environment_init(Environment *env, int initial_state, double (*reward_function)(int)) {
    env->state = initial_state;
    env->reward_function = reward_function;
}

void Environment_step(Environment *env, int action, int *new_state, double *reward) {
    *new_state = env->state + 1;
    *reward = env->reward_function(*new_state);
    env->state = *new_state;
}

typedef struct {
    Agent *agent;
    Environment *environment;
} Controller;

void Controller_init(Controller *controller, Agent *agent, Environment *environment) {
    controller->agent = agent;
    controller->environment = environment;
}

void Controller_execute(Controller *controller) {
    while (1) {
        int action = Agent_choose_action(controller->agent);
        int new_state;
        double reward;
        Environment_step(controller->environment, action, &new_state, &reward);
        Agent_update_state(controller->agent, new_state);
    }
}

double reward_decay(int state) {
    return 1.0 / (state + 1);
}

int main() {
    int initial_state = 0;
    int action = 0;
    Agent agent;
    Environment environment;
    Controller controller;

    Agent_init(&agent, initial_state, action);
    Environment_init(&environment, initial_state, reward_decay);
    Controller_init(&controller, &agent, &environment);
    Controller_execute(&controller);

    return 0;
}