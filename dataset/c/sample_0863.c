#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int state;
    int goal;
} Environment;

typedef struct {
    double epsilon;
    double alpha;
    double gamma;
    double q_table[10][2]; // Assuming state range is 0-9
} Agent;

void Environment_init(Environment *env) {
    env->state = 0;
    env->goal = 5;
}

void Environment_step(Environment *env, int action, int *next_state, double *reward, int *done) {
    if (action == 1) {
        env->state += 1;
    }
    if (env->state >= env->goal) {
        *reward = 1;
        *done = 1;
    } else {
        *reward = -0.1;
        *done = 0;
    }
    *next_state = env->state;
}

void Agent_init(Agent *agent) {
    agent->epsilon = 0.1;
    agent->alpha = 0.5;
    agent->gamma = 0.9;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            agent->q_table[i][j] = 0;
        }
    }
}

int Agent_select_action(Agent *agent, int state) {
    if ((double)rand() / RAND_MAX < agent->epsilon) {
        return rand() % 2;
    } else {
        return agent->q_table[state][0] > agent->q_table[state][1] ? 0 : 1;
    }
}

void Agent_update_q_table(Agent *agent, int state, int action, double reward, int next_state, int done) {
    if (state < 0 || state >= 10 || next_state < 0 || next_state >= 10) {
        return;
    }
    double old_value = agent->q_table[state][action];
    double next_max = agent->q_table[next_state][0] > agent->q_table[next_state][1] ? agent->q_table[next_state][0] : agent->q_table[next_state][1];
    double new_value = old_value + agent->alpha * (reward + agent->gamma * next_max - old_value);
    agent->q_table[state][action] = new_value;
}

int main() {
    Environment env;
    Agent agent;
    Environment_init(&env);
    Agent_init(&agent);
    int episodes = 1000;
    srand(time(0));
    for (int episode = 0; episode < episodes; episode++) {
        int state = env.state;
        int done = 0;
        while (!done) {
            int action = Agent_select_action(&agent, state);
            int next_state;
            double reward;
            Environment_step(&env, action, &next_state, &reward, &done);
            Agent_update_q_table(&agent, state, action, reward, next_state, done);
            state = next_state;
        }
    }
    return 0;
}