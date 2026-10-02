def reward_decay():
    reward = 1.0
    decay_rate = 0.9
    iterations = 10
    for _ in range(iterations):
        reward *= decay_rate
    return reward
reward_decay()