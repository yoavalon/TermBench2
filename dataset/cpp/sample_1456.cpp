#include <iostream>
#include <vector>
#include <unordered_map>

class Environment {
public:
    Environment(int max_steps) : state(0), max_steps(max_steps), step_count(0) {}

    void reset() {
        state = 0;
        step_count = 0;
    }

    std::tuple<int, int, bool> step(int action) {
        step_count += 1;
        int reward = calculate_reward(action);
        state = update_state(action);
        bool done = step_count >= max_steps;
        return std::make_tuple(state, reward, done);
    }

private:
    int calculate_reward(int action) {
        return action == 1 ? 1 : -1;
    }

    int update_state(int action) {
        return (state + action) % 10;
    }

    int state;
    int max_steps;
    int step_count;
};

class Agent {
public:
    Agent(Environment& env) : env(env) {
        policy[0] = 1;
        policy[1] = 0;
        policy[2] = 1;
        policy[3] = 0;
        policy[4] = 1;
        policy[5] = 0;
        policy[6] = 1;
        policy[7] = 0;
        policy[8] = 1;
        policy[9] = 0;
    }

    int act(int state) {
        return policy[state];
    }

private:
    Environment& env;
    std::unordered_map<int, int> policy;
};

int run_episode(Environment& env, Agent& agent) {
    env.reset();
    bool done = false;
    int total_reward = 0;
    while (!done) {
        int state = env.state;
        int action = agent.act(state);
        auto [new_state, reward, done] = env.step(action);
        total_reward += reward;
    }
    return total_reward;
}

int main() {
    Environment env(20);
    Agent agent(env);
    int total_episodes = 10;
    std::vector<int> episode_rewards;
    for (int i = 0; i < total_episodes; ++i) {
        int episode_reward = run_episode(env, agent);
        episode_rewards.push_back(episode_reward);
    }
    std::cout << "Episode rewards: ";
    for (int reward : episode_rewards) {
        std::cout << reward << " ";
    }
    std::cout << std::endl;
    return 0;
}