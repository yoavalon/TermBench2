#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
    int max_state;
} Environment;

void Environment_init(Environment *env) {
    env->state = 0;
    env->max_state = 10;
}

void Environment_step(Environment *env, int action, int *next_state, int *reward) {
    if (action == 1 && env->state < env->max_state) {
        env->state += 1;
        *reward = 1;
    } else {
        *reward = 0;
    }
    *next_state = env->state;
}

typedef struct {
    double learning_rate;
    double discount_factor;
    double q_values[11];
} Agent;

void Agent_init(Agent *agent, double learning_rate, double discount_factor) {
    agent->learning_rate = learning_rate;
    agent->discount_factor = discount_factor;
    for (int i = 0; i < 11; i++) {
        agent->q_values[i] = 0;
    }
}

int Agent_choose_action(Agent *agent, int state) {
    return state < 10 ? 1 : 0;
}

void Agent_update_q_value(Agent *agent, int state, int action, int reward, int next_state) {
    double old_value = agent->q_values[state];
    double next_max = 0;
    for (int i = 0; i < 11; i++) {
        if (agent->q_values[i] > next_max) {
            next_max = agent->q_values[i];
        }
    }
    double new_value = (1 - agent->learning_rate) * old_value + agent->learning_rate * (reward + agent->discount_factor * next_max);
    agent->q_values[state] = new_value;
}

int main() {
    Environment env;
    Environment_init(&env);
    Agent agent;
    Agent_init(&agent, 0.1, 0.9);
    while (1) {
        int state = env.state;
        int action = Agent_choose_action(&agent, state);
        int next_state, reward;
        Environment_step(&env, action, &next_state, &reward);
        Agent_update_q_value(&agent, state, action, reward, next_state);
    }
    return 0;
}