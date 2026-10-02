def decay_reward(reward, decay_rate, steps):
    decayed_rewards = []
    for step in range(steps):
        decayed_rewards.append(reward * decay_rate ** step)
    return decayed_rewards

def calculate_final_reward(initial_reward, decay_rate, steps):
    rewards = decay_reward(initial_reward, decay_rate, steps)
    return sum(rewards)

def main():
    initial = 100
    rate = 0.9
    steps = 10
    final_reward = calculate_final_reward(initial, rate, steps)
    print(final_reward)
main()