#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int state;
    int terminal_state;
    int rewards[10];
} Environment;

void Environment_init(Environment *env) {
    env->state = 0;
    env->terminal_state = 10;
    for (int i = 0; i < env->terminal_state; i++) {
        env->rewards[i] = i + 1;
    }
}

void Environment_step(Environment *env, int action, int *next_state, int *reward, int *done) {
    if (env->state + action > env->terminal_state) {
        *next_state = env->state;
        *reward = 0;
        *done = 1;
    } else {
        env->state += action;
        *next_state = env->state;
        *reward = env->rewards[env->state - 1];
        *done = (env->state == env->terminal_state);
    }
}

typedef struct {
    double alpha;
    double gamma;
    double q_table[11];
} Agent;

void Agent_init(Agent *agent, double alpha, double gamma) {
    agent->alpha = alpha;
    agent->gamma = gamma;
    for (int i = 0; i < 11; i++) {
        agent->q_table[i] = 0;
    }
}

int Agent_choose_action(Agent *agent) {
    return (rand() > RAND_MAX / 2) ? 1 : 2;
}

void Agent_learn(Agent *agent, int state, int action, int reward, int next_state) {
    double td_target = reward + agent->gamma * agent->q_table[next_state];
    double td_error = td_target - agent->q_table[state + action - 1];
    agent->q_table[state + action - 1] += agent->alpha * td_error;
}

void main() {
    Environment env;
    Agent agent;
    Environment_init(&env);
    Agent_init(&agent, 0.1, 0.99);
    int episodes = 1000;
    for (int i = 0; i < episodes; i++) {
        int state = env.state;
        while (1) {
            int action = Agent_choose_action(&agent);
            int next_state, reward, done;
            Environment_step(&env, action, &next_state, &reward, &done);
            Agent_learn(&agent, state, action, reward, next_state);
            state = next_state;
            if (done) {
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    main();
    return 0;
}