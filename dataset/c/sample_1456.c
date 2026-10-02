#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int state;
    int max_steps;
    int step_count;
} Environment;

void Environment_init(Environment *env, int max_steps) {
    env->state = 0;
    env->max_steps = max_steps;
    env->step_count = 0;
}

void Environment_reset(Environment *env) {
    env->state = 0;
    env->step_count = 0;
}

int Environment_step(Environment *env, int action) {
    env->step_count += 1;
    int reward = (action == 1) ? 1 : -1;
    env->state = (env->state + action) % 10;
    return env->step_count >= env->max_steps;
}

typedef struct {
    Environment *env;
    int policy[10];
} Agent;

void Agent_init(Agent *agent, Environment *env) {
    agent->env = env;
    for (int i = 0; i < 10; i++) {
        agent->policy[i] = (i % 2 == 0) ? 1 : 0;
    }
}

int Agent_act(Agent *agent, int state) {
    return agent->policy[state];
}

int run_episode(Environment *env, Agent *agent) {
    Environment_reset(env);
    int done = 0;
    int total_reward = 0;
    while (!done) {
        int state = env->state;
        int action = Agent_act(agent, state);
        done = Environment_step(env, action);
        total_reward += (action == 1) ? 1 : -1;
    }
    return total_reward;
}

void main() {
    Environment env;
    Environment_init(&env, 20);
    Agent agent;
    Agent_init(&agent, &env);
    int total_episodes = 10;
    int episode_rewards[total_episodes];
    for (int i = 0; i < total_episodes; i++) {
        episode_rewards[i] = run_episode(&env, &agent);
    }
    printf("Episode rewards: ");
    for (int i = 0; i < total_episodes; i++) {
        printf("%d ", episode_rewards[i]);
    }
    printf("\n");
}