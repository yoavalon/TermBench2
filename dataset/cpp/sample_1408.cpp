#include <iostream>
#include <vector>
#include <cmath>

class RewardDecay {
public:
    RewardDecay(double initial_reward, double decay_rate) : current_reward(initial_reward), decay_rate(decay_rate) {}

    void update_reward() {
        current_reward *= 1 - decay_rate;
    }

    double get_current_reward() const {
        return current_reward;
    }

private:
    double current_reward;
    double decay_rate;
};

class Agent {
public:
    Agent(RewardDecay& reward_decay) : reward_decay(reward_decay), action_count(0) {}

    void take_action() {
        action_count += 1;
        reward_decay.update_reward();
    }

    double get_reward() const {
        return reward_decay.get_current_reward();
    }

private:
    RewardDecay& reward_decay;
    int action_count;
};

std::vector<double> simulate_environment(Agent& agent, int max_actions) {
    std::vector<double> rewards;
    for (int i = 0; i < max_actions; ++i) {
        agent.take_action();
        rewards.push_back(agent.get_reward());
    }
    return rewards;
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.01;
    int max_actions = 1000;
    RewardDecay reward_decay(initial_reward, decay_rate);
    Agent agent(reward_decay);
    std::vector<double> rewards = simulate_environment(agent, max_actions);
    for (double reward : rewards) {
        std::cout << reward << " ";
    }
    std::cout << std::endl;
    return 0;
}