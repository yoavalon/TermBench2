def calculate_discounted_rewards(rewards, decay_rate, steps):
    discounted_rewards = [rewards[i] * decay_rate ** i for i in range(steps)]
    return discounted_rewards

def main():
    rewards = [100, 90, 80, 70, 60]
    decay_rate = 0.9
    steps = 5
    result = calculate_discounted_rewards(rewards, decay_rate, steps)
    print(result)
main()