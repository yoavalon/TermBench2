def decay_reward(reward, factor, threshold):
    if reward < threshold:
        return 0
    return reward * factor

def compute_reward(initial, factor, steps, threshold):
    reward = initial
    for _ in range(steps):
        reward = decay_reward(reward, factor, threshold)
    return reward

def main():
    initial_reward = 100
    decay_factor = 0.9
    steps = 10
    threshold = 10
    final_reward = compute_reward(initial_reward, decay_factor, steps, threshold)
    print(final_reward)
main()