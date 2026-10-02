#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int state;
    int max_steps;
    int current_step;
} Environment;

typedef struct {
    double policy[2];
} Agent;

void environment_init(Environment *env) {
    env->state = 0;
    env->max_steps = 100;
    env->current_step = 0;
}

int environment_reset(Environment *env) {
    env->state = 0;
    env->current_step = 0;
    return env->state;
}

void environment_step(Environment *env, int action, int *new_state, int *reward, int *done) {
    env->current_step += 1;
    if (env->current_step >= env->max_steps) {
        *done = 1;
    } else {
        *done = 0;
    }
    *reward = (action == 0) ? -1 : 1;
    *new_state = env->state + action;
    env->state = *new_state;
}

int agent_select_action(Agent *agent) {
    double r = (double)rand() / RAND_MAX;
    return (r < agent->policy[0]) ? 0 : 1;
}

void agent_init(Agent *agent) {
    agent->policy[0] = 0.5;
    agent->policy[1] = 0.5;
}

int main() {
    srand(time(NULL));
    Environment env;
    Agent agent;
    environment_init(&env);
    agent_init(&agent);
    int total_episodes = 10;
    for (int episode = 0; episode < total_episodes; episode++) {
        int state = environment_reset(&env);
        int done = 0;
        while (!done) {
            int action = agent_select_action(&agent);
            int new_state, reward;
            environment_step(&env, action, &new_state, &reward, &done);
        }
        printf("Episode %d completed\n", episode + 1);
    }
    return 0;
}