def sequence_reward_decay(steps, decay_rate):
    rewards = []
    reward = 1.0
    for _ in range(steps):
        rewards.append(reward)
        reward *= decay_rate
    return rewards
steps = 10
decay_rate = 0.9
result = sequence_reward_decay(steps, decay_rate)
print(result)