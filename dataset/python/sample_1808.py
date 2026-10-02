import random

def simulate_reward_decay(steps, decay_rate):
    rewards = [random.uniform(0, 1)]
    for _ in range(steps - 1):
        rewards.append(rewards[-1] * decay_rate)
    return rewards

def main():
    steps = 10
    decay_rate = 0.9
    result = simulate_reward_decay(steps, decay_rate)
    print(result)
main()