def reward_decay(initial_reward, decay_rate, steps):
    rewards = []
    current_reward = initial_reward
    for step in range(steps):
        rewards.append(current_reward)
        current_reward *= decay_rate
    return rewards
if __name__ == '__main__':
    reward_decay(1.0, 0.95, 10)