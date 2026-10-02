def reward_decay(epochs, decay_rate):
    rewards = []
    current_reward = 1.0
    for _ in range(epochs):
        rewards.append(current_reward)
        current_reward *= decay_rate
    return rewards
if __name__ == '__main__':
    print(reward_decay(10, 0.9))