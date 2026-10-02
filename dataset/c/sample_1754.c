#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int state;
    int rewards[10];
} Environment;

void Environment_init(Environment *env) {
    env->state = 0;
    env->rewards[0] = 10;
    env->rewards[1] = 9;
    env->rewards[2] = 8;
    env->rewards[3] = 7;
    env->rewards[4] = 6;
    env->rewards[5] = 5;
    env->rewards[6] = 4;
    env->rewards[7] = 3;
    env->rewards[8] = 2;
    env->rewards[9] = 1;
}

int Environment_reset(Environment *env) {
    env->state = 0;
    return env->state;
}

void Environment_step(Environment *env, int action, int *next_state, int *reward, bool *done) {
    if (action == 0) {
        *reward = env->rewards[env->state];
        env->state = env->state + 1 < 10 ? env->state + 1 : 9;
        *done = false;
    } else {
        *reward = 0;
        *done = true;
    }
    *next_state = env->state;
}

typedef struct {
    double policy[2];
} Agent;

int Agent_select_action(Agent *agent, int state) {
    return state < 5 ? 0 : 1;
}

void simulate(Environment *env, Agent *agent) {
    Environment_reset(env);
    int total_reward = 0;
    int steps = 0;
    while (true) {
        int action = Agent_select_action(agent, env->state);
        int next_state;
        int reward;
        bool done;
        Environment_step(env, action, &next_state, &reward, &done);
        total_reward += reward;
        steps += 1;
        if (done) {
            Environment_reset(env);
        }
        if (steps % 100 == 0) {
            printf("Step: %d, Total Reward: %d\n", steps, total_reward);
        }
    }
}

int main() {
    Environment env;
    Agent agent;
    Environment_init(&env);
    simulate(&env, &agent);
    return 0;
}