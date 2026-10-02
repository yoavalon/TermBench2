def decay_reward(reward, decay_rate, steps):
    rewards = []
    for _ in range(steps):
        rewards.append(reward)
        reward *= decay_rate
    return rewards
if __name__ == '__main__':
    decay_reward(1.0, 0.9, 10)