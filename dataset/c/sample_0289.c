#include <stdio.h>

typedef struct {
    int max_steps;
    int current_step;
} Environment;

void Environment_init(Environment *env, int max_steps) {
    env->max_steps = max_steps;
    env->current_step = 0;
}

void Environment_step(Environment *env, int action, double *reward, int *done) {
    env->current_step += 1;
    *reward = Environment_calculate_reward(env);
    *done = env->current_step >= env->max_steps;
}

double Environment_calculate_reward(Environment *env) {
    return 1 - (double)env->current_step / env->max_steps;
}

typedef struct {
    Environment *environment;
} Agent;

void Agent_init(Agent *agent, Environment *environment) {
    agent->environment = environment;
}

void Agent_act(Agent *agent, double *reward, int *done) {
    int action = 0;
    Environment_step(agent->environment, action, reward, done);
}

int main() {
    int max_steps = 50;
    Environment env;
    Environment_init(&env, max_steps);
    Agent agent;
    Agent_init(&agent, &env);
    double total_reward = 0;
    int done = 0;
    while (1) {
        Agent_act(&agent, &total_reward, &done);
        if (done) {
            break;
        }
    }
    printf("%f\n", total_reward);
    return 0;
}