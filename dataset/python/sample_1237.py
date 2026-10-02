def decay_reward(reward, decay_rate, steps):
    for _ in range(steps):
        reward *= decay_rate
    return reward
if __name__ == '__main__':
    decay_reward(10, 0.9, 10)