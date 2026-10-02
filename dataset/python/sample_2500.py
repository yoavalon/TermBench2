def simulate_decay(steps, decay_rate):
    reward = 1.0
    rewards = []
    for _ in range(steps):
        rewards.append(reward)
        reward *= decay_rate
    return rewards

def main():
    print(simulate_decay(10, 0.9))
main()