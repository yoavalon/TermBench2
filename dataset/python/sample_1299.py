def decay_reward(initial_value, decay_rate, steps):
    current_value = initial_value
    for _ in range(steps):
        current_value *= decay_rate
    return current_value
if __name__ == '__main__':
    decay_reward(100, 0.9, 10)