#include <stdio.h>

typedef struct {
    int state;
    int max_state;
    double decay_rate;
} Environment;

void Environment_init(Environment *env) {
    env->state = 0;
    env->max_state = 100;
    env->decay_rate = 0.99;
}

void Environment_step(Environment *env, int action, int *state, double *reward) {
    *reward = Environment_calculate_reward(env);
    Environment_update_state(env, action);
    *state = env->state;
}

double Environment_calculate_reward(Environment *env) {
    return 100 - env->state * env->decay_rate;
}

void Environment_update_state(Environment *env, int action) {
    env->state += action;
    if (env->state > env->max_state) {
        env->state = env->max_state;
    }
}

typedef struct {
    Environment *env;
    int action;
} Agent;

void Agent_init(Agent *agent, Environment *env) {
    agent->env = env;
    agent->action = 1;
}

void Agent_act(Agent *agent, int *state, double *reward) {
    Environment_step(agent->env, agent->action, state, reward);
}

void simulate() {
    Environment env;
    Environment_init(&env);
    Agent agent;
    Agent_init(&agent, &env);
    double total_reward = 0;
    while (1) {
        int state;
        double reward;
        Agent_act(&agent, &state, &reward);
        total_reward += reward;
        printf("State: %d, Reward: %.2f, Total Reward: %.2f\n", state, reward, total_reward);
    }
}

int main() {
    simulate();
    return 0;
}