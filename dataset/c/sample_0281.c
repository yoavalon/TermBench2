#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int current;
    int goal;
    double decay_rate;
    int time_step;
} Environment;

typedef struct {
    int* action_space;
    int action_space_size;
} Agent;

void Environment_init(Environment* env, int start, int goal, double decay_rate) {
    env->current = start;
    env->goal = goal;
    env->decay_rate = decay_rate;
    env->time_step = 0;
}

void Environment_step(Environment* env, int action, int* next_state, double* reward, int* done) {
    env->current += action;
    env->time_step += 1;
    *next_state = env->current;
    *reward = Environment_compute_reward(env);
    *done = Environment_is_done(env);
}

double Environment_compute_reward(Environment* env) {
    int distance = abs(env->current - env->goal);
    double reward = 1.0 / (distance + 1);
    reward *= pow(1 - env->decay_rate, env->time_step);
    return reward;
}

int Environment_is_done(Environment* env) {
    return env->current == env->goal || env->time_step > 1000;
}

void Agent_init(Agent* agent, int* action_space, int action_space_size) {
    agent->action_space = action_space;
    agent->action_space_size = action_space_size;
}

int Agent_act(Agent* agent) {
    return agent->action_space[rand() % agent->action_space_size];
}

double run_episode(Environment* env, Agent* agent) {
    int observation = env->current;
    double total_reward = 0;
    int done = 0;
    while (!done) {
        int action = Agent_act(agent);
        int next_state;
        double reward;
        Environment_step(env, action, &next_state, &reward, &done);
        total_reward += reward;
        observation = next_state;
    }
    return total_reward;
}

void main() {
    srand(42);
    Environment env;
    Environment_init(&env, 0, 10, 0.01);

    int action_space[] = {1, -1};
    int action_space_size = sizeof(action_space) / sizeof(action_space[0]);
    Agent agent;
    Agent_init(&agent, action_space, action_space_size);

    double episode_reward = run_episode(&env, &agent);
    printf("Episode reward: %f\n", episode_reward);
}