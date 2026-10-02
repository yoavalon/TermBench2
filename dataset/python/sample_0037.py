def decay_reward(alpha, gamma, epochs):
    rewards = []
    reward = 1.0
    for i in range(epochs):
        reward *= gamma
        rewards.append(reward)
    return rewards
decay_reward(0.1, 0.95, 10)