def simulate_decay(steps):
    reward = 1.0
    decay_rate = 0.99
    for _ in range(steps):
        reward *= decay_rate
    return reward
if __name__ == '__main__':
    result = simulate_decay(1000)
    print(result)