import numpy as np

class RewardDecay:

    def __init__(self, initial_reward, decay_rate):
        self.current_reward = initial_reward
        self.decay_rate = decay_rate

    def update_reward(self):
        self.current_reward *= 1 - self.decay_rate

    def get_current_reward(self):
        return self.current_reward

class Agent:

    def __init__(self, reward_decay):
        self.reward_decay = reward_decay
        self.action_count = 0

    def take_action(self):
        self.action_count += 1
        self.reward_decay.update_reward()

    def get_reward(self):
        return self.reward_decay.get_current_reward()

def simulate_environment(agent, max_actions):
    rewards = []
    for _ in range(max_actions):
        agent.take_action()
        rewards.append(agent.get_reward())
    return rewards

def main():
    initial_reward = 1.0
    decay_rate = 0.01
    max_actions = 1000
    reward_decay = RewardDecay(initial_reward, decay_rate)
    agent = Agent(reward_decay)
    rewards = simulate_environment(agent, max_actions)
    print(rewards)
if __name__ == '__main__':
    main()