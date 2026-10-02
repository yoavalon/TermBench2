#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int state;
    double reward;
} Environment;

void Environment_init(Environment *env) {
    env->state = 0;
    env->reward = 1.0;
}

void Environment_step(Environment *env, int action) {
    if (action == 0) {
        env->state += 1;
        env->reward *= 0.95;
    } else {
        env->state -= 1;
        env->reward *= 0.9;
    }
    if (env->state > 10) {
        env->state = 10;
        env->reward = 0;
    } else if (env->state < 0) {
        env->state = 0;
        env->reward = 0;
    }
}

typedef struct {
    double policy[2];
} Agent;

void Agent_init(Agent *agent) {
    agent->policy[0] = 0.5;
    agent->policy[1] = 0.5;
}

int Agent_choose_action(Agent *agent) {
    double r = (double)rand() / RAND_MAX;
    if (r < agent->policy[0]) {
        return 0;
    } else {
        return 1;
    }
}

double simulate() {
    Environment env;
    Agent agent;
    Environment_init(&env);
    Agent_init(&agent);
    int done = 0;
    while (!done) {
        int action = Agent_choose_action(&agent);
        Environment_step(&env, action);
        done = (env.state == 0 || env.state == 10);
    }
    return env.reward;
}

int main() {
    srand(time(NULL));
    double results[100];
    for (int i = 0; i < 100; i++) {
        results[i] = simulate();
    }
    double sum = 0;
    for (int i = 0; i < 100; i++) {
        sum += results[i];
    }
    printf("%f\n", sum / 100);
    return 0;
}