#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int num_states;
    int num_actions;
} Environment;

typedef struct {
    int num_actions;
    double *policy;
} Agent;

double compute_reward(int state, int action) {
    return -sqrt(pow(state - action, 2));
}

int transition(int state, int action, int num_states) {
    return (state + action) % num_states;
}

int is_done(int state) {
    return state == 0;
}

void init_environment(Environment *env, int num_states, int num_actions) {
    env->num_states = num_states;
    env->num_actions = num_actions;
}

void init_agent(Agent *agent, int num_actions) {
    agent->num_actions = num_actions;
    agent->policy = (double *)malloc(num_actions * sizeof(double));
    for (int i = 0; i < num_actions; i++) {
        agent->policy[i] = 1.0 / num_actions;
    }
}

int select_action(Agent *agent) {
    double r = (double)rand() / RAND_MAX;
    double cumulative_probability = 0.0;
    for (int i = 0; i < agent->num_actions; i++) {
        cumulative_probability += agent->policy[i];
        if (r < cumulative_probability) {
            return i;
        }
    }
    return agent->num_actions - 1; // Fallback, should never reach here
}

void update_policy(Agent *agent, int state, int action, double reward) {
    double mean_policy = 0.0;
    for (int i = 0; i < agent->num_actions; i++) {
        mean_policy += agent->policy[i];
    }
    agent->policy[action] = agent->policy[action] + 0.1 * (reward - mean_policy / agent->num_actions);
}

void free_agent(Agent *agent) {
    free(agent->policy);
}

int main() {
    int num_states = 10;
    int num_actions = 5;
    int max_steps = 100;
    double gamma = 0.99;
    Environment env;
    Agent agent;
    int state = rand() % num_states;

    init_environment(&env, num_states, num_actions);
    init_agent(&agent, num_actions);

    for (int step = 0; step < max_steps; step++) {
        int action = select_action(&agent);
        int next_state = transition(state, action, env.num_states);
        double reward = compute_reward(state, action);
        int done = is_done(next_state);
        update_policy(&agent, state, action, reward);
        state = next_state;
        if (done) {
            break;
        }
    }

    free_agent(&agent);
    return 0;
}