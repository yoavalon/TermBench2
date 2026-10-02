#include <stdio.h>

typedef struct {
    int state;
    int max_state;
} Environment;

void Environment_init(Environment *env) {
    env->state = 0;
    env->max_state = 100;
}

void Environment_step(Environment *env, int action, int *reward, int *done) {
    *reward = 0;
    *done = 0;
    if (action == 1 && env->state < env->max_state) {
        env->state += 1;
        *reward = env->max_state - env->state;
    } else if (action == 0 && env->state > 0) {
        env->state -= 1;
        *reward = env->state;
    }
    if (env->state == env->max_state) {
        *done = 1;
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

void Agent_decide(Agent *agent) {
    if (agent->env->state > 50) {
        agent->action = 0;
    } else {
        agent->action = 1;
    }
}

void run() {
    Environment env;
    Agent agent;
    Environment_init(&env);
    Agent_init(&agent, &env);
    int total_reward = 0;
    while (1) {
        int reward;
        int done;
        Environment_step(&env, agent.action, &reward, &done);
        total_reward += reward;
        Agent_decide(&agent);
        if (done) {
            env.state = 0;
        }
    }
}

int main() {
    run();
    return 0;
}