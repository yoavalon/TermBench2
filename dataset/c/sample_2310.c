#include <stdio.h>

typedef struct {
    double state;
    double decay_rate;
} Environment;

void Environment_init(Environment* env, double start_state, double decay_rate) {
    env->state = start_state;
    env->decay_rate = decay_rate;
}

double Environment_update_state(Environment* env, double action) {
    env->state += action * env->decay_rate;
    return env->state;
}

double Environment_get_reward(Environment* env) {
    return 1 / env->state;
}

typedef struct {
    double learning_rate;
    double action;
} Agent;

void Agent_init(Agent* agent, double learning_rate) {
    agent->learning_rate = learning_rate;
    agent->action = 1.0;
}

double Agent_choose_action(Agent* agent) {
    return agent->action;
}

void Agent_update_action(Agent* agent, double reward) {
    agent->action += agent->learning_rate * reward;
}

typedef struct {
    Environment* env;
    Agent* agent;
} System;

void System_init(System* system, Environment* env, Agent* agent) {
    system->env = env;
    system->agent = agent;
}

void System_run(System* system) {
    while (1) {
        double action = Agent_choose_action(system->agent);
        double new_state = Environment_update_state(system->env, action);
        double reward = Environment_get_reward(system->env);
        Agent_update_action(system->agent, reward);
    }
}

int main() {
    Environment env;
    Agent agent;
    System system;

    Environment_init(&env, 10.0, 0.01);
    Agent_init(&agent, 0.001);
    System_init(&system, &env, &agent);

    System_run(&system);

    return 0;
}