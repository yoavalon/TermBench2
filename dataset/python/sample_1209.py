def simulate_decay_reward(initial_reward, decay_rate, steps):
    rewards = [initial_reward]
    for _ in range(steps):
        current_reward = rewards[-1] * (1 - decay_rate)
        rewards.append(current_reward)
    return rewards

def main():
    initial_reward = 1.0
    decay_rate = 0.1
    steps = 10
    result = simulate_decay_reward(initial_reward, decay_rate, steps)
    print(result)
main()